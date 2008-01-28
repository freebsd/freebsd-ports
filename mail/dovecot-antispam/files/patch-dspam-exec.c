--- dspam-exec.c.orig	2007-10-29 14:09:16.000000000 +0300
+++ dspam-exec.c	2008-01-05 18:38:37.000000000 +0300
@@ -127,7 +127,7 @@
 
 		argv[0] = (char *)dspam_binary;
 		argv[1] = "--source=error";
-		argv[2] = "--stdout";
+		argv[2] = "--deliver=";
 		argv[3] = (char *)class_arg;
 		argv[4] = (char *)sign_arg;
 
@@ -136,7 +136,7 @@
 		 * not good with stderr debuggin since we then write to
 		 * stderr which our parent takes as a bug
 		 */
-		debug("%s --source=error --stdout %s %s ...",
+		debug("%s --source=error --deliver= %s %s ...",
 		      dspam_binary, class_arg, sign_arg);
 #endif
 
