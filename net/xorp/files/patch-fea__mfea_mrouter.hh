--- ./fea/mfea_mrouter.hh.orig	2011-03-16 21:27:49.000000000 +0000
+++ ./fea/mfea_mrouter.hh	2014-02-26 21:17:13.000000000 +0000
@@ -437,6 +437,8 @@
     // Original state from the underlying system before the MFEA was started
     //
     bool	_multicast_forwarding_enabled;
+
+public:
     const FibConfig& _fibconfig;
 };
 
