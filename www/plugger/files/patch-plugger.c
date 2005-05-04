--- plugger.c.orig	Tue May  3 11:51:06 2005
+++ plugger.c	Tue May  3 11:51:32 2005
@@ -624,16 +624,6 @@
   if(cb(fname, data)) return 1;
 #endif
 
-  sprintf(fname,"/usr/local/netscape/%s",basename);
-  if(cb(fname, data)) return 1;
-  sprintf(fname,"/etc/%s",basename);
-  if(cb(fname, data)) return 1;
-  sprintf(fname,"/usr/etc/%s",basename);
-  if(cb(fname, data)) return 1;
-  sprintf(fname,"/usr/local/etc/%s",basename);
-  if(cb(fname, data)) return 1;
-  if(cb(basename, data)) return 1;
-  
   return 0;
 }
 
