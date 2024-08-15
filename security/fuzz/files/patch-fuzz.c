--- fuzz.c.orig	2000-08-09 14:48:26 UTC
+++ fuzz.c
@@ -387,10 +387,16 @@ int main(int argc, char **argv){
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
