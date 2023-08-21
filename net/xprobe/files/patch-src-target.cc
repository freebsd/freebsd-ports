--- src/target.cc.orig	2005-07-27 08:38:17 UTC
+++ src/target.cc
@@ -28,6 +28,8 @@
 #include "os_matrix.h"
 #include "xplib/xplib.h"
 #include "log.h"
+#include <algorithm>
+#include <random>
 
 extern Interface *ui;
 extern Xprobe_Module_Hdlr   *xmh;
@@ -363,6 +365,8 @@ void Port_Range::set_range(u_short a, u_short b) {
 
 int Port_Range::get_next(u_short *port) {
 	int k, sz=size();
+	std::random_device rd;
+	std::mt19937 g(rd());
 	
 	if (curr+low > high)
 		return 1;
@@ -370,7 +373,7 @@ int Port_Range::get_next(u_short *port) {
 		// initialize
 		for (k=0; k < sz; k++) 
 			ports.push_back(low + k);
-		random_shuffle(ports.begin(), ports.end());
+		std::shuffle(ports.begin(), ports.end(), g);
 		*port = ports[curr++];
 	} else 
 		*port = ports[curr++];
