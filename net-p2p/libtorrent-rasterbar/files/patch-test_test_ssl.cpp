From c8f3063f25ab0c90998b08711a7ecf2eed5677ba Mon Sep 17 00:00:00 2001
From: arvidn <arvid@libtorrent.org>
Date: Mon, 14 Oct 2019 12:35:17 +0200
Subject: [PATCH] fix SSL test

---
 test/test_ssl.cpp | 14 ++++++++++++--
 1 file changed, 12 insertions(+), 2 deletions(-)

diff --git a/test/test_ssl.cpp b/test/test_ssl.cpp
index 63a1ae75fa..47f713c737 100644
--- test/test_ssl.cpp
+++ test/test_ssl.cpp
@@ -101,7 +101,12 @@ bool on_alert(alert const* a)
 	if (peer_disconnected_alert const* e = alert_cast<peer_disconnected_alert>(a))
 	{
 		++peer_disconnects;
-		if (strcmp(e->error.category().name(), boost::asio::error::get_ssl_category().name()) == 0)
+		string_view const cat = e->error.category().name();
+		if (cat == boost::asio::error::get_ssl_category().name()
+#if BOOST_VERSION >= 106400
+			|| cat == boost::asio::ssl::error::get_stream_category().name()
+#endif
+			)
 			++ssl_peer_disconnects;
 
 		std::printf("--- peer_errors: %d ssl_disconnects: %d\n"
@@ -113,7 +118,12 @@ bool on_alert(alert const* a)
 		++peer_disconnects;
 		++peer_errors;
 
-		if (strcmp(e->error.category().name(), boost::asio::error::get_ssl_category().name()) == 0)
+		string_view const cat = e->error.category().name();
+		if (cat == boost::asio::error::get_ssl_category().name()
+#if BOOST_VERSION >= 106400
+			|| cat == boost::asio::ssl::error::get_stream_category().name()
+#endif
+			)
 			++ssl_peer_disconnects;
 
 		std::printf("--- peer_errors: %d ssl_disconnects: %d\n"
