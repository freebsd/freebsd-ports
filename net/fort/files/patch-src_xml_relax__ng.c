--- src/xml/relax_ng.c.orig	2024-06-23 04:09:22 UTC
+++ src/xml/relax_ng.c
@@ -35,8 +35,15 @@ relax_ng_log_warn(void *ctx, const char *msg, ...)
 	VLOG_MSG(warn)
 }
 
+/* Signature changed at libxml2 commit 61034116d0a3c8b295c6137956adc3ae55720. */
+#if LIBXML_VERSION >= 21200
+#define XMLERROR_PARAMTYPE const xmlError *
+#else
+#define XMLERROR_PARAMTYPE xmlErrorPtr
+#endif
+
 static void
-relax_ng_log_str_err(void *userData, xmlErrorPtr error)
+relax_ng_log_str_err(void *userData, XMLERROR_PARAMTYPE error)
 {
 	char *ptr;
 
