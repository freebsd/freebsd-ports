--- lib/system/ktls.c.orig	2025-04-11 11:51:08 UTC
+++ lib/system/ktls.c
@@ -1076,6 +1076,7 @@ int _gnutls_ktls_recv_control_msg(gnutls_session_t ses
 		default:
 			return GNUTLS_E_PULL_ERROR;
 		}
+#ifdef EKEYEXPIRED
 	} else if (unlikely(ret == -EKEYEXPIRED)) {
 		/* This will be received until a keyupdate is performed on the
 		   scoket. */
@@ -1083,6 +1084,7 @@ int _gnutls_ktls_recv_control_msg(gnutls_session_t ses
 				  "updated keys\n");
 		gnutls_assert();
 		return GNUTLS_E_AGAIN;
+#endif
 	}
 
 	/* connection closed */
