--- channels/h323/ast_h323.cxx.orig	2008-04-08 15:08:37.000000000 +0300
+++ channels/h323/ast_h323.cxx	2008-04-08 15:08:51.000000000 +0300
@@ -81,8 +81,6 @@
 /** PWLib entry point */
 static MyProcess *localProcess = NULL;
 
-static int _timerChangePipe[2];
-
 static unsigned traceOptions = PTrace::Timestamp | PTrace::Thread | PTrace::FileAndLine;
 
 class PAsteriskLog : public PObject, public iostream {
@@ -191,8 +189,6 @@
 
 MyProcess::~MyProcess()
 {
-	_timerChangePipe[0] = timerChangePipe[0];
-	_timerChangePipe[1] = timerChangePipe[1];
 }
 
 void MyProcess::Main()
@@ -2460,8 +2456,6 @@
 	if (localProcess) {
 		delete localProcess;
 		localProcess = NULL;
-		close(_timerChangePipe[0]);
-		close(_timerChangePipe[1]);
 	}
 	if (logstream) {
 		PTrace::SetLevel(0);
