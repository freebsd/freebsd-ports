--- fea/firewall_manager.hh.orig	2012-01-11 17:56:10 UTC
+++ fea/firewall_manager.hh
@@ -313,6 +313,8 @@ public:
      */
     void delete_browse_state(uint32_t token);
 
+    FeaNode&				_fea_node;
+
 private:
     /**
      * Update the firewall entries by pushing them into the underlying system.
@@ -364,7 +366,7 @@ private:
      */
     void generate_token();
 
-    FeaNode&				_fea_node;
+    // FeaNode&				_fea_node;
     EventLoop&				_eventloop;
     const IfTree&			_iftree;
 
