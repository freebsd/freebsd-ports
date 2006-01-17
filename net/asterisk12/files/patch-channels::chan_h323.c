
$FreeBSD$

--- channels/chan_h323.c.orig	Tue Nov 29 20:24:39 2005
+++ channels/chan_h323.c	Thu Jan 12 18:29:50 2006
@@ -2281,7 +2281,7 @@ static char *convertcap(int cap)
 	}
 }
 
-static int oh323_set_rtp_peer(struct ast_channel *chan, struct ast_rtp *rtp, struct ast_rtp *vrtp, int codecs)
+static int oh323_set_rtp_peer(struct ast_channel *chan, struct ast_rtp *rtp, struct ast_rtp *vrtp, int codecs, int nat_active)
 {
 	/* XXX Deal with Video */
 	struct oh323_pvt *pvt;
