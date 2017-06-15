--- liblttng-ust-dl/ust_dl.h.orig	2016-11-29 01:46:24 UTC
+++ liblttng-ust-dl/ust_dl.h
@@ -36,6 +36,7 @@ extern "C" {
 
 #define LTTNG_UST_DL_PROVIDER
 #include <lttng/tracepoint.h>
+#include <lttng/ust-dlfcn.h>
 
 TRACEPOINT_EVENT(lttng_ust_dl, dlopen,
 	TP_ARGS(void *, ip, void *, baddr, const char *, path,
