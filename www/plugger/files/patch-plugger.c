--- plugger.c.orig	Sun Mar 24 20:58:49 2002
+++ plugger.c	Sun Mar 24 21:06:15 2002
@@ -437,33 +437,31 @@
   D("find_helper_file '%s'\n",basename);
   if((tmp=getenv("HOME")) && strlen(tmp)<8000)
   {
-    sprintf(fname,"%s/.netscape/%s",tmp,basename);
+    snprintf(fname,strlen(tmp)+11+strlen(basename)+1,"%s/.netscape/%s",tmp,basename);
     if(cb(fname,data)) return 1;
-    sprintf(fname,"%s/.mozilla/%s",tmp,basename);
+    snprintf(fname,strlen(tmp)+10+strlen(basename)+1,"%s/.mozilla/%s",tmp,basename);
     if(cb(fname,data)) return 1;
-    sprintf(fname,"%s/.opera/%s",tmp,basename);
+    snprintf(fname,strlen(tmp)+8+strlen(basename)+1,"%s/.opera/%s",tmp,basename);
     if(cb(fname,data)) return 1;
   }
 
   if((tmp=getenv("MOZILLA_HOME")) && strlen(tmp)<8000)
   {
-    sprintf(fname,"%s/%s",tmp,basename);
+    snprintf(fname,strlen(tmp)+1+strlen(basename)+1,"%s/%s",tmp,basename);
     if(cb(fname, data)) return 1;
   }
 
   if((tmp=getenv("OPERA_DIR")) && strlen(tmp)<8000)
   {
-    sprintf(fname,"%s/%s",tmp,basename);
+    snprintf(fname,strlen(tmp)+1+strlen(basename)+1,"%s/%s",tmp,basename);
     if(cb(fname, data)) return 1;
   }
 
-  sprintf(fname,"/usr/local/netscape/%s",basename);
+  snprintf(fname,strlen(basename)+5+1,"/etc/%s",basename);
   if(cb(fname, data)) return 1;
-  sprintf(fname,"/etc/%s",basename);
+  snprintf(fname,strlen(basename)+9+1,"/usr/etc/%s",basename);
   if(cb(fname, data)) return 1;
-  sprintf(fname,"/usr/etc/%s",basename);
-  if(cb(fname, data)) return 1;
-  sprintf(fname,"/usr/local/etc/%s",basename);
+  snprintf(fname,strlen(basename)+15+1,"/usr/local/etc/%s",basename);
   if(cb(fname, data)) return 1;
   if(cb(basename, data)) return 1;
   
