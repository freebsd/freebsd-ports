--- src/gp/execinfo_bsd.h.orig	2022-08-10 06:56:53 UTC
+++ src/gp/execinfo_bsd.h
@@ -46,3 +46,5 @@ void    backtrace_symbols_fd(void *const *, int, int);
 #ifdef __cplusplus
 }
 #endif
+
+#endif
