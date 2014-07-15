--- readpassphrase.c-orig	2014-07-15 19:27:23.000000000 +0200
+++ readpassphrase.c	2014-07-15 19:28:20.000000000 +0200
@@ -32,6 +32,10 @@
 #include <unistd.h>
 #include <readpassphrase.h>
 
+#ifndef _NSIG
+#define _NSIG NSIG
+#endif
+
 static volatile sig_atomic_t signo[_NSIG];
 
 static void handler(int);
