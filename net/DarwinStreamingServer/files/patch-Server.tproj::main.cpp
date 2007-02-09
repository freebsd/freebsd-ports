--- Server.tproj/main.cpp.orig	Wed Apr 27 21:21:14 2005
+++ Server.tproj/main.cpp	Sat Feb 10 04:06:49 2007
@@ -212,7 +212,7 @@
     //(void) ::signal(SIGPIPE, SIG_IGN);
     struct sigaction act;
     
-#if defined(sun) || defined(i386) || defined (__MacOSX__) || defined(__powerpc__) || defined (__osf__) || defined (__sgi_cc__) || defined (__hpux__)
+#if defined(sun) || defined(i386) || defined (__MacOSX__) || defined(__powerpc__) || defined (__osf__) || defined (__sgi_cc__) || defined (__hpux__) || defined(__amd64__)
     sigemptyset(&act.sa_mask);
     act.sa_flags = 0;
     act.sa_handler = (void(*)(int))&sigcatcher;
@@ -291,7 +291,7 @@
 
     char* theConfigFilePath = sDefaultConfigFilePath;
     char* theXMLFilePath = sDefaultXMLFilePath;
-    while ((ch = getopt(argc,argv, "vdfxp:DZ:c:o:S:Ih")) != EOF) // opt: means requires option arg
+    while ((ch = getopt(argc,argv, "vdfxp:DZ:c:o:S:Ih")) != -1) // opt: means requires option arg
     {
         switch(ch)
         {
