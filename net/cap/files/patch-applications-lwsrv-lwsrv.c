--- applications/lwsrv/lwsrv.c.orig	Sat Mar 20 14:38:45 2004
+++ applications/lwsrv/lwsrv.c	Sat Mar 20 14:55:51 2004
@@ -1864,7 +1864,7 @@
 PFILE *pf;
 {
   long t;
-  int argc, i;
+  int argc, i, fd;
   FILE *outfile;
   char tname[256],status[256];
   char pbuf[256],rhbuf[16],jbuf[1024];
@@ -1930,10 +1930,8 @@
       strcat(tname,"/lwsrvXXXXXX");
     } else
       strcpy(tname,TEMPFILE);
-    mktemp(tname);
-    if ((outfile = fopen(tname, "w+")) == NULL)
+    if ( ((fd = mkstemp(tname)) == -1 ) || ((outfile = fdopen(fd, "w+")) == NULL) )
       perror(tname);
-    chmod(tname, 0600);
   }
 
   NewStatus(prtp->children <= 0 ? "initializing" : statusprocessing);
@@ -2310,7 +2308,7 @@
 PFILE *pf;
 {
   long t;
-  int argc, i;
+  int argc, i, fd;
   FILE *outfile;
   char tname[256],status[256];
   char pbuf[256],rhbuf[16],jbuf[1024];
@@ -2354,16 +2352,15 @@
     if (tmpfiledir != NULL) {
       strcpy(tname,tmpfiledir);
       strcat(tname,"/lwsrvXXXXXX");
+      if ((outfile = fopen(tname, "w+")) == NULL)
+        perror(tname);
+      chmod(tname, 0600);
     } else
       strcat(tname,TEMPFILE);
-    mktemp(tname);
+      if ( ((fd = mkstemp(tname)) == -1 ) || ((outfile = fdopen(fd, "w+")) == NULL) )
+        perror(tname);
   }
   
-  if ((outfile = fopen(tname, "w+")) == NULL)
-    perror(tname);
-
-  chmod(tname, 0600);
-
   if (singlefork)
     NewStatus("initializing");
 
