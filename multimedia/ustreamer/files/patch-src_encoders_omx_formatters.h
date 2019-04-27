--- src/encoders/omx/formatters.h.orig	2019-04-27 06:14:24 UTC
+++ src/encoders/omx/formatters.h
@@ -34,12 +34,21 @@
 #include "../../tools.h"
 
 
+#if defined(__FreeBSD__)
+#define LOG_OMX_ERROR(_error, _msg, ...) { \
+		LOGGING_LOCK; \
+		printf("-- ERROR [%.03Lf tid=%ld] -- " _msg ": %s\n", get_now_monotonic(), \
+			pthread_getthreadid_np(), ##__VA_ARGS__, omx_error_to_string(_error)); \
+		LOGGING_UNLOCK; \
+	}
+#else
 #define LOG_OMX_ERROR(_error, _msg, ...) { \
 		LOGGING_LOCK; \
 		printf("-- ERROR [%.03Lf tid=%ld] -- " _msg ": %s\n", get_now_monotonic(), \
 			syscall(SYS_gettid), ##__VA_ARGS__, omx_error_to_string(_error)); \
 		LOGGING_UNLOCK; \
 	}
+#endif
 
 
 const char *omx_error_to_string(OMX_ERRORTYPE error);
