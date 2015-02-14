--- unix.c.orig	2014-04-24 09:49:05.000000000 +0200
+++ unix.c	2015-02-14 11:32:25.346006823 +0100
@@ -104,7 +104,7 @@
     char buffer [2048];
     int errnum;
 
-#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
     gethostbyname_r (name, & hostData, buffer, sizeof (buffer), & hostEntry, & errnum);
 #else
     hostEntry = gethostbyname_r (name, & hostData, buffer, sizeof (buffer), & errnum);
@@ -162,7 +162,7 @@
 
     in.s_addr = address -> host;
 
-#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
     gethostbyaddr_r ((char *) & in, sizeof (struct in_addr), AF_INET, & hostData, buffer, sizeof (buffer), & hostEntry, & errnum);
 #else
     hostEntry = gethostbyaddr_r ((char *) & in, sizeof (struct in_addr), AF_INET, & hostData, buffer, sizeof (buffer), & errnum);
