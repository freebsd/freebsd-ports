--- plugins/fixsmbcop.cpp.orig	Sat Jul 14 21:39:17 2001
+++ plugins/fixsmbcop.cpp	Sat Jul 14 21:40:25 2001
@@ -27,7 +27,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-void
+int
 main(int args, char *argv[]) {
   if (args > 3) {
     if (cin) {
