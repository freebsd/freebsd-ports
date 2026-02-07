--- wpa_supplicant/ctrl_iface_unix.c.orig	2022-01-16 12:51:29.000000000 -0800
+++ wpa_supplicant/ctrl_iface_unix.c	2023-11-29 08:12:07.843443000 -0800
@@ -506,6 +506,10 @@
 	struct group *grp;
 	char *endp;
 	int flags;
+#if defined(__FreeBSD__)
+	int optval, rc;
+	socklen_t optlen;
+#endif
 
 	buf = os_strdup(wpa_s->conf->ctrl_interface);
 	if (buf == NULL)
@@ -678,6 +682,22 @@
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
