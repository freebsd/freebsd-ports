--- pcapsource.cc.orig	Wed Jun 22 08:22:23 2005
+++ pcapsource.cc	Wed Jul  6 18:37:03 2005
@@ -610,9 +610,6 @@
                 (bit0 + BITNO_32(present ^ next_present));
 
             switch (bit) {
-                case IEEE80211_RADIOTAP_FCS:
-					fcs_cut = 4;
-                    break;
                 case IEEE80211_RADIOTAP_FLAGS:
                 case IEEE80211_RADIOTAP_RATE:
                 case IEEE80211_RADIOTAP_DB_ANTSIGNAL:
@@ -678,6 +675,10 @@
                 case IEEE80211_RADIOTAP_DB_ANTNOISE:
                     packet->noise = u.i8;
                     break;
+		case IEEE80211_RADIOTAP_FLAGS:
+		    if (u.u8 & IEEE80211_RADIOTAP_F_FCS)
+	                 fcs_cut = 4;
+		    break;
 #if 0
                 case IEEE80211_RADIOTAP_FHSS:
                     printf("fhset %d fhpat %d ", u.u16 & 0xff,
