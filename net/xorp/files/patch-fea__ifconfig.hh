--- fea/ifconfig.hh.orig	2012-01-11 17:56:10 UTC
+++ fea/ifconfig.hh
@@ -442,6 +442,8 @@ public:
      */
     void report_updates(IfTree& iftree);
 
+    FeaNode&			_fea_node;
+
 private:
     /**
      * Restore the interface configuration.
@@ -455,7 +457,7 @@ private:
 		       const IfTree& old_system_config,
 		       string& error_msg);
 
-    FeaNode&			_fea_node;
+    // FeaNode&			_fea_node;
     EventLoop&			_eventloop;
     NexthopPortMapper&		_nexthop_port_mapper;
     IfConfigTransactionManager* _itm;	// The interface transaction manager
