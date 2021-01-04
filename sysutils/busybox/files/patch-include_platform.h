--- include/platform.h.orig	2021-01-01 13:30:02 UTC
+++ include/platform.h
@@ -319,7 +319,7 @@ typedef unsigned smalluint;
 #endif
 
 /* Define bb_setpgrp */
-#if defined(__digital__) && defined(__unix__)
+#if (defined(__digital__) && defined(__unix__) || defined(__FreeBSD__))
 /* use legacy setpgrp(pid_t, pid_t) for now.  move to platform.c */
 # define bb_setpgrp() do { pid_t __me = getpid(); setpgrp(__me, __me); } while (0)
 #else
