--- jit/jit/wp_client.cpp	Tue Jul  6 18:58:45 2004
+++ jit/jit/wp_client.cpp	Tue Jul  6 18:55:31 2004
@@ -146,7 +146,8 @@
 }
 
 void WPclient::SignalDisconnected(DisconnectedEvent *ev) {
-  terror e = (terror){0,""};
+  terror e;
+  e = (terror){0,""};
   
   switch(ev->getReason()){
   case DisconnectedEvent::FAILED_BADUSERNAME:
