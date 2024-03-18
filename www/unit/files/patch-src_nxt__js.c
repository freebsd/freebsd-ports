--- src/nxt_js.c.orig	2023-10-17 14:15:38 UTC
+++ src/nxt_js.c
@@ -69,14 +69,6 @@ nxt_js_module_loader(njs_vm_t *vm, njs_external_ptr_t 
 }
 
 
-static njs_vm_ops_t  nxt_js_ops = {
-    NULL,
-    NULL,
-    nxt_js_module_loader,
-    NULL,
-};
-
-
 njs_int_t  nxt_js_proto_id;
 
 
@@ -127,6 +119,7 @@ nxt_js_vm_create(nxt_js_conf_t *jcf)
 {
     u_char           *p;
     size_t           size;
+    njs_vm_t         *vm;
     nxt_uint_t       i;
     njs_vm_opt_t     opts;
     nxt_js_module_t  *module, *mod;
@@ -146,7 +139,6 @@ nxt_js_vm_create(nxt_js_conf_t *jcf)
         goto done;
     }
 
-    opts.ops = &nxt_js_ops;
     opts.external = jcf;
 
     size = 0;
@@ -203,7 +195,13 @@ nxt_js_vm_create(nxt_js_conf_t *jcf)
 
 done:
 
-    return njs_vm_create(&opts);
+    vm = njs_vm_create(&opts);
+
+    if (nxt_fast_path(vm != NULL)) {
+        njs_vm_set_module_loader(vm, nxt_js_module_loader, jcf);
+    }
+
+    return vm;
 }
 
 
