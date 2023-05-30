--- src/rootcheck/os_string.c.orig	2023-05-12 12:30:40 UTC
+++ src/rootcheck/os_string.c
@@ -42,6 +42,9 @@
 #include <locale.h>
 #include <unistd.h>
 #include <netinet/in.h>
+#ifdef __FreeBSD__
+#define __LDPGSZ         4096
+#endif
 
 #ifdef SOLARIS
 #include <sys/exechdr.h>
