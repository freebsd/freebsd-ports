https://github.com/domoticz/domoticz/commit/388c7b51716c

--- webserver/server.cpp.orig	2017-07-30 10:19:41 UTC
+++ webserver/server.cpp
@@ -148,7 +148,7 @@ void server::handle_accept(const boost::system::error_
 ssl_server::ssl_server(const ssl_server_settings & ssl_settings, request_handler & user_request_handler) :
 		server_base(ssl_settings, user_request_handler),
 		settings_(ssl_settings),
-		context_(io_service_, ssl_settings.get_ssl_method())
+		context_(ssl_settings.get_ssl_method())
 {
 #ifdef DEBUG_WWW
 	_log.Log(LOG_STATUS, "[web:%s] create ssl_server using ssl_server_settings : %s", ssl_settings.listening_port.c_str(), ssl_settings.to_string().c_str());
@@ -161,7 +161,7 @@ ssl_server::ssl_server(const ssl_server_settings & ssl
 ssl_server::ssl_server(const server_settings & settings, request_handler & user_request_handler) :
 		server_base(settings, user_request_handler),
 		settings_(dynamic_cast<ssl_server_settings const &>(settings)),
-		context_(io_service_, dynamic_cast<ssl_server_settings const &>(settings).get_ssl_method()) {
+		context_(dynamic_cast<ssl_server_settings const &>(settings).get_ssl_method()) {
 #ifdef DEBUG_WWW
 	_log.Log(LOG_STATUS, "[web:%s] create ssl_server using server_settings : %s", settings.listening_port.c_str(), settings.to_string().c_str());
 #endif
