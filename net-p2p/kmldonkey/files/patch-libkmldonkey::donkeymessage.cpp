--- libkmldonkey/donkeymessage.cpp.orig	Sun May 11 14:25:25 2003
+++ libkmldonkey/donkeymessage.cpp	Sun May 11 14:25:33 2003
@@ -42,6 +42,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
