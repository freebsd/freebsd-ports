--- include/platform.h.orig	2018-12-05 14:44:34 UTC
+++ include/platform.h
@@ -315,7 +315,7 @@ typedef unsigned smalluint;
 #endif
 
 /* Define bb_setpgrp */
-#if defined(__digital__) && defined(__unix__)
+#if (defined(__digital__) && defined(__unix__) || defined(__FreeBSD__))
 /* use legacy setpgrp(pid_t, pid_t) for now.  move to platform.c */
 # define bb_setpgrp() do { pid_t __me = getpid(); setpgrp(__me, __me); } while (0)
 #else
