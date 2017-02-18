--- include/licq/icq/filetransfer.h.orig	2014-06-01 19:16:42 UTC
+++ include/licq/icq/filetransfer.h
@@ -73,6 +73,7 @@
  * which case the file will be saved as <filename>.<timestamp>
  *-------------------------------------------------------------------------*/
 
+#include <sys/time.h>
 #include <cstring>
 #include <list>
 #include <string>
