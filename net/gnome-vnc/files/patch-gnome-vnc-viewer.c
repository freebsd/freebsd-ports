
$FreeBSD$

--- gnome-vnc-viewer.c.orig	Sun Aug 22 15:48:17 2004
+++ gnome-vnc-viewer.c	Sun Aug 22 15:48:33 2004
@@ -343,7 +343,7 @@
       curShared = TRUE; break;
     case -2:
       
-    }
+    break;}
   case POPT_CALLBACK_REASON_PRE:
     if (!strcmp(arg, "8"))
       curDepth = VNC_VIEWER_DEPTH_8BIT;
