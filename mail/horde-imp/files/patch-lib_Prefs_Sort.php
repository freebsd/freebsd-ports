--- lib/Prefs/Sort.php.orig	2020-08-27 19:34:20 UTC
+++ lib/Prefs/Sort.php
@@ -39,9 +39,13 @@ class IMP_Prefs_Sort implements ArrayAccess, IteratorA
     {
         global $prefs;
 
-        $sortpref = @unserialize($prefs->getValue(self::SORTPREF));
-        if (is_array($sortpref)) {
-            $this->_sortpref = $sortpref;
+        $serializedPref = $prefs->getValue(self::SORTPREF);
+        // Only unserialize non-empty strings. Disallow yielding any classes.
+        if (!empty($serializedPref && is_string($serializedPref))) {
+            $sortpref = @unserialize($serializedPref, ['allowed_classes' => false]);
+            if (is_array($sortpref)) {
+                $this->_sortpref = $sortpref;
+            }
         }
     }
 
