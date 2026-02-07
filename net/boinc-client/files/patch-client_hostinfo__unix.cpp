--- client/hostinfo_unix.cpp.orig	2022-07-27 21:28:09 UTC
+++ client/hostinfo_unix.cpp
@@ -177,7 +177,7 @@ extern "C" {
 // The following is intended to be true both on Linux
 // and Debian GNU/kFreeBSD (see trac #521)
 //
-#if (defined(__linux__) || defined(__GNU__) || defined(__GLIBC__))  && !defined(__HAIKU__)
+#if (defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) || defined(__freebsd__))  && !defined(__HAIKU__)
 #define LINUX_LIKE_SYSTEM 1
 #endif
 
