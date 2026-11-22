--- ngx_http_zip_module.h.orig	2026-11-09 01:58:10 UTC
+++ ngx_http_zip_module.h
@@ -3,7 +3,16 @@
 #include <ngx_config.h>
 #include <ngx_core.h>
 #include <ngx_http.h>
+#include <nginx.h>
 #include <time.h>
+
+/* Fallback in case the configure-time feature test did not run:
+ * multi-value headers became linked lists in nginx 1.23.0 */
+#ifndef NGX_ZIP_MULTI_HEADERS_LINKED_LISTS
+#if (nginx_version >= 1023000)
+#define NGX_ZIP_MULTI_HEADERS_LINKED_LISTS 1
+#endif
+#endif
 
 #define NGX_ZIP_MIME_TYPE "application/zip"
 #define ngx_http_zip_current_file(ctx) ctx->pieces[ctx->pieces_i].file
