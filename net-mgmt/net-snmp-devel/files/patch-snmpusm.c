--- snmplib/snmpusm.c.orig	Thu Sep 16 07:57:47 2004
+++ snmplib/snmpusm.c	Tue Jan 25 10:23:02 2005
@@ -54,6 +54,9 @@
 #include <netinet/in.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
@@ -89,6 +92,8 @@
 oid             usmAESPrivProtocol[10] = { 1, 3, 6, 1, 6, 3, 10, 1, 2, 4 };
 /* backwards compat */
 oid             *usmAES128PrivProtocol = usmAESPrivProtocol;
+oid             *usmAES192PrivProtocol = usmAESPrivProtocol;
+oid             *usmAES256PrivProtocol = usmAESPrivProtocol;
 
 static u_int    dummy_etime, dummy_eboot;       /* For ISENGINEKNOWN(). */
 
