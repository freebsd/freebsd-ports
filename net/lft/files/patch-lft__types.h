--- lft_types.h.orig	2016-05-02 14:31:54 UTC
+++ lft_types.h
@@ -101,7 +101,7 @@ typedef signed long n_time;
 #if !defined(DARWIN) && !defined(NETBSD)
 #define HAVE_SNPRINTF
 #define HAVE_VSNPRINTF
-#if !defined(OPENBSD)
+#if !defined(OPENBSD) && !defined(__FreeBSD__)
 #include <pcap-int.h>
 #endif
 #endif
