
This bug is due to the fact, applications are restarted before extension
defaults are loaded.

To reproduce, choose any preference and set the values like:
system default:
  pref("prefkey",systemvalue);
extension default:
  pref("prefkey", extensiondefault);
user pref:
  user_pref("prefkey", systemvalue);

Next, trigger application behaviour similar to upgrade by removing compreg.dat
from profile and start the application.

Result:
User sees extensiondefault after upgrade, because the user_pref has been
eliminated ... which is definitly not what the user expects because he explicitly
had *systemvalue* set before the upgrade.

Evaluation:
The bug happens because restart is performed *before* extension defaults have been
loaded and the prefapi.cpp always eliminate user preference if the user preference
is equal to the actual default (which happens to be extensiondefault normally  - so
no reset, but is systemvalue during restart).

Fix:
1. savePrefs should not try to be smart ... this patch removes the heuristic that guesses
whether a setting can be eliminated or not; it should be sufficient to only eliminate
prefs in hashPrefs.

2. This patch prevents hashPrefs from eliminating the user pref in case we are in
*startup* ... unfortunately no such state info exists, which lets us guess that
we are in startup for the previously not dealt case: !set_default && 
!pref_ValueChanged(pref->defaultPref, value, type) && !PREF_HAS_USER_VALUE(pref).

If is the case we explicitly remember that this setting is a user-pref ...
even though it might be temporarily equal to the default pref.

---
 modules/libpref/src/prefapi.cpp |   20 ++++++++++++++------
 1 file changed, 14 insertions(+), 6 deletions(-)

Index: modules/libpref/src/prefapi.cpp
===================================================================
--- modules/libpref/src/prefapi.cpp
+++ modules/libpref/src/prefapi.cpp
@@ -324,23 +324,20 @@
     if (!pref)
         return PL_DHASH_NEXT;
 
     nsCAutoString prefValue;
 
     // where we're getting our pref from
     PrefValue* sourcePref;
 
-    if (PREF_HAS_USER_VALUE(pref) &&
-        pref_ValueChanged(pref->defaultPref,
-                          pref->userPref,
-                          (PrefType) PREF_TYPE(pref)))
-        sourcePref = &pref->userPref;
-    else if (PREF_IS_LOCKED(pref))
+    if (PREF_IS_LOCKED(pref))
         sourcePref = &pref->defaultPref;
+    else if (PREF_HAS_USER_VALUE(pref))
+        sourcePref = &pref->userPref;
     else
         // do not save default prefs that haven't changed
         return PL_DHASH_NEXT;
 
     // strings are in quotes!
     if (pref->flags & PREF_STRING) {
         prefValue = '\"';
         str_escape(sourcePref->stringVal, prefValue);
@@ -742,16 +739,27 @@
            Otherwise, set the user value only if it has changed */
         if ( !pref_ValueChanged(pref->defaultPref, value, type) )
         {
             if (PREF_HAS_USER_VALUE(pref))
             {
                 pref->flags &= ~PREF_USERSET;
                 if (!PREF_IS_LOCKED(pref))
                     valueChanged = PR_TRUE;
+            } else {
+                // this is tricky: we have !set_default ...
+                // thus we are setting a user pref; however the user
+                // pref set is same as *current default*; this normally
+                // means to un-set ... however since we have
+                // !PREF_HAS_USER_VALUE(pref) this can only be during
+                // startup
+                pref_SetValue(&pref->userPref, value, type);
+                pref->flags |= PREF_USERSET;
+                if (!PREF_IS_LOCKED(pref))
+                    valueChanged = PR_TRUE;
             }
         }
         else if ( !PREF_HAS_USER_VALUE(pref) ||
                    pref_ValueChanged(pref->userPref, value, type) )
         {
             pref_SetValue(&pref->userPref, value, type);
             pref->flags |= PREF_USERSET;
             if (!PREF_IS_LOCKED(pref))
