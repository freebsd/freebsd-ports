--- src/wasm/nxt_rt_wasmtime.c.orig	2024-11-22 14:57:14.033949000 -0500
+++ src/wasm/nxt_rt_wasmtime.c	2024-11-22 14:56:05.796918000 -0500
@@ -281,7 +281,9 @@
     wasi_config_inherit_stderr(wasi_config);
 
     for (dir = ctx->dirs; dir != NULL && *dir != NULL; dir++) {
-        wasi_config_preopen_dir(wasi_config, *dir, *dir);
+        wasi_config_preopen_dir(wasi_config, *dir, *dir,
+                WASMTIME_WASI_DIR_PERMS_READ|WASMTIME_WASI_DIR_PERMS_WRITE,
+                WASMTIME_WASI_FILE_PERMS_READ|WASMTIME_WASI_FILE_PERMS_WRITE);
     }
 
     error = wasmtime_context_set_wasi(rt_ctx->ctx, wasi_config);
