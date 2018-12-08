--- src/ndisc.c.orig	2014-12-14 10:39:28 UTC
+++ src/ndisc.c
@@ -532,7 +532,7 @@ parseadv (const uint8_t *buf, size_t len
 		printf (_("Stateful other conf.      :          %3s\n"),
 		        gettext ((v & ND_RA_FLAG_OTHER) ? N_ ("Yes") : N_("No")));
 		printf (_("Mobile home agent         :          %3s\n"),
-		        gettext ((v & ND_RA_FLAG_HOME_AGENT) ? N_ ("Yes") : N_("No")));
+		        gettext ((v & ND_RA_FLAG_HA) ? N_ ("Yes") : N_("No")));
 		printf (_("Router preference         :       %6s\n"), pref_i2n (v));
 		printf (_("Neighbor discovery proxy  :          %3s\n"),
 		        gettext ((v & 0x04) ? N_ ("Yes") : N_("No")));
