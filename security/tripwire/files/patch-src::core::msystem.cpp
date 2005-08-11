--- src/core/msystem.cpp.orig	Wed Aug 10 15:59:22 2005
+++ src/core/msystem.cpp	Wed Aug 10 17:00:19 2005
@@ -951,8 +951,11 @@
 			 * ignore any signals until child dies
 			 */
 			for(i = 0; i < MAX_SIGNAL; i++)
+#ifdef __FreeBSD__
+#define SIGCLD	SIGCHLD
+#endif
 #ifdef SIGCLD
 				if (i != SIGCLD)
 #endif
 					savesig[i] = tw_sigign(i);
 			/*
