--- epan/dissectors/packet-ieee80211.c.orig	Mon Oct 10 06:23:01 2005
+++ epan/dissectors/packet-ieee80211.c	Tue Dec  6 18:53:33 2005
@@ -74,6 +74,10 @@
 #include <ctype.h>
 #include "isprint.h"
 
+#ifndef roundup2
+#define	roundup2(x, y)	(((x)+((y)-1))&(~((y)-1))) /* if y is powers of two */
+#endif
+
 /* Defragment fragmented 802.11 datagrams */
 static gboolean wlan_defragment = TRUE;
 
@@ -635,11 +639,11 @@
   case DATA_FRAME:
     len = (COOK_ADDR_SELECTOR(fcf) == DATA_ADDR_T4) ? DATA_LONG_HDR_LEN :
 						      DATA_SHORT_HDR_LEN;
-    if( IS_DATA_QOS(fcf))
+    if (fcf & 0x80)
       return len + 2;
     else
       return len;
-  
+
   default:
     return 4;	/* XXX */
   }
@@ -1922,6 +1926,23 @@
 		     ether_to_str(addr));
 }
 
+static guint32
+crc32_802_tvb_padded(tvbuff_t *tvb, guint hdr_len, guint hdr_size, guint len)
+{
+  guint32 c_crc;
+
+  c_crc = crc32_ccitt_tvb(tvb, hdr_len);
+  c_crc = crc32_ccitt_seed(tvb_get_ptr(tvb, hdr_size, len), len, ~c_crc);
+
+  /* Byte reverse. */
+  c_crc = ((unsigned char)(c_crc>>0)<<24) |
+    ((unsigned char)(c_crc>>8)<<16) |
+    ((unsigned char)(c_crc>>16)<<8) |
+    ((unsigned char)(c_crc>>24)<<0);
+
+  return ( c_crc );
+}
+
 typedef enum {
     ENCAP_802_2,
     ENCAP_IPX,
@@ -1935,7 +1956,7 @@
 dissect_ieee80211_common (tvbuff_t * tvb, packet_info * pinfo,
 			  proto_tree * tree, gboolean fixed_length_header,
 			  gboolean has_radio_information, gint fcs_len,
-			  gboolean wlan_broken_fc)
+			  gboolean wlan_broken_fc, gboolean datapad)
 {
   guint16 fcf, flags, frame_type_subtype;
   guint16 seq_control;
@@ -1950,7 +1971,7 @@
   proto_tree *hdr_tree = NULL;
   proto_tree *flag_tree;
   proto_tree *fc_tree;
-  guint16 hdr_len;
+  guint16 hdr_len, ohdr_len;
   gboolean has_fcs;
   gint len, reported_len, ivlen;
   gboolean save_fragmented;
@@ -1994,6 +2015,9 @@
     hdr_len = DATA_LONG_HDR_LEN;
   else
     hdr_len = find_header_length (fcf);
+  ohdr_len = hdr_len;
+  if (datapad)
+    hdr_len = roundup2(hdr_len, 4);
   frame_type_subtype = COMPOSE_FRAME_TYPE(fcf);
 
   /*if (check_col (pinfo->cinfo, COL_INFO))
@@ -2495,9 +2519,13 @@
 	  reported_len -= 4;
 	  if (tree)
 	    {
-	      guint32 fcs = crc32_802_tvb(tvb, hdr_len + len);
 	      guint32 sent_fcs = tvb_get_ntohl(tvb, hdr_len + len);
+	      guint32 fcs;
 
+	      if (datapad)
+		fcs = crc32_802_tvb_padded(tvb, ohdr_len, hdr_len, len);
+	      else
+		fcs = crc32_802_tvb(tvb, hdr_len + len);
 	      if (fcs == sent_fcs)
 		proto_tree_add_uint_format(hdr_tree, hf_fcs, tvb,
 			hdr_len + len, 4, sent_fcs,
@@ -2530,35 +2558,46 @@
 	  proto_item *qos_fields;
 	  proto_tree *qos_tree;
 
+          guint16 qosoff;
           guint16 qos_control;
 	  guint16 qos_priority;
           guint16 qos_ack_policy;
 	  guint16 qos_eosp;
 	  guint16 qos_field_content;
 
-	  qos_fields = proto_tree_add_text(hdr_tree, tvb, hdr_len - 2, 2,
+	  /*
+	   * We calculate the offset to the QoS header data as
+	   * an offset relative to the end of the header.  But
+	   * when the header has been padded to align the data
+	   * this must be done relative to true header size, not
+	   * the padded/aligned value.  To simplify this work we
+	   * stash the original header size in ohdr_len instead
+	   * of recalculating it. 
+	   */
+	  qosoff = ohdr_len - 2;
+	  qos_fields = proto_tree_add_text(hdr_tree, tvb, qosoff, 2,
 	      "QoS parameters");
           qos_tree = proto_item_add_subtree (qos_fields, ett_qos_parameters);
 
-          qos_control =	      tvb_get_letohs(tvb, hdr_len - 2);
+          qos_control =	      tvb_get_letohs(tvb, qosoff + 0);
 	  qos_priority =      COOK_QOS_PRIORITY(qos_control);
           qos_ack_policy =    COOK_QOS_ACK_POLICY(qos_control);
 	  qos_eosp =	      COOK_QOS_EOSP(qos_control);
 	  qos_field_content = COOK_QOS_FIELD_CONTENT( qos_control);
 
           proto_tree_add_uint_format (qos_tree, hf_qos_priority, tvb,
-	      hdr_len - 2, 2, qos_priority,
+	      qosoff, 2, qos_priority,
 	      "Priority: %d (%s) (%s)",
 	      qos_priority, qos_tags[qos_priority], qos_acs[qos_priority]);
 
     	  if(flags & FLAG_FROM_DS)	{
 	    proto_tree_add_boolean (qos_tree, hf_qos_eosp, tvb, 
-	      hdr_len - 2, 1, qos_eosp);
+	      qosoff, 1, qos_eosp);
 
 	    if(IS_DATA_CF_POLL(frame_type_subtype)) {
 	      /* txop limit */
 	      proto_tree_add_uint_format (qos_tree, hf_qos_field_content, tvb,
-      		  hdr_len - 1, 1, qos_field_content, "TXOP Limit: %d ", qos_field_content);
+      		  qosoff + 1, 1, qos_field_content, "TXOP Limit: %d ", qos_field_content);
 	      
 	    }else {
 	      /* qap ps buffer state */
@@ -2572,7 +2611,7 @@
 	      buf_ac	= COOK_PS_BUF_AC(qos_field_content);  /*access category */
 	      buf_load	= COOK_PS_BUF_LOAD(qos_field_content);
 
-	      qos_ps_buf_state_fields = proto_tree_add_text(qos_tree, tvb, hdr_len - 1, 1,
+	      qos_ps_buf_state_fields = proto_tree_add_text(qos_tree, tvb, qosoff + 1, 1,
 	      "QAP PS Buffer State: 0x%x", qos_field_content);
     	      qos_ps_buf_state_tree = proto_item_add_subtree (qos_ps_buf_state_fields, ett_qos_ps_buf_state);
 
@@ -2581,25 +2620,25 @@
     		  1, 1, buf_state);
 	      
 	      proto_tree_add_uint_format (qos_ps_buf_state_tree, hf_qos_buf_ac, tvb,
-		  hdr_len - 1, 1, buf_ac, "Priority: %d (%s)",
+		  qosoff + 1, 1, buf_ac, "Priority: %d (%s)",
 		  buf_ac, wme_acs[buf_ac]);
 	      
 	      proto_tree_add_uint_format (qos_ps_buf_state_tree, hf_qos_buf_load, tvb,
-      		  hdr_len - 1, 1, buf_load, "Buffered load: %d ", (buf_load * 4096));
+      		  qosoff + 1, 1, buf_load, "Buffered load: %d ", (buf_load * 4096));
 */	      
 
 	    }
 	  } else  if(qos_eosp)  {
 	    /* txop limit requested */
 	    proto_tree_add_uint_format (qos_tree, hf_qos_field_content, tvb,
-      		  hdr_len - 1, 1, qos_field_content, "Queue Size: %d ", (qos_field_content * 254));
+      		  qosoff + 1, 1, qos_field_content, "Queue Size: %d ", (qos_field_content * 254));
 	  } else  {
 	    /* queue size */
 	    proto_tree_add_uint_format (qos_tree, hf_qos_field_content, tvb,
-		  hdr_len - 1, 1, qos_field_content, "TXOP Limit Requested: %d ", qos_field_content);
+		  qosoff + 1, 1, qos_field_content, "TXOP Limit Requested: %d ", qos_field_content);
 	  }
 	  
