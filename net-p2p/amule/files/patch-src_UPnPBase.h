--- src/UPnPBase.h.orig	2016-09-16 07:55:07 UTC
+++ src/UPnPBase.h
@@ -489,9 +489,15 @@ public:
 
 	// Callback function
 	static int Callback(
+#if UPNP_VERSION >= 10800
+		Upnp_EventType_e EventType,
+		const void *Event,
+		void *Cookie);
+#else
 		Upnp_EventType EventType,
 		void* Event,
 		void* Cookie);
+#endif
 
 private:
 	void OnEventReceived(
