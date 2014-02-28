--- ./fea/fibconfig.hh.orig	2012-01-11 17:46:45.000000000 +0000
+++ ./fea/fibconfig.hh	2014-02-26 21:17:13.000000000 +0000
@@ -736,12 +736,14 @@
      */
     Trie6& trie6() { return _trie6; }
 
+    FeaNode&				_fea_node;
+
 protected:
     Trie4	_trie4;		// IPv4 trie (used for testing purpose)
     Trie6	_trie6;		// IPv6 trie (used for testing purpose)
     
 private:
-    FeaNode&				_fea_node;
+    // FeaNode&				_fea_node;
     EventLoop&				_eventloop;
 #ifndef XORP_DISABLE_PROFILE
     Profile&				_profile;
