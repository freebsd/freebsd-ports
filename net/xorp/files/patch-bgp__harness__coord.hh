--- ./bgp/harness/coord.hh.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./bgp/harness/coord.hh	2014-02-26 21:17:13.000000000 +0000
@@ -42,7 +42,9 @@
 
 private:
     bool _done;
+public:
     EventLoop& _eventloop;
+private:
     Command& _command;
 };
 
