--- socket++/local.h.orig	Mon Oct 13 14:36:26 2003
+++ socket++/local.h	Mon Oct 13 14:37:03 2003
@@ -89,7 +89,7 @@
 // arpa/in.h does not provide a protype for the following
 extern "C" char* inet_ntoa (in_addr ina);
 
-#if !defined (__linux__)
+#if !(defined (__linux__) || defined(__FreeBSD__))
   extern "C" int gethostname (char* hostname, int len);
 #if !(defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__APPLE__))
   extern char* SYS_SIGLIST [];
