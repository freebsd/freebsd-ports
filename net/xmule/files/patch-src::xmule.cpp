--- src/xmule.cpp.orig	Tue May 27 00:02:47 2003
+++ src/xmule.cpp	Tue May 27 21:31:38 2003
@@ -55,16 +55,6 @@
 //	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
 //END_MESSAGE_MAP()
 
-#include <sys/time.h>
-inline long GetTickCount()
-{	
-  struct timeval aika;
-  gettimeofday(&aika,NULL);
-  unsigned long secs=aika.tv_sec*1000;
-  secs+=(aika.tv_usec/1000);
-  return secs;
-}
-
 CxmuleApp::CxmuleApp() {
   splashBmp=new wxBitmap((const char**)About_jpg);
 }
@@ -641,11 +631,13 @@
     
 } //End Added By Bouc7
 
-
+#if 0
 #include <execinfo.h>
+#endif
 
 void CxmuleApp::OnFatalException()
 {
+#if 0
     // (stkn) create backtrace
     void * bt_array[100]; // 100 should be enough ?!?
     char ** bt_strings;
@@ -666,6 +658,7 @@
        fprintf(stderr, "[%d] %s\n", i, bt_strings[i]);
        
     free(bt_strings);
+#endif
 }
 
 #define wxGTK_WINDOW 1
