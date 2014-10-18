--- annoyance-filter.cc.orig	2004-08-04 16:28:36.000000000 -0400
+++ annoyance-filter.cc	2014-10-08 12:04:20.000000000 -0400
@@ -114,7 +114,7 @@
 #define __GNU_LIBRARY__
 #undef __GETOPT_H__
 #endif
-#include "getopt.h"     
+#include <getopt.h>
 #include "statlib.h" 
 
 /*237:*/
@@ -2675,7 +2675,7 @@
 fileLength= lseek(fileHandle,0,2);
 lseek(fileHandle,0,0);
 dp= static_cast<char*> (mmap((caddr_t)0,fileLength,
-PROT_READ,MAP_SHARED|MAP_NORESERVE,
+PROT_READ,MAP_SHARED,
 fileHandle,0));
 istrstream is(dp,fileLength);
 #else
@@ -7332,7 +7332,7 @@
 long fileLength= lseek(fileHandle,0,2);
 lseek(fileHandle,0,0);
 char*dp= static_cast<char*> (mmap((caddr_t)0,fileLength,
-PROT_READ,MAP_SHARED|MAP_NORESERVE,
+PROT_READ,MAP_SHARED,
 fileHandle,0));
 istrstream is(dp,fileLength);
 #else
