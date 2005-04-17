
$FreeBSD$

--- server.cxx.orig
+++ server.cxx
@@ -32,7 +32,7 @@
         << "  -a sets the secondary IP" << endl
         << "  -p sets the primary port and defaults to 3478" << endl
         << "  -o sets the secondary port and defaults to 3479" << endl
-        << "  -b makes the program run in the backgroud" << endl
+        << "  -b makes the program run in the background" << endl
         << "  -m sets up a STERN server starting at port m" << endl
         << "  -v runs in verbose mode" << endl
       // in makefile too
@@ -188,30 +188,14 @@
       //exit(1);
    }
    
-#if defined(WIN32)
-   int pid=0;
-
-   if ( background )
-   {
-      cerr << "The -b background option does not work in windows" << endl;
-      exit(-1);
-   }
-#else
-   pid_t pid=0;
-
-   if ( background )
-   {
-      pid = fork();
-
-      if (pid < 0)
-      {
-         cerr << "fork: unable to fork" << endl;
-         exit(-1);
-      }
+   if (background) {
+       if (daemon(0,0) < 0) {
+           cerr << "daemon() call failed" << endl;
+           exit(1);
+       }
    }
-#endif
 
-   if (pid == 0) //child or not using background
+   if (1) //child or not using background
    {
       StunServerInfo info;
       bool ok = stunInitServer(info, myAddr, altAddr, myMediaPort, verbose);
