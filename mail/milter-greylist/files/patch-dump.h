--- dump.h.orig	Tue May 25 11:39:49 2004
+++ dump.h	Tue Jun  8 10:24:13 2004
@@ -46,7 +46,7 @@
 #include <arpa/inet.h>
 
 #ifndef DUMPFILE
-#define DUMPFILE "/var/milter-greylist/greylist.db"
+#define DUMPFILE "/var/db/milter-greylist/greylist.db"
 #endif
 
 #ifndef DUMPFREQ
