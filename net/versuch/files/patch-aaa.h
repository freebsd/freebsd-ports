--- Aaa.h.orig	2008-01-15 13:56:51.000000000 +0000
+++ Aaa.h	2008-01-15 13:57:41.000000000 +0000
@@ -95,7 +95,7 @@
 class TCDR
 {
 public:
- TCDR::TCDR() { DisconnectCause = 0; StartTime = 0; StopTime = 0; };
+ TCDR() { DisconnectCause = 0; StartTime = 0; StopTime = 0; };
  unsigned int CallRef;
  unsigned int StartTime, StopTime, IncOctets, OutOctets, RouteRetries;
  int FastStart, Tunneling;
