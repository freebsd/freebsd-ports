--- readconfig.h.orig	Wed Feb 13 06:54:06 2002
+++ readconfig.h	Tue Sep 27 19:33:19 2005
@@ -14,7 +14,7 @@
 #endif
 
 #if withPGSQL
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 #endif
 
 #include <pcap.h> 
