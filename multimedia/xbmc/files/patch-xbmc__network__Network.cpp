--- ./xbmc/network/Network.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/network/Network.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -30,6 +30,7 @@
 #include "dialogs/GUIDialogKaiToast.h"
 
 #include <netinet/in.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 
 using namespace std;
