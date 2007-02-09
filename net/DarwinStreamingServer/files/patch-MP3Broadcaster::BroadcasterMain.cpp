--- MP3Broadcaster/BroadcasterMain.cpp.orig	Sat Mar 12 08:24:54 2005
+++ MP3Broadcaster/BroadcasterMain.cpp	Sat Feb 10 03:54:31 2007
@@ -85,7 +85,7 @@
     char* config = NULL;
     char* playList = NULL;
     char* workingDir = NULL;
-    char ch;
+    int ch;
     bool preflight = false;
     bool checkMP3s = false;
     char*   errorlog = NULL;
@@ -112,7 +112,7 @@
         ::exit(0);
     }
 
-    while ( (ch = getopt(argc,argv, "vdixXa:p:c:l:e:w:")) != EOF ) // opt: means requires option
+    while ( (ch = getopt(argc,argv, "vdixXa:p:c:l:e:w:")) != -1 ) // opt: means requires option
     {
         switch(ch)
         {
@@ -216,7 +216,7 @@
 
 struct sigaction act;
     
-#if defined(sun) || defined(i386) || defined(__MacOSX__) || defined(__sgi__) || defined(__osf__) || defined(__hpux__)
+#if defined(sun) || defined(i386) || defined(__MacOSX__) || defined(__sgi__) || defined(__osf__) || defined(__hpux__) || defined(__amd64__)
     sigemptyset(&act.sa_mask);
     act.sa_flags = 0;
     act.sa_handler = (void(*)(int))&SignalEventHandler;
