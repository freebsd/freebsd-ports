--- plugger-helper.c.orig	Sun Dec  9 22:41:11 2001
+++ plugger-helper.c	Sun Mar 24 23:29:20 2002
@@ -30,6 +30,7 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <errno.h>
+#include <stdlib.h>
 #include <sys/time.h>
 #include <X11/X.h>
 #include <X11/Xos.h>
@@ -355,10 +356,10 @@
 	/* Time to steal the lock! */
 	mode=PropModeReplace;
 	gettimeofday(&tv, 0);
-	INC_TIME(&tv, 0, 10000 + (rand() & 16383));
+	INC_TIME(&tv, 0, 10000 + (random() & 16383));
 	break;
       }
-      my_usleep((rand() & 16383) + 2000); /* 0.18383 seconds */
+      my_usleep((random() & 16383) + 2000); /* 0.18383 seconds */
     }
     
     D("XChangeProperty, mode=%d\n",mode);
@@ -401,6 +402,7 @@
   got_sigwinch=1;
 }
 
+#define LONG_CHARS  12
 
 int main(int argc, char **argv)
 {
@@ -493,30 +495,30 @@
 	loops=MIN(repeats,10);
 	for(e=0;e<loops;e++)
 	{
-	  strcat(foo," ");
-	  strcat(foo,file);
+	  strncat(foo," ", 1);
+	  strncat(foo,file,strlen(file));
 	}
       }else{
-	sprintf(foo,"file=%s",file);
+	snprintf(foo,strlen(file)+1+5,"file=%s",file);
       }
       putenv(foo);
       foo+=strlen(foo)+1;
     }
 
     /* setup environment variable $env */
-    sprintf(foo,"window=%ld",(long)WINDOW);
+    snprintf(foo,LONG_CHARS+7+1,"window=%ld",(long)WINDOW);
     putenv(foo);
     foo+=strlen(foo)+1;
 
     /* setup environment variable $repeat */
-    sprintf(foo,"repeat=%ld",(long)repeats);
+    snprintf(foo,LONG_CHARS+7+1,"repeat=%ld",(long)repeats);
     putenv(foo);
     foo+=strlen(foo)+1;
 
     /* setup environment variable $DISPLAY */
     if(displayname)
     {
-      sprintf(foo,"DISPLAY=%s",displayname);
+      snprintf(foo,strlen(displayname)+1+8,"DISPLAY=%s",displayname);
       D("putenv(%s)\n",foo);
       putenv(foo);
       foo+=strlen(foo)+1;
@@ -526,7 +528,7 @@
     /* setup environment variable $mimetype */
     if(mimetype)
     {
-      sprintf(foo,"mimetype=%s",mimetype);
+      snprintf(foo,strlen(mimetype)+1+9,"mimetype=%s",mimetype);
       D("putenv(%s)\n",foo);
       putenv(foo);
       foo+=strlen(foo)+1;
