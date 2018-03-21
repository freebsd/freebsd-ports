--- libfreerdp/core/nla.c.orig	2018-03-21 03:26:15 UTC
+++ libfreerdp/core/nla.c
@@ -1663,14 +1663,18 @@ BOOL nla_send(rdpNla* nla)
 static int nla_decode_ts_request(rdpNla* nla, wStream* s)
 {
 	int length;
+	UINT32 version = 0;
 
 	/* TSRequest */
 	if (!ber_read_sequence_tag(s, &length) ||
 	    !ber_read_contextual_tag(s, 0, &length, TRUE) ||
-	    !ber_read_integer(s, &nla->version))
+	    !ber_read_integer(s, &version))
 	{
 		return -1;
 	}
+
+	if (version < nla->version)
+		nla->version = version;
 
 	/* [1] negoTokens (NegoData) */
 	if (ber_read_contextual_tag(s, 1, &length, TRUE) != FALSE)
