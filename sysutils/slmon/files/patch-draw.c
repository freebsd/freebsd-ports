--- draw.c.orig	Tue Oct  1 20:32:27 2002
+++ draw.c	Tue Aug 17 13:40:08 2004
@@ -26,6 +26,7 @@
 #include <glibtop/netload.h>
 
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 
 /*
@@ -314,6 +315,7 @@
 	SLsmg_write_string("SPC,ENTER:  leave help");
 	break;
     default:
+	break;
     }
 }
 
