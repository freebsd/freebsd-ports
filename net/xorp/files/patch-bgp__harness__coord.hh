--- bgp/harness/coord.hh.orig	2012-01-11 17:56:10 UTC
+++ bgp/harness/coord.hh
@@ -42,7 +42,9 @@ public:
 
 private:
     bool _done;
+public:
     EventLoop& _eventloop;
+private:
     Command& _command;
 };
 
