--- subst.c.orig	Sun Sep 22 22:00:53 2002
+++ subst.c	Fri Apr 11 02:07:44 2003
@@ -48,7 +48,7 @@
     char *format=NULL;
     size_t formatlen=0;
     int flags;
-    ssize_t str_start;
+    size_t str_start;
 
     for(i=j=0; s[i]!='\0'; i++){
         if(s[i]!='%'){
