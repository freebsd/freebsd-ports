--- epan/crypt/airpdcap_interop.h.orig	Thu Feb 15 01:26:42 2007
+++ epan/crypt/airpdcap_interop.h	Thu Feb 15 01:27:00 2007
@@ -85,9 +85,9 @@ typedef	gchar	CHAR;
 typedef guchar	UCHAR;
 #endif
 
-#ifndef	size_t
+/*#ifndef	size_t
 typedef	gsize	size_t;
-#endif
+#endif*/
 
 #ifdef WIN32
 #include <winsock2.h>  /* ntohs() */
