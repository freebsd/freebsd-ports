--- epan/dissectors/packet-radiotap.c.orig	Mon Oct 10 06:23:07 2005
+++ epan/dissectors/packet-radiotap.c	Tue Dec  6 18:34:19 2005
@@ -73,7 +73,6 @@
     IEEE80211_RADIOTAP_ANTENNA = 11,
     IEEE80211_RADIOTAP_DB_ANTSIGNAL = 12,
     IEEE80211_RADIOTAP_DB_ANTNOISE = 13,
-    IEEE80211_RADIOTAP_FCS = 14,
     IEEE80211_RADIOTAP_EXT = 31
 };
 
@@ -121,6 +120,11 @@
 #define	IEEE80211_RADIOTAP_F_FRAG	0x08	/* sent/received
 						 * with fragmentation
 						 */
+#define	IEEE80211_RADIOTAP_F_FCS	0x10	/* frame includes FCS */
+#define	IEEE80211_RADIOTAP_F_DATAPAD	0x20	/* frame has padding between
+						 * 802.11 header and payload
+						 * (to 32-bit boundary)
+						 */
 
 /* protocol */
 static int proto_radiotap = -1;
@@ -140,11 +144,14 @@
 static int hf_radiotap_db_antnoise = -1;
 static int hf_radiotap_txpower = -1;
 static int hf_radiotap_preamble = -1;
+static int hf_radiotap_fcs = -1;
+static int hf_radiotap_datapad = -1;
 
 static gint ett_radiotap = -1;
 static gint ett_radiotap_present = -1;
 
 static dissector_handle_t ieee80211_handle;
+static dissector_handle_t ieee80211_datapad_handle;
 
 static void
 dissect_radiotap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
@@ -190,6 +197,12 @@
     { 0, NULL },
   };
 
