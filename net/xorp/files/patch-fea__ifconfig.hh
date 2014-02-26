--- ./fea/ifconfig.hh.orig	2011-03-16 21:27:49.000000000 +0000
+++ ./fea/ifconfig.hh	2014-02-26 21:17:13.000000000 +0000
@@ -442,6 +442,8 @@
      */
     void report_updates(IfTree& iftree);
 
+    FeaNode&			_fea_node;
+
 private:
     /**
      * Restore the interface configuration.
@@ -455,7 +457,7 @@
 		       const IfTree& old_system_config,
 		       string& error_msg);
 
-    FeaNode&			_fea_node;
+    // FeaNode&			_fea_node;
     EventLoop&			_eventloop;
     NexthopPortMapper&		_nexthop_port_mapper;
     IfConfigTransactionManager* _itm;	// The interface transaction manager
