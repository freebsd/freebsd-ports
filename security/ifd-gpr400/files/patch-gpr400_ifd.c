--- gpr400_ifd.c.orig	Wed Aug 22 03:21:43 2001
+++ gpr400_ifd.c	Sun Sep  8 18:10:47 2002
@@ -77,7 +77,7 @@
 	printf("IFDHCreateChannel:\n");
 #endif
     if(gpr_fd < 0){
-        gpr_fd= open("/dev/gpr400", O_RDWR);
+        gpr_fd= open(GPRDEVNAME, O_RDWR);
         if(gpr_fd < 0){
             return IFD_COMMUNICATION_ERROR;
         }
