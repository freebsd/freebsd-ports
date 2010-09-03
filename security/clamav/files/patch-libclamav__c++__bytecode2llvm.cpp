--- libclamav/c++/bytecode2llvm.cpp
+++ libclamav/c++/bytecode2llvm.cpp
@@ -1637,11 +1637,15 @@ int cli_vm_execute_jit(const struct cli_all_bc *bcs, struct cli_bc_ctx *ctx,
 	0
     };
 
-    if ((ret = pthread_create(&thread, NULL, bytecode_watchdog, &w))) {
-	errs() << "Bytecode: failed to create new thread!";
-	errs() << cli_strerror(ret, buf, sizeof(buf));
-	errs() << "\n";
-	return CL_EBYTECODE;
+    if (ctx->bytecode_timeout) {
+	/* only spawn if timeout is set.
+	 * we don't set timeout for selfcheck (see bb #2235) */
+	if ((ret = pthread_create(&thread, NULL, bytecode_watchdog, &w))) {
+	    errs() << "Bytecode: failed to create new thread!";
+	    errs() << cli_strerror(ret, buf, sizeof(buf));
+	    errs() << "\n";
+	    return CL_EBYTECODE;
+	}
     }
 
     ret = bytecode_execute((intptr_t)code, ctx);
@@ -1649,7 +1653,9 @@ int cli_vm_execute_jit(const struct cli_all_bc *bcs, struct cli_bc_ctx *ctx,
     w.finished = 1;
     pthread_cond_signal(&w.cond);
     pthread_mutex_unlock(&w.mutex);
-    pthread_join(thread, NULL);
+    if (ctx->bytecode_timeout) {
+	pthread_join(thread, NULL);
+    }
 
     if (cli_debug_flag) {
 	gettimeofday(&tv1, NULL);
