--- MP3Broadcaster/BroadcasterMain.cpp.orig	2008-05-06 08:28:57.000000000 +0900
+++ MP3Broadcaster/BroadcasterMain.cpp	2008-06-01 18:05:51.000000000 +0900
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
     
-#if defined(sun) || defined(i386) || defined(__MacOSX__) || defined(__sgi__) || defined(__osf__) || defined(__hpux__) || defined(__linuxppc__)
+#if defined(sun) || defined(i386) || defined(__MacOSX__) || defined(__sgi__) || defined(__osf__) || defined(__hpux__) || defined(__linuxppc__) || defined(__amd64__)
     sigemptyset(&act.sa_mask);
     act.sa_flags = 0;
     act.sa_handler = (void(*)(int))&SignalEventHandler;
