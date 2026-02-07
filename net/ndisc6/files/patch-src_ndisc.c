--- src/ndisc.c.orig	2023-11-10 15:28:07 UTC
+++ src/ndisc.c
@@ -451,7 +451,7 @@ parsednssl (const uint8_t *opt)
 parsednssl (const uint8_t *opt)
 {
 	const uint8_t *base;
-	uint8_t optlen = opt[1];
+	uint16_t optlen = opt[1];
 	if (optlen < 2)
 		return -1;
 
@@ -559,7 +559,7 @@ parseadv (const uint8_t *buf, size_t len, const struct
 		printf (_("Stateful other conf.      :          %3s\n"),
 		        gettext ((v & ND_RA_FLAG_OTHER) ? N_ ("Yes") : N_("No")));
 		printf (_("Mobile home agent         :          %3s\n"),
-		        gettext ((v & ND_RA_FLAG_HOME_AGENT) ? N_ ("Yes") : N_("No")));
+		        gettext ((v & ND_RA_FLAG_HA) ? N_ ("Yes") : N_("No")));
 		printf (_("Router preference         :       %6s\n"), pref_i2n (v));
 		printf (_("Neighbor discovery proxy  :          %3s\n"),
 		        gettext ((v & 0x04) ? N_ ("Yes") : N_("No")));
