--- fea/data_plane/fibconfig/fibconfig_table_observer_rtmv2.hh.orig	2012-01-11 17:56:10 UTC
+++ fea/data_plane/fibconfig/fibconfig_table_observer_rtmv2.hh
@@ -73,15 +73,15 @@ public:
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
 
