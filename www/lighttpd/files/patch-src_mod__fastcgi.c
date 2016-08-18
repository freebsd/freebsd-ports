--- src/mod_fastcgi.c.orig	2016-08-07 17:19:10 UTC
+++ src/mod_fastcgi.c
@@ -3257,7 +3257,8 @@ SUBREQUEST_FUNC(mod_fastcgi_handle_subre
 		}
 	}
 
-	return (0 == hctx->wb->bytes_in || !chunkqueue_is_empty(hctx->wb))
+	return ((0 == hctx->wb->bytes_in || !chunkqueue_is_empty(hctx->wb))
+		&& hctx->state != FCGI_STATE_CONNECT_DELAYED)
 	  ? fcgi_send_request(srv, hctx)
 	  : HANDLER_WAIT_FOR_EVENT;
 }
