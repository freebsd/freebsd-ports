--- dump.h.orig	Tue Jun  8 16:47:47 2004
+++ dump.h	Sat Jun 12 10:47:56 2004
@@ -46,7 +46,7 @@
 #include <arpa/inet.h>
 
 #ifndef DUMPFILE
-#define DUMPFILE "/var/milter-greylist/greylist.db"
+#define DUMPFILE "/var/db/milter-greylist/greylist.db"
 #endif
 
 #ifndef DUMPFREQ
