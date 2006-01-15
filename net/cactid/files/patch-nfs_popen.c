--- nft_popen.c.orig	Sun Jan 15 10:27:41 2006
+++ nft_popen.c	Sun Jan 15 10:28:08 2006
@@ -66,6 +66,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <sys/wait.h>
+#include <sys/signal.h>
 
 #include <nft_popen.h>
 
