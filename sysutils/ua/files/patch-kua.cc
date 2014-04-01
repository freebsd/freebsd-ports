--- ./kua.cc.orig	2014-03-31 20:20:29.908846067 +0100
+++ ./kua.cc	2014-03-31 20:20:48.178847931 +0100
@@ -49,6 +49,7 @@
 
 extern "C" {
 #include <stdio.h>
+#include <unistd.h>
 }
 
 static char __help[] = 
