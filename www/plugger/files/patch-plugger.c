--- plugger.c.orig	2004-08-04 20:03:29.000000000 +0200
+++ plugger.c	2011-12-20 20:23:39.068175279 +0100
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
 
@@ -1060,17 +1050,17 @@
 
   D("start_standalone!\n");
 
-  if(!THIS->command) { D("no command!\n"); return; }
-  if(!WINDOW) { D("No window!\n"); return; }
+  if(!THIS->command) { D("no command!\n"); return NPERR_GENERIC_ERROR; }
+  if(!WINDOW) { D("No window!\n"); return NPERR_GENERIC_ERROR; }
 
   if(THIS->flags & H_URL)
   {
-    if(!THIS->url) { D("No url!\n"); return; }
+    if(!THIS->url) { D("No url!\n"); return NPERR_GENERIC_ERROR; }
   }else{
-    if(!THIS->stream) { D("No stream!\n"); return; }
+    if(!THIS->stream) { D("No stream!\n"); return NPERR_GENERIC_ERROR; }
   }
 
-  if(THIS->waitfd!=-1) { D("Already started!\n"); return; }
+  if(THIS->waitfd!=-1) { D("Already started!\n"); return NPERR_GENERIC_ERROR; }
   D("Actually starging!\n");
 
   if(socketpair(AF_UNIX, SOCK_STREAM, 0, bar) < 0)
@@ -1082,7 +1072,7 @@
   if(THIS->pid1==-1)
   {
     NPN_Status(instance, "My_Fork failed!");
-    return;
+    return NPERR_GENERIC_ERROR;
   }
   
   if(!THIS->pid1)
@@ -1097,6 +1087,7 @@
     THIS->waitfd=bar[0];
     close(bar[1]);
   }
+  return NPERR_NO_ERROR;
 }
 
 
