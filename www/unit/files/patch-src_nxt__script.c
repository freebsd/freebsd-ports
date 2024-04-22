--- src/nxt_script.c.orig	2023-10-17 14:15:38 UTC
+++ src/nxt_script.c
@@ -37,14 +37,6 @@ static void nxt_script_buf_completion(nxt_task_t *task
 static nxt_lvlhsh_t  nxt_script_info;
 
 
-static njs_vm_ops_t  nxt_js_ops = {
-    NULL,
-    NULL,
-    nxt_js_module_loader,
-    NULL,
-};
-
-
 nxt_script_t *
 nxt_script_new(nxt_task_t *task, nxt_str_t *name, u_char *data, size_t size,
     u_char *error)
@@ -62,8 +54,6 @@ nxt_script_new(nxt_task_t *task, nxt_str_t *name, u_ch
 
     opts.file.start = (u_char *) "default";
     opts.file.length = 7;
-
-    opts.ops = &nxt_js_ops;
 
     vm = njs_vm_create(&opts);
     if (nxt_slow_path(vm == NULL)) {
