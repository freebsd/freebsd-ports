--- ./rib/vifmanager.hh.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./rib/vifmanager.hh	2014-02-26 21:17:13.000000000 +0000
@@ -110,6 +110,9 @@
      */
     int		final_stop();
 
+    XrlRouter&		_xrl_router;
+    EventLoop&		_eventloop;
+
 protected:
     //
     // IfMgrHintObserver methods
@@ -163,8 +166,8 @@
      */
     int ifmgr_shutdown();
 
-    XrlRouter&		_xrl_router;
-    EventLoop&		_eventloop;
+    // XrlRouter&		_xrl_router;
+    // EventLoop&		_eventloop;
     RibManager*		_rib_manager;
 
     IfMgrXrlMirror	_ifmgr;
