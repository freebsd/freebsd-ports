
$FreeBSD$

--- sip/b2b/AAATransceiver.hxx	2003/01/18 23:09:49	1.1
+++ sip/b2b/AAATransceiver.hxx	2003/01/18 23:10:07
@@ -61,8 +61,9 @@
 #include "VThread.hxx"
 #include "AAAEvent.hxx"
 #include "RadiusMessage.hxx"
+#include "UdpStack.hxx"
 
-class UdpStack;
+//class UdpStack;
 
 using Vocal::Fifo;
 
