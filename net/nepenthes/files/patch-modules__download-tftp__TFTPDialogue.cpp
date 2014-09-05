--- modules/download-tftp/TFTPDialogue.cpp.orig
+++ modules/download-tftp/TFTPDialogue.cpp
@@ -27,7 +27,10 @@
 
  /* $Id: TFTPDialogue.cpp 550 2006-05-04 10:25:35Z common $ */
 
+#include <cstdlib>
+#include <cstring>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/tftp.h>
 #include <netinet/in.h>
 
