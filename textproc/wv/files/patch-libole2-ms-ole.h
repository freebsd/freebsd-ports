--- libole2/ms-ole.h.orig	Thu Nov 28 16:26:40 2002
+++ libole2/ms-ole.h	Thu Nov 28 16:27:24 2002
@@ -33,6 +33,7 @@
 	typedef long caddr_t;
 #endif
 
+#include <sys/types.h>
 #include <glib.h>
 
 typedef enum {
