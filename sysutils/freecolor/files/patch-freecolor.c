--- ./freecolor.c.orig	2005-10-18 21:09:52.000000000 +0100
+++ ./freecolor.c	2009-05-14 13:31:55.000000000 +0100
@@ -62,9 +62,6 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
-#ifndef NO_GETOPT
-#include <getopt.h>
-#endif
 #define BARLEN 35
 #define HEADERLEN 14
 #define VERSION "0.8.7"
@@ -73,8 +70,8 @@
 extern char *optarg;
 extern int optind, opterr, optopt;
 
-void bargraph(float percent, float secondper, char marks[BARLEN+HEADERLEN],int usefull) {
-  char percentone[BARLEN], percenttwo[BARLEN], remain[BARLEN];
+void bargraph(float percent, float secondper, char marks[BARLEN+HEADERLEN+1],int usefull) {
+  char percentone[BARLEN+1], percenttwo[BARLEN+1], remain[BARLEN+1];
   unsigned int numberofmarks, numofmarkstwo, remainnum;
   numberofmarks=(int) ((float) (BARLEN*(percent/100)));
   if (!usefull) numofmarkstwo=(int) ((float) (BARLEN*(secondper/100))); else numofmarkstwo=(BARLEN-numberofmarks);
@@ -85,7 +82,7 @@
   percentone[numberofmarks]=0;
   percenttwo[numofmarkstwo]=0;
   remain[remainnum]=0;
-  sprintf(marks,"%s\033[1;31m%s\033[1;37m%s",percentone, percenttwo, remain);
+  snprintf(marks, BARLEN+HEADERLEN+1, "%s\033[1;31m%s\033[1;37m%s", percentone, percenttwo, remain);
   return;
 }
 
@@ -113,9 +110,9 @@
 int main(int argc, char *argv[]) {
   float percentram, percentswap, percentbuffer, percentused, percentfree;
   float ramfree, ramtotal, swapfree, swaptotal, doloop=0, cachedbuffer, totaltotal;
-  char realbarchart[BARLEN+HEADERLEN], swapbarchart[BARLEN+HEADERLEN], totalbarchart[BARLEN+HEADERLEN];
-  int i, divisor=1024, dototals=0, doold=0, linestoup=2;
-  unsigned long meminfo_cached;
+  char realbarchart[BARLEN+HEADERLEN+1], swapbarchart[BARLEN+HEADERLEN+1], totalbarchart[BARLEN+HEADERLEN+1];
+  int i, dototals=0, doold=0, linestoup=2;
+  unsigned long meminfo_cached, divisor=1024;
 #ifndef HAVE_LIBSTATGRAB
   struct sysinfo sinfo;
 
@@ -204,10 +201,10 @@
     bargraph(percentram,percentbuffer,realbarchart,0);
     bargraph((int) percentfree,(int) percentused,totalbarchart,1);
     if (!doold) {
-      printf("Physical  : \033[1;30m[\033[1;32m%s\033[1;30m]\033[1;37m %i\033[0;31m%%\033[0m\t(%i/%i)\n", realbarchart ,(int) (percentram+percentbuffer), (int) (ramfree+cachedbuffer)/divisor, (int) ramtotal/divisor);
-      printf("Swap      : \033[1;30m[\033[1;32m%s\033[1;30m]\033[1;37m %i\033[0;31m%%\033[0m\t(%i/%i)\n",swapbarchart ,(int) percentswap,(int) swapfree/divisor, (int) swaptotal/divisor);
+      printf("Physical  : \033[1;30m[\033[1;32m%s\033[1;30m]\033[1;37m %i\033[0;31m%%\033[0m\t(%lu/%lu)\n", realbarchart ,(int) (percentram+percentbuffer), (unsigned long) (ramfree+cachedbuffer)/divisor, (unsigned long) ramtotal/divisor);
+      printf("Swap      : \033[1;30m[\033[1;32m%s\033[1;30m]\033[1;37m %i\033[0;31m%%\033[0m\t(%lu/%lu)\n",swapbarchart ,(int) percentswap,(unsigned long) swapfree/divisor, (unsigned long) swaptotal/divisor);
       if (dototals) 
-      printf("Total     : \033[1;30m[\033[1;32m%s\033[1;30m]\033[1;37m \033[0m(%i=%i+%i)\n", totalbarchart, (int) (sinfo.totalram+sinfo.totalswap)/divisor,(int) ((sinfo.freeram+sinfo.freeswap)/divisor), (int) ((totaltotal-((sinfo.freeram+sinfo.freeswap+cachedbuffer)))/divisor));
+      printf("Total     : \033[1;30m[\033[1;32m%s\033[1;30m]\033[1;37m \033[0m(%lu=%lu+%lu)\n", totalbarchart, (unsigned long) (sinfo.totalram+sinfo.totalswap)/divisor,(unsigned long) ((sinfo.freeram+sinfo.freeswap)/divisor), (unsigned long) ((totaltotal-((sinfo.freeram+sinfo.freeswap+cachedbuffer)))/divisor));
     } else {
       printf("             total       used       free     shared    buffers     cached\n");
       printf("Mem:  %12lu %10lu %10lu %10lu %10lu %10lu\n",(sinfo.totalram/divisor), (sinfo.totalram-sinfo.freeram)/divisor, (sinfo.freeram/divisor), (sinfo.sharedram/divisor), (sinfo.bufferram/divisor), (((unsigned long) cachedbuffer)/divisor)); 
