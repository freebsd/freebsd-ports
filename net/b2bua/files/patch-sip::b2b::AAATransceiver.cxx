
$FreeBSD$

--- sip/b2b/AAATransceiver.cxx	2003/01/18 06:18:49	1.1
+++ sip/b2b/AAATransceiver.cxx	2003/01/18 06:19:07
@@ -52,6 +52,7 @@
 static const char* const AAATransceiver_cxx_Version =
     "$Id: AAATransceiver.cxx,v 1.1 2003/01/18 06:18:49 root Exp root $";
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
