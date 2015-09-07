--- fea/xrl_mfea_node.hh.orig	2012-01-11 17:56:10 UTC
+++ fea/xrl_mfea_node.hh
@@ -504,6 +504,8 @@ protected:
 	// Input values,
 	const bool&	enable);
 
+    EventLoop&			_eventloop;
+
 private:
     /**
      * Called when Finder connection is established.
@@ -570,7 +572,7 @@ private:
     
     int family() const { return (MfeaNode::family()); }
 
-    EventLoop&			_eventloop;
+    // EventLoop&			_eventloop;
     const string		_finder_target;
 
     XrlMfeaClientV0p1Client	_xrl_mfea_client_client;
