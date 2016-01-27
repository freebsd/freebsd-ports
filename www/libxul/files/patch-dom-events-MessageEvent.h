--- dom/events/MessageEvent.h.orig	2015-12-22 00:49:29.000000000 +0100
+++ dom/events/MessageEvent.h	2016-01-17 14:44:08.806122000 +0100
@@ -15,9 +15,6 @@ namespace mozilla {
 namespace dom {
 
 struct MessageEventInit;
-class MessagePort;
-class MessagePortBase;
-class MessagePortList;
 class OwningWindowProxyOrMessagePort;
 
 /**
