--- fea/tools/show_interfaces.hh.orig	2012-01-11 17:56:10 UTC
+++ fea/tools/show_interfaces.hh
@@ -79,6 +79,8 @@ public:
      */
     void print_interfaces(const string& print_iface_name) const;
 
+    EventLoop&		_eventloop;
+
 protected:
     //
     // IfMgrHintObserver methods
@@ -132,7 +134,7 @@ private:
      */
     int ifmgr_shutdown();
 
-    EventLoop&		_eventloop;
+    // EventLoop&		_eventloop;
 
     IfMgrXrlMirror	_ifmgr;
 
