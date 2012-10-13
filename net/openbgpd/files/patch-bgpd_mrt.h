Index: bgpd/mrt.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/mrt.h,v
retrieving revision 1.1.1.6
retrieving revision 1.1.1.9
diff -u -p -r1.1.1.6 -r1.1.1.9
--- bgpd/mrt.h	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/mrt.h	13 Oct 2012 18:22:43 -0000	1.1.1.9
@@ -1,4 +1,4 @@
-/*	$OpenBSD: mrt.h,v 1.23 2009/06/29 12:22:16 claudio Exp $ */
+/*	$OpenBSD: mrt.h,v 1.30 2011/09/18 09:31:25 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -18,12 +18,10 @@
 #ifndef __MRT_H__
 #define __MRT_H__
 
-#include "bgpd.h"
-
 /*
  * MRT binary packet format
  * For more info see:
- * draft-ietf-grow-mrt-04.txt, "MRT routing information export format"
+ * draft-ietf-grow-mrt-11.txt, "MRT routing information export format"
  * http://www.quagga.net/docs/docs-multi/Packet-Binary-Dump-Format.html
  */
 
@@ -37,11 +35,18 @@
  * |               length              | length of packet excluding this header
  * +--------+--------+--------+--------+
  *
- * ET types include an additional 32bit microsecond field comming after the
- * length field.
+ * ET types include an additional 32bit microsecond field coming after the
+ * length field. Which is accounted in the length field.
  */
 #define MRT_HEADER_SIZE		12
 
