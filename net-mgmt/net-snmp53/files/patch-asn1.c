--- snmplib/asn1.c.orig	Tue Jan 25 10:09:35 2005
+++ snmplib/asn1.c	Tue Jan 25 10:09:55 2005
@@ -181,6 +181,9 @@
 #include <in.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
