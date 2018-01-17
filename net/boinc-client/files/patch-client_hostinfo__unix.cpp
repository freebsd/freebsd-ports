--- client/hostinfo_unix.cpp.orig	2018-01-14 16:39:30 UTC
+++ client/hostinfo_unix.cpp
@@ -164,7 +164,9 @@ extern "C" {
 // The following is intended to be true both on Linux
 // and Debian GNU/kFreeBSD (see trac #521)
 //
-#define LINUX_LIKE_SYSTEM (defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(__HAIKU__)
+#if (defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) || defined (__freebsd__)) && !defined(__HAIKU__) 
+#define LINUX_LIKE_SYSTEM 1
+#endif
 
 // Returns the offset between LOCAL STANDARD TIME and UTC.
 // LOCAL_STANDARD_TIME = UTC_TIME + get_timezone().
