--- pft/main.cpp.orig	Sat Jul  6 18:36:30 2002
+++ pft/main.cpp	Thu Aug  5 19:33:12 2004
@@ -8,7 +8,7 @@
  *
  * $Id: main.cpp,v 1.8 2002/07/06 15:36:29 fx Exp fx $
  */
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>			// cant live without printf() ;)
 
 #ifndef UNIX
@@ -27,12 +27,15 @@
 #include <sys/types.h>			// open(), close(), write()
 #include <sys/stat.h>
 #include <fcntl.h>
-#endif UNIX
+#include <string.h>			// memset()
+#endif // UNIX
 
 #include "fxstrings.h"
 #include "pjlsession.h"
 #include "commands.h"
 
+using namespace std;
+
 #define SPLASH			"PFT - PJL file transfer\n" \
 						"\tFX of Phenoelit <fx@phenoelit.de>\n"\
 						"\tVersion 0.7 ($Revision: 1.8 $)\n"
@@ -89,7 +92,7 @@
 void	commandline_ident(void);
 #ifdef UNIX
 void	sighandl(int s);
-#endif UNIX
+#endif // UNIX
 
 
 class Program_config {
@@ -102,7 +105,7 @@
 		bool			pause;
 #ifdef UNIX
 		bool			ctrlc;
-#endif UNIX
+#endif // UNIX
 };
 
 Program_config		cfg;
@@ -122,7 +125,7 @@
 	}
 #else 
 	cfg.lpwd=_getcwd(NULL,0);
-#endif UNIX
+#endif // UNIX
 	
 	if (argc>3) {
 		usage(argv[0]);
@@ -148,7 +151,7 @@
 void sighandl(int s) {
 	cfg.ctrlc=true;
 }
-#endif UNIX
+#endif // UNIX
 
 void cmdloop(void) {
 	String			cmd;
@@ -209,7 +212,7 @@
 #ifdef UNIX
 			// endable default handler for ctrl-c during connect() call
 			signal(SIGINT,SIG_DFL);
-#endif UNIX
+#endif // UNIX
 			
 
 			if (sess.connected()) {
@@ -238,7 +241,7 @@
 			}
 #ifdef UNIX
 			signal(SIGINT,&sighandl);
-#endif UNIX
+#endif // UNIX
 		}
 
 		// close connection
@@ -486,7 +489,7 @@
 					if (_kbhit()) break;
 #else
 					if (cfg.ctrlc) break;
-#endif UNIX
+#endif // UNIX
 
 					if (++di==dx) {
 						cout << "try " << p << endl;
@@ -523,7 +526,7 @@
 					if (_kbhit()) break;
 #else
 					if (cfg.ctrlc) break;
-#endif UNIX
+#endif // UNIX
 				}
 
 			// env invalid
@@ -826,7 +829,7 @@
 			} else {
 				cerr << "lcd failed" << endl;
 			}
-#endif UNIX
+#endif // UNIX
 		}
 		// get command
 		else if (basecmd==CMD_GET) {
@@ -949,7 +952,7 @@
 				cout << sess.filebuffer.length() 
 					<< " bytes read from local file " << cmd.token(' ',1)<< endl;
 			}
-#endif UNIX
+#endif // UNIX
 
 			try {
 				sess.append_file(targ.get());
@@ -1193,7 +1196,7 @@
 #ifdef UNIX
 	// endable default handler for ctrl-c during connect() call
 	signal(SIGINT,SIG_DFL);
-#endif UNIX
+#endif // UNIX
 
 	try {
 		sess.initiate(cfg.server.get(),cfg.port);
