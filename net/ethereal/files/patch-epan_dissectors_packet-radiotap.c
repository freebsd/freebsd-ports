--- epan/dissectors/packet-radiotap.c.orig	Mon Apr 17 14:46:52 2006
+++ epan/dissectors/packet-radiotap.c	Fri Apr 28 19:21:24 2006
@@ -382,7 +382,7 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
     proto_item *ti = NULL;
     int offset;
     guint32 version, pad;
-    guint32 length;
+    guint length, length_remaining;
     guint32 rate, freq, flags;
     gint8 dbm;
     guint8 db, rflags;
@@ -416,11 +416,13 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
 	ti = proto_tree_add_uint(radiotap_tree, hf_radiotap_length,
 	    tvb, offset + 2, 2, length);
     }
+    length_remaining = length;
+
     /*
      * FIXME: This only works if there is exactly 1 it_present
      *        field in the header
      */
-    if (length < sizeof(struct ieee80211_radiotap_header)) {
+    if (length_remaining < sizeof(struct ieee80211_radiotap_header)) {
 	/*
 	 * Radiotap header is shorter than the fixed-length portion
 	 * plus one "present" bitset.
@@ -435,7 +437,7 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
 	present_tree = proto_item_add_subtree(pt, ett_radiotap_present);
     }
     offset += sizeof(struct ieee80211_radiotap_header);
-    length -= sizeof(struct ieee80211_radiotap_header);
+    length_remaining -= sizeof(struct ieee80211_radiotap_header);
 
     rflags = 0;
     for (; present; present = next_present) {
@@ -447,7 +449,7 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
 
 	switch (bit) {
 	case IEEE80211_RADIOTAP_FLAGS:
-	    if (length < 1)
+	    if (length_remaining < 1)
 		break;
 	    rflags = tvb_get_guint8(tvb, offset);
 	    if (tree) {
@@ -459,13 +461,12 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
 			tvb, 0, 0, (rflags&IEEE80211_RADIOTAP_F_DATAPAD) != 0);
 	    }
 	    offset++;
-	    length--;
+	    length_remaining--;
 	    /* XXX CFP, WEP, FRAG */
 	    break;
 	case IEEE80211_RADIOTAP_RATE:
-	    if (length < 1)
+	    if (length_remaining < 1)
 		break;
-	    rflags = tvb_get_guint8(tvb, offset);
 	    rate = tvb_get_guint8(tvb, offset) & 0x7f;
 	    if (check_col(pinfo->cinfo, COL_TX_RATE)) {
 		col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%d.%d",
@@ -477,12 +478,11 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
 			"Data Rate: %d.%d Mb/s", rate / 2, rate & 1 ? 5 : 0);
 	    }
 	    offset++;
-	    length--;
+	    length_remaining--;
 	    break;
 	case IEEE80211_RADIOTAP_DBM_ANTSIGNAL:
-	    if (length < 1)
+	    if (length_remaining < 1)
 		break;
-	    rflags = tvb_get_guint8(tvb, offset);
 	    dbm = (gint8) tvb_get_guint8(tvb, offset);
 	    if (check_col(pinfo->cinfo, COL_RSSI)) {
 		col_add_fstr(pinfo->cinfo, COL_RSSI, "%d dBm", dbm);
@@ -494,12 +494,11 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
 					  "SSI Signal: %d dBm", dbm);
 	    }
 	    offset++;
-	    length--;
+	    length_remaining--;
 	    break;
 	case IEEE80211_RADIOTAP_DB_ANTSIGNAL:
-	    if (length < 1)
+	    if (length_remaining < 1)
 		break;
-	    rflags = tvb_get_guint8(tvb, offset);
 	    db = tvb_get_guint8(tvb, offset);
 	    if (check_col(pinfo->cinfo, COL_RSSI)) {
 		col_add_fstr(pinfo->cinfo, COL_RSSI, "%u dB", db);
@@ -511,12 +510,11 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
 					   "SSI Signal: %u dB", db);
 	    }
 	    offset++;
