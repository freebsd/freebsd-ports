--- src/nxt_js.c.orig	2023-05-10 16:22:28 UTC
+++ src/nxt_js.c
@@ -386,11 +386,11 @@ nxt_js_call(nxt_task_t *task, nxt_js_conf_t *jcf, nxt_
     nxt_js_t *js, nxt_str_t *str, void *ctx)
 {
     njs_vm_t            *vm;
-    njs_int_t           rc, ret;
+    njs_int_t           ret;
     njs_str_t           res;
-    njs_value_t         *array, *value;
+    njs_value_t         *value;
     njs_function_t      *func;
-    njs_opaque_value_t  opaque_value, arguments[6];
+    njs_opaque_value_t  retval, opaque_value, arguments[6];
 
     static const njs_str_t  uri_str = njs_str("uri");
     static const njs_str_t  host_str = njs_str("host");
@@ -407,15 +407,13 @@ nxt_js_call(nxt_task_t *task, nxt_js_conf_t *jcf, nxt_
             return NXT_ERROR;
         }
 
-        ret = njs_vm_start(vm);
+        ret = njs_vm_start(vm, njs_value_arg(&retval));
         if (ret != NJS_OK) {
             return NXT_ERROR;
         }
 
-        array = njs_vm_retval(vm);
-
         cache->vm = vm;
-        cache->array = *array;
+        cache->array = *njs_value_arg(&retval);
     }
 
     value = njs_vm_array_prop(vm, &cache->array, js->index, &opaque_value);
@@ -463,18 +461,20 @@ nxt_js_call(nxt_task_t *task, nxt_js_conf_t *jcf, nxt_
         return NXT_ERROR;
     }
 
-    ret = njs_vm_call(vm, func, njs_value_arg(&arguments), 6);
+    ret = njs_vm_invoke(vm, func, njs_value_arg(&arguments), 6,
+                        njs_value_arg(&retval));
 
-    rc = njs_vm_retval_string(vm, &res);
-    if (rc != NJS_OK) {
-        return NXT_ERROR;
-    }
-
     if (ret != NJS_OK) {
-        nxt_alert(task, "js exception: %V", &res);
+        ret = njs_vm_exception_string(vm, &res);
+        if (ret == NJS_OK) {
+            nxt_alert(task, "js exception: %V", &res);
+        }
+
         return NXT_ERROR;
     }
 
+    ret = njs_vm_value_string(vm, &res, njs_value_arg(&retval));
+
     str->length = res.length;
     str->start = res.start;
 
@@ -498,7 +498,7 @@ nxt_js_error(njs_vm_t *vm, u_char *error)
     njs_str_t  res;
     nxt_str_t  err;
 
-    ret = njs_vm_retval_string(vm, &res);
+    ret = njs_vm_exception_string(vm, &res);
     if (nxt_slow_path(ret != NJS_OK)) {
         return NXT_ERROR;
     }
