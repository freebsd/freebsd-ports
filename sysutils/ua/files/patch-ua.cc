--- ./ua.cc.orig	2014-03-31 20:20:23.870845476 +0100
+++ ./ua.cc	2014-03-31 20:21:00.021844495 +0100
@@ -57,6 +57,7 @@
 
 extern "C" {
 #include <stdio.h>
+#include <unistd.h>
 }
 
 static char __help[] = 
