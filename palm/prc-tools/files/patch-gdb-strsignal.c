--- ../gdb-5.3/libiberty/strsignal.c.orig	Mon May  3 07:28:54 1999
+++ ../gdb-5.3/libiberty/strsignal.c	Mon May  5 14:27:35 2003
@@ -244,7 +244,7 @@
 #else
 
 #ifdef NSIG
-static int sys_nsig = NSIG;
+static const int sys_nsig = NSIG;
 #else
 #ifdef _NSIG
 static int sys_nsig = _NSIG;
