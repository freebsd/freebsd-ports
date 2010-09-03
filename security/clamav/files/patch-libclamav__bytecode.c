--- libclamav/bytecode.c
+++ libclamav/bytecode.c
@@ -2107,6 +2107,7 @@ static int run_selfcheck(struct cli_all_bc *bcs)
     cli_bytecode_context_setfuncid(ctx, bc, 0);
 
     cli_dbgmsg("bytecode self test running\n");
+    ctx->bytecode_timeout = 0;
     rc = cli_bytecode_run(bcs, bc, ctx);
     cli_bytecode_context_destroy(ctx);
     if (rc != CL_SUCCESS) {
diff --git a/libclamav/c++/bytecode2llvm.cpp b/libclamav/c++/bytecode2llvm.cpp
index 0f1de1a..f0b12fe 100644
