--- ./src/Network/XMPP/Types.hs.orig	2013-07-05 10:53:16.000000000 +0800
+++ ./src/Network/XMPP/Types.hs	2013-07-05 10:53:56.000000000 +0800
@@ -139,9 +139,6 @@
 
 data ShowType = Available | Away | FreeChat | DND | XAway deriving Eq
 
-instance Show (Content a) where
-  show = render . P.content
-
 instance Show MessageType where
   show Chat = "chat"
   show GroupChat = "groupchat"
