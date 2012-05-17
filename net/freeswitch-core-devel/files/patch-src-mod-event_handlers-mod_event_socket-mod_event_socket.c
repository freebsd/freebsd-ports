--- src/mod/event_handlers/mod_event_socket/mod_event_socket.c
+++ src/mod/event_handlers/mod_event_socket/mod_event_socket.c
@@ -1356,16 +1356,16 @@ static switch_status_t read_packet(listener_t *listener, switch_event_t **event,
 			if (switch_test_flag(listener, LFLAG_LINGER)) {
 				char disco_buf[512] = "";
 				
-				switch_log_printf(SWITCH_CHANNEL_SESSION_LOG(listener->session), SWITCH_LOG_DEBUG, "%s Socket Linger %"TIME_T_FMT"\n", 
-								  switch_channel_get_name(channel), listener->linger_timeout);
+				switch_log_printf(SWITCH_CHANNEL_SESSION_LOG(listener->session), SWITCH_LOG_DEBUG, "%s Socket Linger %d\n", 
+								  switch_channel_get_name(channel), (int)listener->linger_timeout);
 				
 				switch_snprintf(disco_buf, sizeof(disco_buf), "Content-Type: text/disconnect-notice\n"
 								"Controlled-Session-UUID: %s\n"
 								"Content-Disposition: linger\n" 
 								"Channel-Name: %s\n"
-								"Linger-Time: %"TIME_T_FMT"\n"
+								"Linger-Time: %d\n"
 								"Content-Length: 0\n\n", 
-								switch_core_session_get_uuid(listener->session), switch_channel_get_name(channel), listener->linger_timeout);
+								switch_core_session_get_uuid(listener->session), switch_channel_get_name(channel), (int)listener->linger_timeout);
 
 
 				if (listener->linger_timeout != (time_t) -1) {

