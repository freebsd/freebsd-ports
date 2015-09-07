--- fea/mfea_mrouter.hh.orig	2012-01-11 17:56:10 UTC
+++ fea/mfea_mrouter.hh
@@ -437,6 +437,8 @@ private:
     // Original state from the underlying system before the MFEA was started
     //
     bool	_multicast_forwarding_enabled;
+
+public:
     const FibConfig& _fibconfig;
 };
 
