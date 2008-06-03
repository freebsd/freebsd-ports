--- src/settings.cpp.orig	2008-01-04 18:25:54.000000000 +0200
+++ src/settings.cpp		2008-04-24 00:55:06.000000000 +0300
@@ -8,15 +8,12 @@
 
 #include <unistd.h>
 #include <sys/ioctl.h>
-#include <net/if.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
+#include <net/if.h>
 #include <sys/types.h>
 #include <arpa/inet.h>
-
-#ifdef FREEBSD
 #include <net/route.h>
-#include <netinet/in.h>
-#endif
 
 #endif
 
@@ -279,7 +276,7 @@
 #if defined ( WIN32 )    
     def_playcmd = "";
 #else
-    def_playcmd = "/usr/bin/aplay";
+    def_playcmd = "/usr/local/bin/play";
 #endif
     def_snd[Sound::Chatline] = datapath + "snd/chatline.wav";
     def_snd[Sound::Beep] = datapath + "snd/beep.wav";
