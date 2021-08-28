--- src/providers/twitch/PubsubClient.cpp.orig	2021-05-21 15:21:21 UTC
+++ src/providers/twitch/PubsubClient.cpp
@@ -803,7 +803,11 @@ PubSub::PubSub()
         // qCDebug(chatterinoPubsub) << QString::fromStdString(rj::stringify(data));
     };
 
+#ifdef DEBUG_OFF
+    this->websocketClient.set_access_channels(websocketpp::log::alevel::none);
+#else
     this->websocketClient.set_access_channels(websocketpp::log::alevel::all);
+#endif
     this->websocketClient.clear_access_channels(
         websocketpp::log::alevel::frame_payload);
 
