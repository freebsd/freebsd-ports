--- memfetch.c.orig	Mon Oct 20 20:04:45 2003
+++ memfetch.c	Thu Nov 25 15:51:00 2004
@@ -20,6 +20,8 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#include <sys/uio.h>
+#include <sys/types.h>
 #include <sys/ptrace.h>
 #include <fcntl.h>
 #include <string.h>
@@ -27,7 +29,8 @@
 #include <signal.h>
 #include <time.h>
 #include <sys/mman.h>
-#include <asm/page.h>
+/* #include <asm/page.h> */
+#include <sys/param.h>
 #include <getopt.h>
 #include <errno.h>
 
@@ -49,7 +52,7 @@
        fprintf(outfile,"** Error message: " x); \
        fclose(outfile); \
      } \
-     if (tracepid>0) ptrace(PTRACE_DETACH,tracepid,0,lastsig); \
+     if (tracepid>0) ptrace(PT_DETACH,tracepid,0,lastsig); \
      exit(1); \
    }
 
@@ -74,6 +77,7 @@
         "  -a      - skip non-anonymous maps (libraries etc)\n"
         "  -w      - write index file to stdout instead of mfetch.lst\n"
         "  -m      - avoid mmap(), helps prevent hanging on some 2.2 boxes\n"
+	"          - this is the only way to go on FreeBSD, for now.\n"
         "  -S xxx  - dump segment containing address xxx (hex) only\n",myname);
   exit(3);
 }
@@ -124,7 +128,7 @@
   if (kill(tracepid,0)) 
     fatal("Process does not exist or is not accessible.\n");
 
-  if (ptrace(PTRACE_ATTACH,tracepid,0,0)) 
+  if (ptrace(PT_ATTACH,tracepid,0,0)) 
     fatal("Cannot attach to this process (already traced?).\n");
 
   if ( wait(&st)<=0 || !WIFSTOPPED(st) ) {
@@ -149,7 +153,7 @@
 
     while (1) {
 
-      ptrace(PTRACE_CONT,tracepid,0,lastsig);
+      ptrace(PT_CONTINUE,tracepid,0,lastsig);
       
       if (wait(&st)<=0) {
         debug("[-] Process gone before receiving a fault signal.\n");
@@ -198,7 +202,7 @@
 
 leavewait: // GOTOs for president!
 
-  sprintf(tmp,"/proc/%d/maps",tracepid);
+  sprintf(tmp,"/proc/%d/map",tracepid);
   mapfile=fopen(tmp,"r");
 
   if (!mapfile) fatal("Cannot open %s for reading.\n",tmp); 
@@ -237,8 +241,8 @@
     int* writeptr;
     char mapped=1;
 
-    if (sscanf(tmp,"%x-%x",&st,&en)!=2) {
-      debug("[!] Parse error in /proc/%d/maps (mockery?): %s",tracepid,tmp);
+    if (sscanf(tmp,"%x %x",&st,&en)!=2) {
+      debug("[!] Parse error in /proc/%d/map (mockery?): %s",tracepid,tmp);
       continue;
     }
 
@@ -280,7 +284,7 @@
             st,len);
 
     if (avoid_mmap) writeptr=MAP_FAILED; else {      
-      for (i=st;i<=en;i+=PAGE_SIZE) ptrace(PTRACE_PEEKDATA,tracepid,i,0);
+      for (i=st;i<=en;i+=PAGE_SIZE) ptrace(PT_READ_D,tracepid,(caddr_t)i,0);
       writeptr=mmap(0,len,PROT_READ,MAP_PRIVATE,memfile,st);
     }
 
@@ -292,7 +296,7 @@
       if (lseek(memfile,st,SEEK_SET)!=st || read(memfile,writeptr,len)!=len) {
         debug("[S] ");
         for (i=0;i<len/4;i++)
-          writeptr[i]=ptrace(PTRACE_PEEKDATA,tracepid,st+i*4,0);
+          writeptr[i]=ptrace(PT_READ_D,tracepid,(caddr_t)st+i*4,0);
       } else debug("[N] ");
 
     }
@@ -308,14 +312,14 @@
 
   }
 
-  if (!dumpcnt) fatal("No matching entries found in /proc/%d/maps.\n",tracepid);
+  if (!dumpcnt) fatal("No matching entries found in /proc/%d/map.\n",tracepid);
 
   if (!textout) fprintf(outfile,"# End of file.\n");
 
   debug("[*] Done (%d matching). Have a nice day.\n",dumpcnt);
 
   fclose(outfile);
-  ptrace(PTRACE_DETACH,tracepid,0,lastsig);
+  ptrace(PT_DETACH,tracepid,0,lastsig);
 
   exit(0);
 
