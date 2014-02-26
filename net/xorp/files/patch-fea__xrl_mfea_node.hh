--- ./fea/xrl_mfea_node.hh.orig	2011-03-16 21:27:49.000000000 +0000
+++ ./fea/xrl_mfea_node.hh	2014-02-26 21:17:13.000000000 +0000
@@ -504,6 +504,8 @@
 	// Input values,
 	const bool&	enable);
 
+    EventLoop&			_eventloop;
+
 private:
     /**
      * Called when Finder connection is established.
@@ -570,7 +572,7 @@
     
     int family() const { return (MfeaNode::family()); }
 
-    EventLoop&			_eventloop;
+    // EventLoop&			_eventloop;
     const string		_finder_target;
 
     XrlMfeaClientV0p1Client	_xrl_mfea_client_client;
