--- dump.h.orig	Thu May  6 15:54:01 2004
+++ dump.h	Tue May 25 22:48:33 2004
@@ -46,7 +46,7 @@
 #include <arpa/inet.h>
 
 #ifndef DUMPFILE
-#define DUMPFILE "/var/milter-greylist/greylist.db"
+#define DUMPFILE "/var/db/milter-greylist/greylist.db"
 #endif
 
 #define DATELEN 40
