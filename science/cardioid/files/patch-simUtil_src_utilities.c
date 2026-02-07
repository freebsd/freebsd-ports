--- simUtil/src/utilities.c.orig	2022-08-24 19:51:03 UTC
+++ simUtil/src/utilities.c
@@ -72,6 +72,10 @@ void mem_debug(char *mem_str)
    static int flag =1; 
    if (flag) printf("No mallinfo on OS X.  Sorry no minfo for <%s>.\n",mem_str);
    flag =0; 
+#elif defined(__FreeBSD__)
+   static int flag =1; 
+   if (flag) printf("No mallinfo on FreeBSD.  Sorry no minfo for <%s>.\n",mem_str);
+   flag =0; 
 #else
    static struct mallinfo old_minfo, minfo;
    static int gstep = 0;
@@ -98,7 +102,7 @@ void mem_debug(char *mem_str)
 */
 void CHKMEM(char *string)
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <sys/resource.h>
 	static struct mallinfo minfo, minfosave;
 	minfosave = minfo;
