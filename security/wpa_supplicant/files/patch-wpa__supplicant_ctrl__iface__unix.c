--- wpa_supplicant/ctrl_iface_unix.c.orig	2024-07-20 18:04:37 UTC
+++ wpa_supplicant/ctrl_iface_unix.c
@@ -509,6 +509,10 @@ static int wpas_ctrl_iface_open_sock(struct wpa_suppli
 	struct group *grp;
 	char *endp;
 	int flags;
+#if defined(__FreeBSD__)
+	int optval, rc;
+	socklen_t optlen;
+#endif
 
 	buf = os_strdup(wpa_s->conf->ctrl_interface);
 	if (buf == NULL)
@@ -681,6 +685,22 @@ havesock:
 			/* Not fatal, continue on.*/
 		}
 	}
+
+#if defined(__FreeBSD__)
+	/* Ensure we can send a full length message atomically. */
+	optval = 0;
+	optlen = sizeof(optval);
+	if (getsockopt(priv->sock, SOL_SOCKET, SO_SNDBUF, &optval, &optlen) == -1) {
+		wpa_printf(MSG_INFO, "failed to get sndbuf for sock=%d: %s",
+			   priv->sock, strerror(errno));
+	} else if (optval < CTRL_IFACE_MAX_LEN) {
+		optval = CTRL_IFACE_MAX_LEN;
+		if (setsockopt(priv->sock, SOL_SOCKET, SO_SNDBUF, &optval,
+			       sizeof(optval)) == -1)
+			wpa_printf(MSG_ERROR, "failed to set sndbuf for "
+				   "sock=%d: %s", priv->sock, strerror(errno));
+	}
+#endif
 
 	eloop_register_read_sock(priv->sock, wpa_supplicant_ctrl_iface_receive,
 				 wpa_s, priv);
