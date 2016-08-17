--- src/mod_proxy.c.orig	2016-07-31 12:42:39 UTC
+++ src/mod_proxy.c
@@ -854,7 +854,20 @@ static handler_t proxy_write_request(ser
 
 		if (hctx->wb->bytes_out == hctx->wb_reqlen) {
 			fdevent_event_clr(srv->ev, &(hctx->fde_ndx), hctx->fd, FDEVENT_OUT);
-			shutdown(hctx->fd, SHUT_WR);/* future: remove if HTTP/1.1 request */
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
+				shutdown(hctx->fd, SHUT_WR);/* future: remove if HTTP/1.1 request */
+			}
+		      #endif
 			proxy_set_state(srv, hctx, PROXY_STATE_READ);
 		} else {
 			off_t wblen = hctx->wb->bytes_in - hctx->wb->bytes_out;
@@ -992,7 +1005,8 @@ SUBREQUEST_FUNC(mod_proxy_handle_subrequ
 		}
 	}
 
-	return (0 == hctx->wb->bytes_in || !chunkqueue_is_empty(hctx->wb))
+	return ((0 == hctx->wb->bytes_in || !chunkqueue_is_empty(hctx->wb))
+		&& hctx->state != PROXY_STATE_CONNECT)
 	  ? proxy_send_request(srv, hctx)
 	  : HANDLER_WAIT_FOR_EVENT;
 }
