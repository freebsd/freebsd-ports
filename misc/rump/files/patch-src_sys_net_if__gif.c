--- src/sys/net/if_gif.c.orig	2017-09-26 10:05:48 UTC
+++ src/sys/net/if_gif.c
@@ -192,7 +192,8 @@ gifattach0(struct gif_softc *sc)
 
 	sc->gif_if.if_addrlen = 0;
 	sc->gif_if.if_mtu    = GIF_MTU;
-	sc->gif_if.if_flags  = IFF_POINTOPOINT | IFF_MULTICAST;
+	int tmp = IFF_POINTOPOINT | IFF_MULTICAST;
+	sc->gif_if.if_flags  = tmp;
 	sc->gif_if.if_extflags  = IFEF_NO_LINK_STATE_CHANGE;
 	sc->gif_if.if_ioctl  = gif_ioctl;
 	sc->gif_if.if_output = gif_output;
