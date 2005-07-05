--- pcapsource.cc.orig	Wed Jun 22 08:22:23 2005
+++ pcapsource.cc	Sun Jul  3 22:44:22 2005
@@ -610,7 +610,7 @@
                 (bit0 + BITNO_32(present ^ next_present));
 
             switch (bit) {
-                case IEEE80211_RADIOTAP_FCS:
+                case IEEE80211_RADIOTAP_F_FCS:
 					fcs_cut = 4;
                     break;
                 case IEEE80211_RADIOTAP_FLAGS:
