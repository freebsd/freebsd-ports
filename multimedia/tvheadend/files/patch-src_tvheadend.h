--- src/tvheadend.h.orig	2024-04-26 17:57:22 UTC
+++ src/tvheadend.h
@@ -340,6 +340,8 @@ void tvh_qsort_r(void *base, size_t nmemb, size_t size
 # define PRItime_t "lld"
 #elif CONFIG_TIME_LD == 1
 # define PRItime_t "ld"
+#elif CONFIG_TIME_D == 1
+# define PRItime_t "d"
 #else
 # error "CONFIG_TIME not properly defined"
 #endif
