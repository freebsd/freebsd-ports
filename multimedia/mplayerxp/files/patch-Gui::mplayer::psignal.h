--- Gui/mplayer/psignal.h.orig	Fri Sep 28 19:46:22 2001
+++ Gui/mplayer/psignal.h	Fri Sep 28 19:46:55 2001
@@ -39,7 +39,7 @@
 #define mplIncAudioBufferDelay                   28
 #define mplDecAudioBufferDelay                   29
 
-#ifdef	__SVR4
+#if defined(__SVR4) || defined(__FreeBSD__)
 #define	SIGTYPE SIGUSR2
 #warning should we use SIGUSR1 or SIGUSR2 on linux, bsd, ... too?
 #else
