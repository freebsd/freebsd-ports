--- mozilla/dom/events/MessageEvent.h.orig	2015-11-04 02:56:28.000000000 +0100
+++ mozilla/dom/events/MessageEvent.h	2016-01-24 16:47:37.869781000 +0100
@@ -16,9 +16,6 @@ namespace mozilla {
 namespace dom {
 
 struct MessageEventInit;
-class MessagePort;
-class MessagePortBase;
-class MessagePortList;
 class OwningWindowProxyOrMessagePortOrClient;
 
 namespace workers {
