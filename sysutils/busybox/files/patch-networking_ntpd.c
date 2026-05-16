--- networking/ntpd.c.orig	2026-05-16 19:33:15 UTC
+++ networking/ntpd.c
@@ -1645,7 +1645,7 @@ update_local_clock(peer_t *p)
 	/* 65536 is one ppm */
 	tmx.freq = G.discipline_freq_drift * 65536e6;
 #endif
-	tmx.modes = ADJ_OFFSET | ADJ_STATUS | ADJ_TIMECONST | ADJ_MAXERROR | ADJ_ESTERROR;
+	tmx.modes = ADJ_OFFSET | ADJ_STATUS | ADJ_TIMECONST; // | ADJ_MAXERROR | ADJ_ESTERROR;
 
 	tmx.offset = (long)(offset * 1000000); /* usec */
 	if (SLEW_THRESHOLD < STEP_THRESHOLD) {
