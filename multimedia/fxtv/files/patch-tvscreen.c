--- tvscreen.c.ORI	Sun May 21 15:49:47 2000
+++ tvscreen.c	Wed Jun  7 10:19:30 2006
@@ -480,6 +480,9 @@
     dga_avail = FALSE;
 
 #ifdef HAVE_XFREE86
+    if ( App_res.disable_direct_v )
+        SUPRINTF(( "Will not init DGA since -disableDirectV was given.\n" ));
+    else
     if ( !XUTILXServerIsLocal( TVDISPLAY ) )
         SUPRINTF(( "XF86DGA not available...X Server isn't local.\n" ));
     else {

