--- ./fea/tools/show_interfaces.hh.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./fea/tools/show_interfaces.hh	2014-02-26 21:17:13.000000000 +0000
@@ -79,6 +79,8 @@
      */
     void print_interfaces(const string& print_iface_name) const;
 
+    EventLoop&		_eventloop;
+
 protected:
     //
     // IfMgrHintObserver methods
@@ -132,7 +134,7 @@
      */
     int ifmgr_shutdown();
 
-    EventLoop&		_eventloop;
+    // EventLoop&		_eventloop;
 
     IfMgrXrlMirror	_ifmgr;
 
