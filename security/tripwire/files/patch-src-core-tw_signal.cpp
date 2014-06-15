--- src/core/tw_signal.cpp.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/core/tw_signal.cpp	2014-06-15 01:48:28.000000000 +0200
@@ -79,7 +79,7 @@ void util_SignalHandler( int sig )
 #if IS_UNIX
 void tw_psignal(int sig, const TCHAR *str)
 {
-    TCHAR *siglist[NSIG] = {
+    const TCHAR *siglist[NSIG] = {
         _T("Unknown Signal"),
         _T("Hangup"),
         _T("Interrupt"),