+  static const value_string truefalse_type[] = {
+    { 0, "False" },
+    { 1, "True" },
+    { 0, NULL },
+  };
+
   static hf_register_info hf[] = {
     { &hf_radiotap_version,
       { "Header revision", "radiotap.version",
@@ -208,6 +221,14 @@
       { "Preamble", "radiotap.flags.preamble",
 	FT_UINT32, BASE_DEC, VALS(preamble_type), 0x0, "", HFILL } },
 
+    /* XXX for debugging */
+    { &hf_radiotap_fcs,
+      { "FCS", "radiotap.flags.fcs",
+	FT_UINT32, BASE_DEC, VALS(truefalse_type), 0x0, "", HFILL } },
+    { &hf_radiotap_datapad,
+      { "DATAPAD", "radiotap.flags.datapad",
+	FT_UINT32, BASE_DEC, VALS(truefalse_type), 0x0, "", HFILL } },
+
     { &hf_radiotap_mactime,
        { "MAC timestamp", "radiotap.mactime",
 	 FT_UINT64, BASE_DEC, NULL, 0x0, "", HFILL } },
@@ -257,6 +278,7 @@
 static int
 ieee80211_mhz2ieee(int freq, int flags)
 {
+#define IS_CHAN_IN_PUBLIC_SAFETY_BAND(_c) ((_c) > 4940 && (_c) < 4990)
     if (flags & IEEE80211_CHAN_2GHZ) {		/* 2GHz band */
 	if (freq == 2484)
 	    return 14;
@@ -265,16 +287,28 @@
 	else
 	    return 15 + ((freq - 2512) / 20);
     } else if (flags & IEEE80211_CHAN_5GHZ) {	/* 5Ghz band */
-	return (freq - 5000) / 5;
+	if (IS_CHAN_IN_PUBLIC_SAFETY_BAND(freq))
+	    return ((freq * 10) + (((freq % 5) == 2) ? 5 : 0) - 49400) / 5;
+	if (freq <= 5000)
+	    return (freq - 4000) / 5;
+	else
+	    return (freq - 5000) / 5;
     } else {					/* either, guess */
 	if (freq == 2484)
 	    return 14;
 	if (freq < 2484)
 	    return (freq - 2407) / 5;
-	if (freq < 5000)
-	    return 15 + ((freq - 2512) / 20);
+	if (freq < 5000) {
+	    if (IS_CHAN_IN_PUBLIC_SAFETY_BAND(freq))
+		return ((freq * 10) + (((freq % 5) == 2) ? 5 : 0) - 49400)/5;
+	    else if (freq > 4900)
+		return (freq - 4000) / 5;
+	    else
+		return 15 + ((freq - 2512) / 20);
+	}
 	return (freq - 5000) / 5;
     }
+#undef IS_CHAN_IN_PUBLIC_SAFETY_BAND
 }
 
 static void
@@ -294,7 +328,7 @@
     guint32 length;
     guint32 rate, freq, flags;
     gint8 dbm;
-    guint8 db;
+    guint8 db, rflags;
     guint32 present, next_present;
     int bit;
 
@@ -334,6 +368,7 @@
      */
     offset += sizeof(struct ieee80211_radiotap_header);
 
+    rflags = 0;
     for (; present; present = next_present) {
 	/* clear the least significant bit that is set */
 	next_present = present & (present - 1);
@@ -344,45 +379,16 @@
 	switch (bit) {
 	case IEEE80211_RADIOTAP_FLAGS:
 	    if (tree) {
+		rflags = tvb_get_guint8(tvb, offset);
 		proto_tree_add_uint(radiotap_tree, hf_radiotap_preamble,
-			tvb, 0, 0, (tvb_get_guint8(tvb, offset) &
-				IEEE80211_RADIOTAP_F_SHORTPRE) != 0);
+			tvb, 0, 0, (rflags&IEEE80211_RADIOTAP_F_SHORTPRE) != 0);
+		proto_tree_add_uint(radiotap_tree, hf_radiotap_fcs,
+			tvb, 0, 0, (rflags&IEEE80211_RADIOTAP_F_FCS) != 0);
+		proto_tree_add_uint(radiotap_tree, hf_radiotap_datapad,
+			tvb, 0, 0, (rflags&IEEE80211_RADIOTAP_F_DATAPAD) != 0);
 	    }
 	    offset++;
 	    /* XXX CFP, WEP, FRAG */
-#if 0
-      capability = tvb_get_letohs (tvb, offset);
-
-      cap_item = proto_tree_add_uint_format (tree, ff_capture,
-					     tvb, offset, 2,
-					     capability,
-					     "Capability Information: 0x%04X",
-					     capability);
-      cap_tree = proto_item_add_subtree (cap_item, ett_cap_tree);
-      proto_tree_add_boolean (cap_tree, ff_cf_ess, tvb, offset, 2,
-			      capability);
-      proto_tree_add_boolean (cap_tree, ff_cf_ibss, tvb, offset, 2,
-			      capability);
-      if (ESS_SET (capability) != 0)	/* This is an AP */
-	proto_tree_add_uint (cap_tree, ff_cf_ap_poll, tvb, offset, 2,
-			     capability);
-
-      else			/* This is a STA */
-	proto_tree_add_uint (cap_tree, ff_cf_sta_poll, tvb, offset, 2,
-			     capability);
-      proto_tree_add_boolean (cap_tree, ff_cf_privacy, tvb, offset, 2,
-			      capability);
-      proto_tree_add_boolean (cap_tree, ff_cf_preamble, tvb, offset, 2,
-			      capability);
-      proto_tree_add_boolean (cap_tree, ff_cf_pbcc, tvb, offset, 2,
-			      capability);
-      proto_tree_add_boolean (cap_tree, ff_cf_agility, tvb, offset, 2,
-			      capability);
-      proto_tree_add_boolean (cap_tree, ff_short_slot_time, tvb, offset, 2,
-			      capability);
-      proto_tree_add_boolean (cap_tree, ff_dsss_ofdm, tvb, offset, 2,
-			      capability);
-#endif
 	    break;
 	case IEEE80211_RADIOTAP_RATE:
 	    rate = tvb_get_guint8(tvb, offset) & 0x7f;
@@ -480,8 +486,8 @@
 	    break;
 	case IEEE80211_RADIOTAP_TSFT:
 	    if (tree) {
-		proto_tree_add_item(radiotap_tree, hf_radiotap_mactime,
-				    tvb, offset, 8, FALSE);
+		proto_tree_add_uint64(radiotap_tree, hf_radiotap_mactime,
+				tvb, offset, 8, tvb_get_letoh64(tvb, offset));
 	    }
 	    offset+=8;
 	    break;
@@ -495,8 +501,11 @@
 	}
     }
 
+    if (rflags & IEEE80211_RADIOTAP_F_FCS)
+	pinfo->pseudo_header->ieee_802_11.fcs_len = 4;
     /* dissect the 802.11 header next */
-    call_dissector(ieee80211_handle,
+    call_dissector((rflags & IEEE80211_RADIOTAP_F_DATAPAD) ?
+	ieee80211_datapad_handle : ieee80211_handle,
 	tvb_new_subset(tvb, length, -1, -1), pinfo, tree);
 #undef BITNO_32
 #undef BITNO_16
@@ -513,6 +522,7 @@
 
     /* handle for 802.11 dissector */
     ieee80211_handle = find_dissector("wlan");
+    ieee80211_datapad_handle = find_dissector("wlan_datapad");
 
     radiotap_handle = create_dissector_handle(dissect_radiotap, proto_radiotap);
 
