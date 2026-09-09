--- src/njs_value.c.orig	2026-08-20 18:32:42 UTC
+++ src/njs_value.c
@@ -1075,9 +1075,7 @@ njs_value_property(njs_vm_t *vm, njs_value_t *value, u
             return NJS_OK;
         }
 
-        if (njs_slow_path(!(njs_is_object(value)
-                            && njs_object(value)->fast_array)))
-        {
+        if (njs_slow_path(!njs_is_fast_array(value))) {
             goto slow_path;
         }
 
@@ -1194,9 +1192,7 @@ njs_value_property_set(njs_vm_t *vm, njs_value_t *valu
             return NJS_OK;
         }
 
-        if (njs_slow_path(!(njs_is_object(value)
-                            && njs_object(value)->fast_array)))
-        {
+        if (njs_slow_path(!njs_is_fast_array(value))) {
             goto slow_path;
         }
 
