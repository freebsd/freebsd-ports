--- ./kpopup/misc.h.orig	Sun Aug 26 17:44:03 2001
+++ ./kpopup/misc.h	Mon May  5 09:47:04 2003
@@ -20,7 +20,7 @@
 #include "kpopup.h"
 
 #undef DEBUG
-#define SMBPATH "/usr/bin" //Path of smbclient
+#define SMBPATH "%%LOCALBASE%%/bin" //Path of smbclient
 #define TMPPOPUPFILE "/tmp/kpopup-message"
 #define SETSIG(sig, fun, fla)	sa.sa_handler = fun; \
     sa.sa_flags = fla; \
