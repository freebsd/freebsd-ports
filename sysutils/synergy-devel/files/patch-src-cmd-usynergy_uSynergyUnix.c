--- src/cmd/usynergy/uSynergyUnix.c.orig	2013-02-18 12:04:59.000000000 +0100
+++ src/cmd/usynergy/uSynergyUnix.c	2013-02-18 12:05:53.000000000 +0100
@@ -27,7 +27,7 @@
 #include "uSynergy.h"
 
 // TODO: implement callbacks.
-int main(char* argv, int argc) {
+int main(int argc, char **argv) {
 	uSynergyContext context;
 	uSynergyInit(&context);
 	
