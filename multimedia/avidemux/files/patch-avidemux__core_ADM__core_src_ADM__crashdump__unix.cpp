--- avidemux_core/ADM_core/src/ADM_crashdump_unix.cpp.orig	2019-08-15 07:25:39 UTC
+++ avidemux_core/ADM_core/src/ADM_crashdump_unix.cpp
@@ -40,8 +40,8 @@
 static ADM_saveFunction *mysaveFunction=NULL;
 static ADM_fatalFunction *myFatalFunction=NULL;
 static ADM_sigIntFunction *mySigIntFunction=NULL;
-static sighandler_t      oldSignalHandlerSigInt;
-static sighandler_t      oldSignalHandlerSigSev;
+static sig_t      oldSignalHandlerSigInt;
+static sig_t      oldSignalHandlerSigSev;
 void sig_segfault_handler(int signo);
 void sig_sigint_handler(int signo);
 
