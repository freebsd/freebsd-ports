--- unix.c.orig	Sat Sep 23 22:34:14 2006
+++ unix.c	Sat Sep 23 22:34:51 2006
@@ -71,7 +71,7 @@
     char buffer [2048];
     int errnum;
 
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
     gethostbyname_r (name, & hostData, buffer, sizeof (buffer), & hostEntry, & errnum);
 #else
     hostEntry = gethostbyname_r (name, & hostData, buffer, sizeof (buffer), & errnum);
@@ -101,7 +101,7 @@
 
     in.s_addr = address -> host;
 
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
     gethostbyaddr_r ((char *) & in, sizeof (struct in_addr), AF_INET, & hostData, buffer, sizeof (buffer), & hostEntry, & errnum);
 #else
     hostEntry = gethostbyaddr_r ((char *) & in, sizeof (struct in_addr), AF_INET, & hostData, buffer, sizeof (buffer), & errnum);