+struct mrt_hdr {
+	u_int32_t	timestamp;
+	u_int16_t	type;
+	u_int16_t	subtype;
+	u_int32_t	length;
+} __packed;
+
 enum MRT_MSG_TYPES {
 	MSG_NULL,		/*  0 empty msg (deprecated) */
 	MSG_START,		/*  1 sender is starting up */
@@ -70,13 +75,15 @@ enum MRT_MSG_TYPES {
  * that are normaly saved as MSG_TABLE_DUMP.
  * In most cases this is the format to choose to dump updates et al.
  */
-enum MRT_BGP4MP_TYPES {
+enum MRT_BGP4MP_SUBTYPES {
 	BGP4MP_STATE_CHANGE,	/* state change */
 	BGP4MP_MESSAGE,		/* bgp message */
 	BGP4MP_ENTRY,		/* table dumps (deprecated) */
 	BGP4MP_SNAPSHOT,	/* file name for dump (deprecated) */
+	BGP4MP_MESSAGE_AS4,	/* same as BGP4MP_MESSAGE with 4byte AS */
 	BGP4MP_STATE_CHANGE_AS4,
-	BGP4MP_MESSAGE_AS4	/* same as BGP4MP_MESSAGE with 4byte AS */
+	BGP4MP_MESSAGE_LOCAL,	  /* same as BGP4MP_MESSAGE but for self */
+	BGP4MP_MESSAGE_AS4_LOCAL  /* originated updates. Not implemented */
 };
 
 /* size of the BGP4MP headers without payload */
@@ -104,6 +111,7 @@ enum MRT_BGP4MP_TYPES {
  *
  * The source_ip and dest_ip are dependant of the afi type. For IPv6 source_ip
  * and dest_ip are both 16 bytes long.
+ * For the AS4 types the source_as and dest_as numbers are both 4 bytes long.
  *
  * Payload of a BGP4MP_STATE_CHANGE packet:
  *
@@ -155,6 +163,98 @@ enum MRT_BGP4MP_TYPES {
  */
 
 /*
+ * New MRT dump format MSG_TABLE_DUMP_V2, the dump is implemented with
+ * sub-tables for peers and NLRI entries just use the index into the peer
+ * table.
+ */
+enum MRT_DUMP_V2_SUBTYPES {
+	MRT_DUMP_V2_PEER_INDEX_TABLE=1,
+	MRT_DUMP_V2_RIB_IPV4_UNICAST=2,
+	MRT_DUMP_V2_RIB_IPV4_MULTICAST=3,
+	MRT_DUMP_V2_RIB_IPV6_UNICAST=4,
+	MRT_DUMP_V2_RIB_IPV6_MULTICAST=5,
+	MRT_DUMP_V2_RIB_GENERIC=6
+};
+
+/*
+ * Format of the MRT_DUMP_V2_PEER_INDEX_TABLE:
+ * If there is no view_name, view_name_len must be set to 0
+ *
+ * +--------+--------+--------+--------+
+ * |         collector_bgp_id          |
+ * +--------+--------+--------+--------+
+ * |  view_name_len  |    view_name
+ * +--------+--------+--------+--------+
+ *        view_name (variable) ...     |
+ * +--------+--------+--------+--------+
+ * |   peer_count    |   peer_entries
+ * +--------+--------+--------+--------+
+ *       peer_entries (variable) ...
+ * +--------+--------+--------+--------+
+ *
+ * The format of a peer_entry is the following:
+ *
+ * +--------+
+ * |  type  |    
+ * +--------+--------+--------+--------+
+ * |            peer_bgp_id            |
+ * +--------+--------+--------+--------+
+ * |       peer_ip_addr (variable)     |
+ * +--------+--------+--------+--------+
+ * |            peer_as (variable)     |
+ * +--------+--------+--------+--------+
+ *
+ * The message is packed a bit strangely. The type byte defines what size
+ * the peer addr and peer AS have.
+ * The position of a peer in the PEER_INDEX_TABLE is used as the index for
+ * the other messages.
+ */
+#define MRT_DUMP_V2_PEER_BIT_I	0x1	/* set for IPv6 addrs */
+#define MRT_DUMP_V2_PEER_BIT_A	0x2	/* set for 32 bits AS number */
+
+/*
+ * AFI/SAFI specific RIB Subtypes are special to save a few bytes.
+ * 
+ * +--------+--------+--------+--------+
+ * |              seq_num              |
+ * +--------+--------+--------+--------+
+ * |  plen  |  prefix (variable)
+ * +--------+--------+--------+--------+
+ * |     #entry      | rib entries (variable)
+ * +--------+--------+--------+--------+
+ *
+ * The RIB_GENERIC subtype is needed for the less common AFI/SAFI pairs
+ *
+ * +--------+--------+--------+--------+
+ * |              seq_num              |
+ * +--------+--------+--------+--------+
+ * |       AFI       |  SAFI  |  NLRI
+ * +--------+--------+--------+--------+
+ *     NLRI (variable) ...
+ * +--------+--------+--------+--------+
+ * |     #entry      | rib entries (variable)
+ * +--------+--------+--------+--------+
+ */
+
+/*
+ * The RIB entries have the following form.
+ *
+ * +--------+--------+
+ * |   peer index    |
+ * +--------+--------+--------+--------+
+ * |          originated_time          |
+ * +--------+--------+--------+--------+
+ * |    attr_len     |   bgp_attrs
+ * +--------+--------+--------+--------+
+ *      bgp_attrs (variable) ...
+ * +--------+--------+--------+--------+
+ *
+ * Some BGP path attributes need special encoding:
+ *  - the AS_PATH attribute MUST be encoded as 4-Byte AS
+ *  - the MP_REACH_NLRI only consists of the nexthop len and nexthop address
+ */
+
+/*
  * Format for routing table dumps in "old" mrt format.
  * Type MSG_TABLE_DUMP and subtype is AFI_IPv4 (1) for IPv4 and AFI_IPv6 (2)
  * for IPv6. In the IPv6 case prefix and peer_ip are both 16 bytes long.
@@ -182,8 +282,14 @@ enum MRT_BGP4MP_TYPES {
  * The status field is unused and should be set to 1.
  */
 
+enum MRT_DUMP_SUBTYPES {
+	MRT_DUMP_AFI_IP=1,
+	MRT_DUMP_AFI_IPv6=2
+};
+
 /* size of the dump header until attr_len */
 #define MRT_DUMP_HEADER_SIZE	22
+#define MRT_DUMP_HEADER_SIZE_V6	46
 
 /*
  * OLD MRT message headers. These structs are here for completion but
@@ -192,7 +298,7 @@ enum MRT_BGP4MP_TYPES {
  * Only for bgp messages (type 5, 9 and 10)
  * Nota bene for bgp dumps MSG_PROTOCOL_BGP4MP should be used.
  */
-enum MRT_BGP_TYPES {
+enum MRT_BGP_SUBTYPES {
 	MSG_BGP_NULL,
 	MSG_BGP_UPDATE,		/* raw update packet (contains both withdraws
 				   and announcements) */
@@ -221,10 +327,8 @@ enum MRT_BGP_TYPES {
  *
  * For IPv6 the type is MSG_PROTOCOL_BGP4PLUS and the subtype remains
  * MSG_BGP_UPDATE. The source_ip and dest_ip are again extended to 16 bytes.
- */
-
-/*
- * For subtype MSG_BGP_STATECHANGE (for all BGP types or just for the
+ *
+ * For subtype MSG_BGP_STATE_CHANGE (for all BGP types or just for the
  * MSG_PROTOCOL_BGP4PLUS case? Unclear.)
  *
  * +--------+--------+--------+--------+
@@ -235,7 +339,7 @@ enum MRT_BGP_TYPES {
  * |    new_state    |
  * +--------+--------+
  *
- * State are defined in RFC 1771.
+ * States are defined in RFC 1771/4271.
  */
 
 /*
@@ -251,66 +355,4 @@ enum MRT_BGP_TYPES {
  *    terminated ... |   0    |
  * +--------+--------+--------+
  */
-
-#define	MRT_FILE_LEN	512
-enum mrt_type {
-	MRT_NONE,
-	MRT_TABLE_DUMP,
-	MRT_TABLE_DUMP_MP,
-	MRT_ALL_IN,
-	MRT_ALL_OUT,
-	MRT_UPDATE_IN,
-	MRT_UPDATE_OUT
-};
-
-enum mrt_state {
-	MRT_STATE_RUNNING,
-	MRT_STATE_OPEN,
-	MRT_STATE_REOPEN,
-	MRT_STATE_REMOVE
-};
-
-struct mrt {
-	char			rib[PEER_DESCR_LEN];
-	struct msgbuf		wbuf;
-	LIST_ENTRY(mrt)		entry;
-	u_int32_t		peer_id;
-	u_int32_t		group_id;
-	enum mrt_type		type;
-	enum mrt_state		state;
-	u_int16_t		seqnum;
-};
-
-struct mrt_config {
-	struct mrt		conf;
-	char			name[MRT_FILE_LEN];	/* base file name */
-	char			file[MRT_FILE_LEN];	/* actual file name */
-	time_t			ReopenTimer;
-	time_t			ReopenTimerInterval;
-};
-
-#define	MRT2MC(x)	((struct mrt_config *)(x))
-#define	MRT_MAX_TIMEOUT	7200
-
-struct peer;
-struct prefix;
-struct rib_entry;
-
-/* prototypes */
-void		 mrt_dump_bgp_msg(struct mrt *, void *, u_int16_t,
-		     struct peer *);
-void		 mrt_dump_state(struct mrt *, u_int16_t, u_int16_t,
-		     struct peer *);
-void		 mrt_clear_seq(void);
-void		 mrt_dump_upcall(struct rib_entry *, void *);
-void		 mrt_dump_done(void *);
-void		 mrt_write(struct mrt *);
-void		 mrt_clean(struct mrt *);
-void		 mrt_init(struct imsgbuf *, struct imsgbuf *);
-int		 mrt_timeout(struct mrt_head *);
-void		 mrt_reconfigure(struct mrt_head *);
-void		 mrt_handler(struct mrt_head *);
-struct mrt	*mrt_get(struct mrt_head *, struct mrt *);
-int		 mrt_mergeconfig(struct mrt_head *, struct mrt_head *);
-
 #endif
