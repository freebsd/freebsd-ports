--- unix/tclXunixDup.c.orig	2014-07-30 16:57:13.000000000 +0200
+++ unix/tclXunixDup.c	2014-07-30 17:00:42.000000000 +0200
@@ -84,7 +84,7 @@
     char       *targetChannelId;
 {
     ClientData handle;
-    Tcl_ChannelType *channelType;
+    const Tcl_ChannelType *channelType;
     Tcl_Channel newChannel = NULL;
     int srcFileNum, newFileNum = -1;
 
