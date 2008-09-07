--- talk/xmpp/xmppclient.h.orig	2008-09-06 23:26:42.000000000 -0300
+++ talk/xmpp/xmppclient.h	2008-09-06 23:27:04.000000000 -0300
@@ -138,7 +138,7 @@
     }
   }
 
-  std::string XmppClient::GetStateName(int state) const {
+  std::string GetStateName(int state) const {
     switch (state) {
       case STATE_PRE_XMPP_LOGIN:      return "PRE_XMPP_LOGIN";
       case STATE_START_XMPP_LOGIN:  return "START_XMPP_LOGIN";
