--- common/gencode.c~	Mon Apr 26 18:30:23 2004
+++ common/gencode.c	Sat Dec 16 15:40:07 2006
@@ -232,7 +232,7 @@
 #include <signal.h>
 #include <sys/wait.h>
 
-static u_int ArgusNetMask;
+u_int ArgusNetMask;
 static int snaplen;
 
 int
