--- dom/events/MessageEvent.h.orig	2015-12-22 00:49:29.000000000 +0100
+++ dom/events/MessageEvent.h	2016-01-24 16:05:27.439512000 +0100
@@ -15,9 +15,6 @@ namespace mozilla {
 namespace dom {
 
 struct MessageEventInit;
-class MessagePort;
-class MessagePortBase;
-class MessagePortList;
 class OwningWindowProxyOrMessagePort;
 
 /**
