--- ../gcc-2.95.3/libiberty/strsignal.c~	Fri May 15 23:42:42 1998
+++ ../gcc-2.95.3/libiberty/strsignal.c	Mon May  5 14:16:36 2003
@@ -244,7 +244,7 @@
 #else
 
 #ifdef NSIG
-static int sys_nsig = NSIG;
+static const int sys_nsig = NSIG;
 #else
 #ifdef _NSIG
 static int sys_nsig = _NSIG;
