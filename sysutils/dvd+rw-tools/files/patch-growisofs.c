diff -dur dvd+rw-tools-5.19.4.9.7/growisofs.c dvd+rw-tools-5.19-1.4.9.7/growisofs.c
--- growisofs.c	Sun Apr  4 04:47:51 2004
+++ growisofs.c	Wed Apr 21 15:31:19 2004
@@ -296,7 +296,7 @@
     char *s=strrchr((cmd),'/');				\
     s ? s++ : (s=(cmd));				\
     printf ("* %.*sgrowisofs by <appro@fy.chalmers.se>,"\
-	    " version 5.19,\n",(int)(s-(cmd)),(cmd));	\
+	    " version 5.19-1,\n",(int)(s-(cmd)),(cmd));	\
 } while (0)
 
 #define _LARGEFILE_SOURCE 

