--- mozilla/dom/events/MessageEvent.h.orig	2015-12-21 23:33:03.000000000 +0100
+++ mozilla/dom/events/MessageEvent.h	2016-01-23 23:42:54.823166000 +0100
@@ -15,9 +15,6 @@ namespace mozilla {
 namespace dom {
 
 struct MessageEventInit;
-class MessagePort;
-class MessagePortBase;
-class MessagePortList;
 class OwningWindowProxyOrMessagePort;
 
 /**
