--- a/dump-vlc-m3u.c
+++ b/dump-vlc-m3u.c
@@ -488,11 +488,11 @@ void vlc_dump_dvb_parameters_as_xspf (FI
 		switch (p->u.qpsk.polarization) {
 			case POLARIZATION_HORIZONTAL:
 			case POLARIZATION_CIRCULAR_LEFT:
-				fprintf (f, "dvb-voltage=18,\n");
+				fprintf (f, "voltage=18,");
 				break;
 			default:
-				fprintf (f, "dvb-voltage=13,\n");
-				break;				
+				fprintf (f, "voltage=13,");
+				break;
 			}
 		fprintf (f, "tone=%i", p->frequency >= lnbp->switch_val);
 
