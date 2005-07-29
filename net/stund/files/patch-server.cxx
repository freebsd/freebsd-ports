
$FreeBSD$

--- server.cxx.orig
+++ server.cxx
@@ -6,10 +6,14 @@
 #ifndef WIN32
 #include <sys/time.h>
 #include <sys/types.h>
+#include <sys/file.h>
+#include <fcntl.h>
 #include <unistd.h>
 #include <netinet/in.h>
 #include <errno.h>
 #include <stdlib.h>
+#include <err.h>
+#include <stdio.h>
 #endif
 
 #include "udp.h"
@@ -32,13 +36,16 @@
         << "  -a sets the secondary IP" << endl
         << "  -p sets the primary port and defaults to 3478" << endl
         << "  -o sets the secondary port and defaults to 3479" << endl
-        << "  -b makes the program run in the backgroud" << endl
+        << "  -b makes the program run in the background" << endl
         << "  -m sets up a STERN server starting at port m" << endl
         << "  -v runs in verbose mode" << endl
       // in makefile too
         << endl;
 }
 
+#define DEFAULT_PIDFILE "/var/run/stund.pid"
+
+int pf = -1;
 
 int
 main(int argc, char* argv[])
@@ -63,6 +70,7 @@
    int myPort = 0;
    int altPort = 0;
    int myMediaPort = 0;
+   const char *pidfile = DEFAULT_PIDFILE;
    
    UInt32 interfaces[10];
    int numInterfaces = stunFindLocalInterfaces(interfaces,10);
@@ -135,6 +143,14 @@
          }
          myMediaPort = UInt16(strtol( argv[arg], NULL, 10));
       }
+      else if( !strcmp( argv[arg], "-i" ) ) {
+         ++arg;
+         if( argc <= arg ) {
+            usage();
+            exit(-1);
+         }
+         pidfile = argv[arg];
+      }
       else
       {
          usage();
@@ -188,30 +204,30 @@
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
+       // Create pidfile
+       pf = open( pidfile, O_RDWR|O_CREAT, 0644 );
+       if( pf == -1 )
+          err( 1, "open(pidfile)" );
+       if( flock( pf, LOCK_EX | LOCK_NB ) == -1 ) {
+          if( errno == EWOULDBLOCK )
+             errx( 1, "pidfile is locked by another process" );
+          err( 1, "flock(pidfile)" );
+       }
+       if( ftruncate( pf, 0 ) == -1 )
+          err( 1, "ftruncate(pidfile)" );
+       char buf[20];
+       ssize_t blen = snprintf( buf, sizeof buf, "%d\n", (int) getpid() );
+       if( write( pf, buf, blen ) != blen )
+          err( 1, "write(pidfile)" );
+       // Don't close pf as we hold lock on it
    }
-#endif
 
-   if (pid == 0) //child or not using background
+   if (1) //child or not using background
    {
       StunServerInfo info;
       bool ok = stunInitServer(info, myAddr, altAddr, myMediaPort, verbose);
