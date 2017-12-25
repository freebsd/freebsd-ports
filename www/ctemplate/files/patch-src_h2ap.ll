--- src/h2ap.ll.orig	2017-12-21 21:01:19 UTC
+++ src/h2ap.ll
@@ -37,7 +37,7 @@
 #include "ff_driver.hh"
 
 char* tplargs=0;
-const char* funcname=0;
+char* funcname=0;
 const char* funcprefix="tpl_";
 FILE* hout=0;
 
