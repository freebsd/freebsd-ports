--- tools/libglibcodegen.py.orig	2014-05-07 14:28:02 UTC
+++ tools/libglibcodegen.py
@@ -23,7 +23,6 @@ please make any changes there.
 
 from libtpcodegen import NS_TP, \
                          Signature, \
-                         cmp_by_name, \
                          escape_as_identifier, \
                          get_by_path, \
                          get_descendant_text, \
@@ -154,7 +153,7 @@ def type_to_gtype(s):
         return ("GHashTable *", "DBUS_TYPE_G_STRING_STRING_HASHTABLE", "BOXED", False)
     elif s[:2] == 'a{':  #some arbitrary hash tables
         if s[2] not in ('y', 'b', 'n', 'q', 'i', 'u', 's', 'o', 'g'):
-            raise Exception, "can't index a hashtable off non-basic type " + s
+            raise Exception("can't index a hashtable off non-basic type " + s)
         first = type_to_gtype(s[2])
         second = type_to_gtype(s[3:-1])
         return ("GHashTable *", "(dbus_g_type_get_map (\"GHashTable\", " + first[1] + ", " + second[1] + "))", "BOXED", False)
@@ -169,4 +168,4 @@ def type_to_gtype(s):
         return ("GValueArray *", gtype, "BOXED", True)
 
     # we just don't know ..
-    raise Exception, "don't know the GType for " + s
+    raise Exception("don't know the GType for " + s)
