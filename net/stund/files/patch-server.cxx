
$FreeBSD$

--- server.cxx	2004/06/10 15:25:17	1.1
+++ server.cxx	2004/06/10 15:26:05
@@ -172,7 +172,7 @@
 #if defined(WIN32)
    int pid=0;
 
-   if ( background )
+   if ( !background )
    {
       cerr << "The -b background option does not work in windows" << endl;
       exit(-1);
@@ -180,7 +180,7 @@
 #else
    pid_t pid=0;
 
-   if ( background )
+   if ( !background )
    {
       pid_t pid = fork();
 