-	    length--;
+	    length_remaining--;
 	    break;
 	case IEEE80211_RADIOTAP_DBM_ANTNOISE:
-	    if (length < 1)
+	    if (length_remaining < 1)
 		break;
-	    rflags = tvb_get_guint8(tvb, offset);
 	    dbm = (gint8) tvb_get_guint8(tvb, offset);
 	    if (tree) {
 		proto_tree_add_int_format(radiotap_tree,
@@ -525,12 +523,11 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
 					  "SSI Noise: %d dBm", dbm);
 	    }
 	    offset++;
-	    length--;
+	    length_remaining--;
 	    break;
 	case IEEE80211_RADIOTAP_DB_ANTNOISE:
-	    if (length < 1)
+	    if (length_remaining < 1)
 		break;
-	    rflags = tvb_get_guint8(tvb, offset);
 	    db = tvb_get_guint8(tvb, offset);
 	    if (tree) {
 		proto_tree_add_uint_format(radiotap_tree,
@@ -539,34 +536,31 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
 					   "SSI Noise: %u dB", db);
 	    }
 	    offset++;
-	    length--;
+	    length_remaining--;
 	    break;
 	case IEEE80211_RADIOTAP_ANTENNA:
-	    if (length < 1)
+	    if (length_remaining < 1)
 		break;
-	    rflags = tvb_get_guint8(tvb, offset);
 	    if (tree) {
 		proto_tree_add_uint(radiotap_tree, hf_radiotap_antenna,
 				   tvb, offset, 1, tvb_get_guint8(tvb, offset));
 	    }
 	    offset++;
-	    length--;
+	    length_remaining--;
 	    break;
 	case IEEE80211_RADIOTAP_DBM_TX_POWER:
-	    if (length < 1)
+	    if (length_remaining < 1)
 		break;
-	    rflags = tvb_get_guint8(tvb, offset);
 	    if (tree) {
 		proto_tree_add_int(radiotap_tree, hf_radiotap_txpower,
 				   tvb, offset, 1, tvb_get_guint8(tvb, offset));
 	    }
 	    offset++;
-	    length--;
+	    length_remaining--;
 	    break;
 	case IEEE80211_RADIOTAP_CHANNEL:
-	    if (length < 4)
+	    if (length_remaining < 4)
 		break;
-	    rflags = tvb_get_guint8(tvb, offset);
 	    if (tree) {
 		freq = tvb_get_letohs(tvb, offset);
 		flags = tvb_get_letohs(tvb, offset+2);
@@ -577,31 +571,29 @@ dissect_radiotap(tvbuff_t *tvb, packet_i
 			tvb, offset+2, 2, flags);
 	    }
 	    offset+=4;
-	    length-=4;
+	    length_remaining-=4;
 	    break;
 	case IEEE80211_RADIOTAP_FHSS:
 	case IEEE80211_RADIOTAP_LOCK_QUALITY:
 	case IEEE80211_RADIOTAP_TX_ATTENUATION:
 	case IEEE80211_RADIOTAP_DB_TX_ATTENUATION:
-	    if (length < 2)
+	    if (length_remaining < 2)
 		break;
-	    rflags = tvb_get_guint8(tvb, offset);
 #if 0
 	    tvb_get_letohs(tvb, offset);
 #endif
 	    offset+=2;
-	    length-=2;
+	    length_remaining-=2;
 	    break;
 	case IEEE80211_RADIOTAP_TSFT:
-	    if (length < 8)
+	    if (length_remaining < 8)
 		break;
-	    rflags = tvb_get_guint8(tvb, offset);
 	    if (tree) {
 		proto_tree_add_uint64(radiotap_tree, hf_radiotap_mactime,
 				tvb, offset, 8, tvb_get_letoh64(tvb, offset));
 	    }
 	    offset+=8;
-	    length-=8;
+	    length_remaining-=8;
 	    break;
 	default:
 	    /*
