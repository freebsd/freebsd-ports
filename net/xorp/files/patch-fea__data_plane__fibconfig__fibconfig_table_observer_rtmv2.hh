--- ./fea/data_plane/fibconfig/fibconfig_table_observer_rtmv2.hh.orig	2011-03-16 21:16:02.000000000 +0000
+++ ./fea/data_plane/fibconfig/fibconfig_table_observer_rtmv2.hh	2014-02-26 21:17:13.000000000 +0000
@@ -73,15 +73,15 @@
 private:
     class RtmV2Observer : public WinRtmPipeObserver {
     public:
-    	RtmV2Observer(WinRtmPipe& rs, int af,
+    	RtmV2Observer(WinRtmPipe& rs, /* int af, */
 		      FibConfigTableObserverRtmV2& rtmo)
-	    : WinRtmPipeObserver(rs), _af(af), _rtmo(rtmo) {}
+	    : WinRtmPipeObserver(rs), /* _af(af), */ _rtmo(rtmo) {}
     	virtual ~RtmV2Observer() {}
 	void routing_socket_data(const vector<uint8_t>& buffer) {
 	    _rtmo.receive_data(buffer);
 	}
     private:
-	int _af;
+	// int _af;
     	FibConfigTableObserverRtmV2& _rtmo;
     };
 
