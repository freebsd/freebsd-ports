--- gatling.c.orig	Mon Jan 31 17:14:45 2005
+++ gatling.c	Sun Feb 20 17:02:12 2005
@@ -3088,7 +3088,7 @@ void forkslave(int fd,buffer* in) {
     }
   }
 error:
-  write(fd,&code,4);
+  if (write(fd,&code,4)!=4) exit(0);
   code=strlen(msg);
   write(fd,&code,4);
   {
