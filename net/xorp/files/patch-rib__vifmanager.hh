--- rib/vifmanager.hh.orig	2012-01-11 17:56:10 UTC
+++ rib/vifmanager.hh
@@ -110,6 +110,9 @@ public:
      */
     int		final_stop();
 
+    XrlRouter&		_xrl_router;
+    EventLoop&		_eventloop;
+
 protected:
     //
     // IfMgrHintObserver methods
@@ -163,8 +166,8 @@ private:
      */
     int ifmgr_shutdown();
 
-    XrlRouter&		_xrl_router;
-    EventLoop&		_eventloop;
+    // XrlRouter&		_xrl_router;
+    // EventLoop&		_eventloop;
     RibManager*		_rib_manager;
 
     IfMgrXrlMirror	_ifmgr;
