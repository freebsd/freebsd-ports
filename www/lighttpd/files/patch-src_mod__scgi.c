--- src/mod_scgi.c.orig	2016-08-07 12:39:31 UTC
+++ src/mod_scgi.c
@@ -2438,7 +2438,20 @@ static handler_t scgi_write_request(serv
 
 		if (hctx->wb->bytes_out == hctx->wb_reqlen) {
 			fdevent_event_clr(srv->ev, &(hctx->fde_ndx), hctx->fd, FDEVENT_OUT);
-			shutdown(hctx->fd, SHUT_WR);
+		      #if (defined(__APPLE__) && defined(__MACH__)) \
+			|| defined(__FreeBSD__) || defined(__NetBSD__) \
+			|| defined(__OpenBSD__) || defined(__DragonflyBSD__)
+			/*(*BSD stack on remote might signal POLLHUP and remote
+			 * might treat as socket error instead of half-close)*/
+		      #else
+			/*(remote could be different machine running affected OS,
+			 * so only issue shutdown for known local sockets)*/
+			if ( '/' == host->host->ptr[0]
+			    || buffer_is_equal_string(host->host, CONST_STR_LEN("127.0.0.1"))
+			    || buffer_is_equal_string(host->host, CONST_STR_LEN("::1"))) {
+				shutdown(hctx->fd, SHUT_WR);
+			}
+		      #endif
 			scgi_set_state(srv, hctx, FCGI_STATE_READ);
 		} else {
 			off_t wblen = hctx->wb->bytes_in - hctx->wb->bytes_out;
@@ -2585,7 +2598,8 @@ SUBREQUEST_FUNC(mod_scgi_handle_subreque
 		}
 	}
 
-	return (0 == hctx->wb->bytes_in || !chunkqueue_is_empty(hctx->wb))
+	return ((0 == hctx->wb->bytes_in || !chunkqueue_is_empty(hctx->wb))
+		&& hctx->state != FCGI_STATE_CONNECT)
 	  ? scgi_send_request(srv, hctx)
 	  : HANDLER_WAIT_FOR_EVENT;
 }
