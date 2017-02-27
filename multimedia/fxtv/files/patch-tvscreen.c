--- tvscreen.c.orig	2000-05-21 13:49:47 UTC
+++ tvscreen.c
@@ -480,6 +480,9 @@ void TVSCREENInit( TV_XSCREEN *s,
     dga_avail = FALSE;
 
 #ifdef HAVE_XFREE86
+    if ( App_res.disable_direct_v )
+        SUPRINTF(( "Will not init DGA since -disableDirectV was given.\n" ));
+    else
     if ( !XUTILXServerIsLocal( TVDISPLAY ) )
         SUPRINTF(( "XF86DGA not available...X Server isn't local.\n" ));
     else {
