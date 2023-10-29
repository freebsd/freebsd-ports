--- src/lib/lttng-ust-dl/ust_dl.h.orig	2022-03-25 15:37:17 UTC
+++ src/lib/lttng-ust-dl/ust_dl.h
@@ -21,6 +21,7 @@ extern "C" {
 
 #define LTTNG_UST_DL_PROVIDER
 #include <lttng/tracepoint.h>
+#include <common/compat/dlfcn.h>
 
 LTTNG_UST_TRACEPOINT_EVENT(lttng_ust_dl, dlopen,
 	LTTNG_UST_TP_ARGS(void *, ip, void *, baddr, const char *, path,
