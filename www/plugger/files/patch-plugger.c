--- plugger.c.orig	Fri Sep 10 14:42:03 2004
+++ plugger.c	Fri Sep 10 15:00:52 2004
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
 
