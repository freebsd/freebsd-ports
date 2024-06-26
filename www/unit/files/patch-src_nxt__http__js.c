--- src/nxt_http_js.c.orig	2024-06-26 22:04:35 UTC
+++ src/nxt_http_js.c
@@ -120,7 +120,7 @@ nxt_http_js_ext_uri(njs_vm_t *vm, njs_object_prop_t *p
         return NJS_DECLINED;
     }
 
-    return njs_vm_value_string_set(vm, retval, r->path->start, r->path->length);
+    return njs_vm_value_string_create(vm, retval, r->path->start, r->path->length);
 }
 
 
@@ -136,7 +136,7 @@ nxt_http_js_ext_host(njs_vm_t *vm, njs_object_prop_t *
         return NJS_DECLINED;
     }
 
-    return njs_vm_value_string_set(vm, retval, r->host.start, r->host.length);
+    return njs_vm_value_string_create(vm, retval, r->host.start, r->host.length);
 }
 
 
@@ -152,7 +152,7 @@ nxt_http_js_ext_remote_addr(njs_vm_t *vm, njs_object_p
         return NJS_DECLINED;
     }
 
-    return njs_vm_value_string_set(vm, retval,
+    return njs_vm_value_string_create(vm, retval,
                                    nxt_sockaddr_address(r->remote),
                                    r->remote->address_length);
 }
@@ -214,7 +214,7 @@ nxt_http_js_ext_get_header(njs_vm_t *vm, njs_object_pr
         if (key.length == f->name_length
             && memcmp(key.start, f->name, f->name_length) == 0)
         {
-            return njs_vm_value_string_set(vm, retval, f->value,
+            return njs_vm_value_string_create(vm, retval, f->value,
                                            f->value_length);
         }
 
@@ -250,7 +250,7 @@ nxt_http_js_ext_keys_header(njs_vm_t *vm, njs_value_t 
             return NJS_ERROR;
         }
 
-        rc = njs_vm_value_string_set(vm, value, f->name, f->name_length);
+        rc = njs_vm_value_string_create(vm, value, f->name, f->name_length);
         if (rc != NJS_OK) {
             return NJS_ERROR;
         }
@@ -296,7 +296,7 @@ nxt_http_js_ext_get_cookie(njs_vm_t *vm, njs_object_pr
         if (key.length == nv->name_length
             && memcmp(key.start, nv->name, nv->name_length) == 0)
         {
-            return njs_vm_value_string_set(vm, retval, nv->value,
+            return njs_vm_value_string_create(vm, retval, nv->value,
                                            nv->value_length);
         }
     }
@@ -340,7 +340,7 @@ nxt_http_js_ext_keys_cookie(njs_vm_t *vm, njs_value_t 
             return NJS_ERROR;
         }
 
-        rc = njs_vm_value_string_set(vm, value, nv->name, nv->name_length);
+        rc = njs_vm_value_string_create(vm, value, nv->name, nv->name_length);
         if (rc != NJS_OK) {
             return NJS_ERROR;
         }
@@ -380,7 +380,7 @@ nxt_http_js_ext_get_var(njs_vm_t *vm, njs_object_prop_
     vv = nxt_var_get(&r->task, rtcf->tstr_state, &r->tstr_cache.var, &name, r);
 
     if (vv != NULL) {
-        return njs_vm_value_string_set(vm, retval, vv->start, vv->length);
+        return njs_vm_value_string_create(vm, retval, vv->start, vv->length);
     }
 
     njs_value_undefined_set(retval);
