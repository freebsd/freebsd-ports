--- Server.tproj/main.cpp.orig	2008-05-06 08:28:59.000000000 +0900
+++ Server.tproj/main.cpp	2008-06-01 18:09:20.000000000 +0900
@@ -216,7 +216,7 @@
     //(void) ::signal(SIGPIPE, SIG_IGN);
     struct sigaction act;
     
-#if defined(sun) || defined(i386) || defined (__MacOSX__) || defined(__powerpc__) || defined (__osf__) || defined (__sgi_cc__) || defined (__hpux__)
+#if defined(sun) || defined(i386) || defined (__MacOSX__) || defined(__powerpc__) || defined (__osf__) || defined (__sgi_cc__) || defined (__hpux__) || defined(__amd64__)
     sigemptyset(&act.sa_mask);
     act.sa_flags = 0;
     act.sa_handler = (void(*)(int))&sigcatcher;
@@ -306,7 +306,7 @@
 
     char* theConfigFilePath = sDefaultConfigFilePath;
     char* theXMLFilePath = sDefaultXMLFilePath;
-    while ((ch = getopt(argc,argv, "vdfxp:DZ:c:o:S:Ih")) != EOF) // opt: means requires option arg
+    while ((ch = getopt(argc,argv, "vdfxp:DZ:c:o:S:Ih")) != -1) // opt: means requires option arg
     {
         switch(ch)
         {
