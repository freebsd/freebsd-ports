diff -ru ../../work/nat10/includes.h ./includes.h
--- includes.h.orig	Sun Feb 16 19:18:04 1997
+++ includes.h	Sat Jun 14 23:10:49 2003
@@ -466,13 +466,15 @@
 
 
 #ifdef FreeBSD
-#include <strings.h>
+#include <string.h>
 #include <netinet/tcp.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
+#include <dirent.h>
 #define SIGNAL_CAST (void (*)())
-#define USE_DIRECT
 #define REPLACE_INNETGR
+#define HAVE_MEMMOVE
+#define HAVE_BZERO
 #endif 
 
 
@@ -1121,3 +1123,6 @@
 #endif
 
 #endif
+
+char * Get_Hostbyaddr (struct in_addr ip);
+struct ipstr *parse_ip(char *);
