--- src/NewsCache.cc.orig	Fri Oct 24 12:12:20 2003
+++ src/NewsCache.cc	Wed Dec 10 15:47:46 2003
@@ -24,7 +24,6 @@
  */
 #include "config.h"
 
-#include <crypt.h>
 #include <ctype.h>
 #include <unistd.h>
 #include <string.h>
@@ -2024,7 +2023,7 @@
 		}
 
 		cmdp = clt.client_command_map.find(argv[0]);
-		if (cmdp == end || !cmdp->second->func) {
+		if (cmdp == clt.client_command_map.end() || !cmdp->second->func) {
 			slog.p(Logger::Notice) << clt.client_logname
 			    << " unrecognized " << oreq << "\n";
 			(*clt.co) << "500 What?\r\n";
