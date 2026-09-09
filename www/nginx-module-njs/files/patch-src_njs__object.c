--- src/njs_object.c.orig	2026-08-20 18:32:42 UTC
+++ src/njs_object.c
@@ -1140,7 +1140,7 @@ njs_object_own_enumerate_object(njs_vm_t *vm, const nj
         }
 
         entry = NULL;
-        njs_set_object(&value, (njs_object_t *) object);
+        njs_set_type_object(&value, (njs_object_t *) object, object->type);
 
         for (i = 0; i< items_sorted->length; i++) {
             ret = njs_value_property_val(vm, &value, &items_sorted->start[i],
