--- generic/tclXdup.c.orig	2014-07-30 16:44:06.000000000 +0200
+++ generic/tclXdup.c	2014-07-30 16:45:30.000000000 +0200
@@ -128,7 +128,7 @@
     char       *targetChannelId;
 {
     Tcl_Channel srcChannel, newChannel = NULL;
-    Tcl_ChannelType *channelType;
+    const Tcl_ChannelType *channelType;
     int mode;
 
     srcChannel = Tcl_GetChannel (interp, srcChannelId, &mode);
