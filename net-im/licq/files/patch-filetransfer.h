--- include/licq/icq/filetransfer.h.orig	2014-06-01 21:16:42.000000000 +0200
+++ include/licq/icq/filetransfer.h	2014-06-06 15:47:07.000000000 +0200
@@ -73,6 +73,7 @@
  * which case the file will be saved as <filename>.<timestamp>
  *-------------------------------------------------------------------------*/
 
+#include <sys/time.h>
 #include <cstring>
 #include <list>
 #include <string>
