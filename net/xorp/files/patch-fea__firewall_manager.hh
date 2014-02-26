--- ./fea/firewall_manager.hh.orig	2011-03-16 21:27:49.000000000 +0000
+++ ./fea/firewall_manager.hh	2014-02-26 21:17:13.000000000 +0000
@@ -313,6 +313,8 @@
      */
     void delete_browse_state(uint32_t token);
 
+    FeaNode&				_fea_node;
+
 private:
     /**
      * Update the firewall entries by pushing them into the underlying system.
@@ -364,7 +366,7 @@
      */
     void generate_token();
 
-    FeaNode&				_fea_node;
+    // FeaNode&				_fea_node;
     EventLoop&				_eventloop;
     const IfTree&			_iftree;
 
