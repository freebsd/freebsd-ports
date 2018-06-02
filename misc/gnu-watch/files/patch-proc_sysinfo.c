--- proc/sysinfo.c.orig	2018-05-18 21:32:22 UTC
+++ proc/sysinfo.c
@@ -30,7 +30,7 @@
 
 #include <unistd.h>
 #include <fcntl.h>
-#ifdef __CYGWIN__
+#ifdef __FreeBSD__
 #include <sys/param.h>
 #endif
 #include "alloc.h"
@@ -41,7 +41,7 @@
 #include <netinet/in.h>  /* htons */
 #endif
 
-#ifndef __CYGWIN__
+#ifndef __FreeBSD__
 #include <link.h>
 #endif
 #include <elf.h>
@@ -98,7 +98,7 @@ static char buf[8192];
 #define SET_IF_DESIRED(x,y) do{  if(x) *(x) = (y); }while(0)
 
 /* return minimum of two values */
-#ifndef __CYGWIN__
+#ifndef __FreeBSD__
 #define MIN(x,y) ((x) < (y) ? (x) : (y))
 #endif
 
@@ -264,7 +264,7 @@ extern char** environ;
 
 static unsigned long find_elf_note(unsigned long type)
 {
-#ifdef __CYGWIN__
+#ifdef __FreeBSD__
   return NOTE_NOT_FOUND;
 #else
   ElfW(auxv_t) auxv_struct;
