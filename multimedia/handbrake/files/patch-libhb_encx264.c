--- libhb/encx264.c.orig	Sat Aug 26 02:34:47 2006
+++ libhb/encx264.c	Sat Aug 26 02:36:02 2006
@@ -79,7 +79,7 @@
     else
     {
         /* Rate control */
-        param.rc.b_cbr     = 1;
+        param.rc.i_rc_method     = 1;
         param.rc.i_bitrate = job->vbitrate;
         switch( job->pass )
         {
