--- fuzz.c.orig	Mon May 12 01:49:39 2003
+++ fuzz.c	Mon May 12 01:53:44 2003
@@ -387,10 +387,16 @@
     int progpipe[2],status;
     char sendnewline=0;
     unsigned long curchar=0,linelen=0;
+    int fd;
 
     // finish setting up files
     if(!execute_filename){
-      snprintf(outfilename,MAXPATH,"/tmp%s.%lu",strrchr(progname,'/'),runs);
+      snprintf(outfilename,MAXPATH,"/tmp%s.%lu.XXXXXX",strrchr(progname,'/'),runs);
+      if ((fd=mkstemp(outfilename)) < 0) {
+         perror("Unable to create temporary file");
+         abort();
+      }
+      close(fd);
       if((outfile=fopen(outfilename,"w"))==NULL){
 	fprintf(stderr,"Can't fopen outfile.\n");
 	abort();
