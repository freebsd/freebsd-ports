--- src/ndisc.c.orig    2011-09-10 14:17:49.714181834 +0400
+++ src/ndisc.c 2011-09-10 14:17:51.893973268 +0400
@@ -441,7 +441,7 @@
 		printf (_("Stateful other conf.      :          %3s\n"),
 		        gettext ((v & ND_RA_FLAG_OTHER) ? N_ ("Yes") : N_("No")));
 		printf (_("Mobile home agent         :          %3s\n"),
-		        gettext ((v & ND_RA_FLAG_HOME_AGENT) ? N_ ("Yes") : N_("No")));
+		        gettext ((v & ND_RA_FLAG_HA) ? N_ ("Yes") : N_("No")));
 		printf (_("Router preference         :       %6s\n"), pref_i2n (v));
 		printf (_("Neighbor discovery proxy  :          %3s\n"),
 		        gettext ((v & 0x04) ? N_ ("Yes") : N_("No")));
