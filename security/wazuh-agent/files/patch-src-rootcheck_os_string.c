--- src/rootcheck/os_string.c	2022-10-06 08:35:58.000000000 -0500
+++ src/rootcheck/os_string.c	2022-10-30 14:31:56.614900000 -0500
@@ -42,6 +42,9 @@
 #include <locale.h>
 #include <unistd.h>
 #include <netinet/in.h>
+#ifdef __FreeBSD__
+#define __LDPGSZ        4096
+#endif
 
 #ifdef SOLARIS
 #include <sys/exechdr.h>
