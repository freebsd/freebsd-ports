--- ntpd/ntp_proto.c.orig	2024-05-07 04:21:28.000000000 -0700
+++ ntpd/ntp_proto.c	2024-12-23 14:40:06.218503000 -0800
@@ -471,6 +471,7 @@
 		return;
 	}
 
+#if 0
 	/* [Bug 3851] drop pool servers which can no longer be reached. */
 	if (MDF_PCLNT & peer->cast_flags) {
 		if (   (IS_IPV6(&peer->srcadr) && !nonlocal_v6_addr_up)
@@ -479,6 +480,7 @@
 			return;
 		}
 	}
+#endif
 
 	 /*
 	 * In unicast modes the dance is much more intricate. It is