-	  proto_tree_add_uint (qos_tree, hf_qos_ack_policy, tvb, hdr_len - 2, 1,
+	  proto_tree_add_uint (qos_tree, hf_qos_ack_policy, tvb, qosoff, 1,
 	      qos_ack_policy); 
 
       	} /* end of qos control field */
@@ -2957,7 +2996,17 @@
 dissect_ieee80211 (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
 {
   dissect_ieee80211_common (tvb, pinfo, tree, FALSE, FALSE,
-      pinfo->pseudo_header->ieee_802_11.fcs_len, FALSE);
+      pinfo->pseudo_header->ieee_802_11.fcs_len, FALSE, FALSE);
+}
+
+/*
+ * Dissect 802.11 with a variable-length link-layer header and data padding.
+ */
+static void
+dissect_ieee80211_datapad (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
+{
+  dissect_ieee80211_common (tvb, pinfo, tree, FALSE, FALSE,
+      pinfo->pseudo_header->ieee_802_11.fcs_len, FALSE, TRUE);
 }
 
 /*
@@ -2968,7 +3017,7 @@
 dissect_ieee80211_radio (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
 {
   dissect_ieee80211_common (tvb, pinfo, tree, FALSE, TRUE,
-     pinfo->pseudo_header->ieee_802_11.fcs_len, FALSE);
+     pinfo->pseudo_header->ieee_802_11.fcs_len, FALSE, FALSE);
 }
 
 /*
@@ -2979,7 +3028,7 @@
 static void
 dissect_ieee80211_bsfc (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
 {
-  dissect_ieee80211_common (tvb, pinfo, tree, FALSE, FALSE, 0, TRUE);
+  dissect_ieee80211_common (tvb, pinfo, tree, FALSE, FALSE, 0, TRUE, FALSE);
 }
 
 /*
@@ -2989,7 +3038,7 @@
 static void
 dissect_ieee80211_fixed (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
 {
-  dissect_ieee80211_common (tvb, pinfo, tree, TRUE, FALSE, 0, FALSE);
+  dissect_ieee80211_common (tvb, pinfo, tree, TRUE, FALSE, 0, FALSE, FALSE);
 }
 
 static void
@@ -3773,6 +3822,7 @@
   register_dissector("wlan", dissect_ieee80211, proto_wlan);
   register_dissector("wlan_fixed", dissect_ieee80211_fixed, proto_wlan);
   register_dissector("wlan_bsfc", dissect_ieee80211_bsfc, proto_wlan);
+  register_dissector("wlan_datapad", dissect_ieee80211_datapad, proto_wlan);
   register_init_routine(wlan_defragment_init);
 
   wlan_tap = register_tap("wlan");
