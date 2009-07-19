Index: bgpd/mrt.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/mrt.h,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/mrt.h	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/mrt.h	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: mrt.h,v 1.16 2007/05/30 04:28:27 msf Exp $ */
+/*	$OpenBSD: mrt.h,v 1.23 2009/06/29 12:22:16 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -20,12 +20,10 @@
 
 #include "bgpd.h"
 
-/* In cases of failure wait at least MRT_MIN_RETRY. */
-#define MRT_MIN_RETRY	300
-
 /*
- * MRT binary packet format as used by zebra.
+ * MRT binary packet format
  * For more info see:
+ * draft-ietf-grow-mrt-04.txt, "MRT routing information export format"
  * http://www.quagga.net/docs/docs-multi/Packet-Binary-Dump-Format.html
  */
 
@@ -38,24 +36,33 @@
  * +--------+--------+--------+--------+
  * |               length              | length of packet excluding this header
  * +--------+--------+--------+--------+
+ *
+ * ET types include an additional 32bit microsecond field comming after the
+ * length field.
  */
 #define MRT_HEADER_SIZE		12
 
 enum MRT_MSG_TYPES {
-	MSG_NULL,
+	MSG_NULL,		/*  0 empty msg (deprecated) */
 	MSG_START,		/*  1 sender is starting up */
-	MSG_DIE,		/*  2 receiver should shut down */
+	MSG_DIE,		/*  2 receiver should shut down (deprecated) */
 	MSG_I_AM_DEAD,		/*  3 sender is shutting down */
-	MSG_PEER_DOWN,		/*  4 sender's peer is down */
-	MSG_PROTOCOL_BGP,	/*  5 msg is a BGP packet */
+	MSG_PEER_DOWN,		/*  4 sender's peer is down (deprecated) */
+	MSG_PROTOCOL_BGP,	/*  5 msg is a BGP packet (deprecated) */
 	MSG_PROTOCOL_RIP,	/*  6 msg is a RIP packet */
-	MSG_PROTOCOL_IDRP,	/*  7 msg is an IDRP packet */
+	MSG_PROTOCOL_IDRP,	/*  7 msg is an IDRP packet (deprecated) */
 	MSG_PROTOCOL_RIPNG,	/*  8 msg is a RIPNG packet */
-	MSG_PROTOCOL_BGP4PLUS,	/*  9 msg is a BGP4+ packet */
-	MSG_PROTOCOL_BGP4PLUS1,	/* 10 msg is a BGP4+ (draft 01) packet */
+	MSG_PROTOCOL_BGP4PLUS,	/*  9 msg is a BGP4+ packet (deprecated) */
+	MSG_PROTOCOL_BGP4PLUS1,	/* 10 msg is a BGP4+ (draft 01) (deprecated) */
 	MSG_PROTOCOL_OSPF,	/* 11 msg is an OSPF packet */
 	MSG_TABLE_DUMP,		/* 12 routing table dump */
-	MSG_PROTOCOL_BGP4MP=16	/* 16 zebras own packet format */
+	MSG_TABLE_DUMP_V2,	/* 13 routing table dump */
+	MSG_PROTOCOL_BGP4MP=16,	/* 16 zebras own packet format */
+	MSG_PROTOCOL_BGP4MP_ET=17,
+	MSG_PROTOCOL_ISIS=32,	/* 32 msg is a ISIS package */
+	MSG_PROTOCOL_ISIS_ET=33,
+	MSG_PROTOCOL_OSPFV3=48,	/* 48 msg is a OSPFv3 package */
+	MSG_PROTOCOL_OSPFV3_ET=49
 };
 
 /*
@@ -64,15 +71,20 @@ enum MRT_MSG_TYPES {
  * In most cases this is the format to choose to dump updates et al.
  */
 enum MRT_BGP4MP_TYPES {
-	BGP4MP_STATE_CHANGE=0,	/* state change */
-	BGP4MP_MESSAGE=1,	/* bgp message */
-	BGP4MP_ENTRY=2,		/* table dumps */
-	BGP4MP_SNAPSHOT=3
+	BGP4MP_STATE_CHANGE,	/* state change */
+	BGP4MP_MESSAGE,		/* bgp message */
+	BGP4MP_ENTRY,		/* table dumps (deprecated) */
+	BGP4MP_SNAPSHOT,	/* file name for dump (deprecated) */
+	BGP4MP_STATE_CHANGE_AS4,
+	BGP4MP_MESSAGE_AS4	/* same as BGP4MP_MESSAGE with 4byte AS */
 };
 
 /* size of the BGP4MP headers without payload */
 #define MRT_BGP4MP_IPv4_HEADER_SIZE	16
 #define MRT_BGP4MP_IPv6_HEADER_SIZE	40
+/* 4-byte AS variants of the previous */
+#define MRT_BGP4MP_AS4_IPv4_HEADER_SIZE	20
+#define MRT_BGP4MP_AS4_IPv6_HEADER_SIZE	44
 
 /* If the type is PROTOCOL_BGP4MP and the subtype is either BGP4MP_STATE_CHANGE
  * or BGP4MP_MESSAGE the message consists of a common header plus the payload.
@@ -110,6 +122,7 @@ enum MRT_BGP4MP_TYPES {
  */
 #define MRT_BGP4MP_IPv4_ENTRY_SIZE	18
 #define MRT_BGP4MP_IPv6_ENTRY_SIZE	30
+#define MRT_BGP4MP_MAX_PREFIXLEN	17
 /*
  * The "new" table dump format consists of messages of type PROTOCOL_BGP4MP
  * and subtype BGP4MP_ENTRY.
@@ -151,9 +164,9 @@ enum MRT_BGP4MP_TYPES {
  * +--------+--------+--------+--------+
  * |               prefix              |
  * +--------+--------+--------+--------+
- * |  plen  | status |    originated
+ * |  plen  | status | originated time
  * +--------+--------+--------+--------+
- *      originated   |     peer_ip
+ *   originated time |     peer_ip
  * +--------+--------+--------+--------+
  *       peer_ip     |     peer_as     |
  * +--------+--------+--------+--------+
@@ -166,8 +179,7 @@ enum MRT_BGP4MP_TYPES {
  *
  *
  * View is normaly 0 and seqnum just a simple counter for this dump.
- * The status seems to be 1 by default but probably something to indicate
- * the status of a prefix would be more useful.
+ * The status field is unused and should be set to 1.
  */
 
 /* size of the dump header until attr_len */
@@ -186,10 +198,14 @@ enum MRT_BGP_TYPES {
 				   and announcements) */
 	MSG_BGP_PREF_UPDATE,	/* tlv preferences followed by raw update */
 	MSG_BGP_STATE_CHANGE,	/* state change */
-	MSG_BGP_SYNC
+	MSG_BGP_SYNC,		/* file name for a table dump */
+	MSG_BGP_OPEN,		/* BGP open messages */
+	MSG_BGP_NOTIFY,		/* BGP notify messages */
+	MSG_BGP_KEEPALIVE	/* BGP keepalives */
 };
 
-/* if type MSG_PROTOCOL_BGP and subtype MSG_BGP_UPDATE
+/* if type MSG_PROTOCOL_BGP and subtype MSG_BGP_UPDATE, MSG_BGP_OPEN,
+ * MSG_BGP_NOTIFY or MSG_BGP_KEEPALIVE
  *
  * +--------+--------+--------+--------+
  * |    source_as    |    source_ip
@@ -225,7 +241,7 @@ enum MRT_BGP_TYPES {
 /*
  * if type MSG_PROTOCOL_BGP and subtype MSG_BGP_SYNC OR
  * if type MSG_PROTOCOL_BGP4MP and subtype BGP4MP_SNAPSHOT
- * What is this for?
+ * *DEPRECATED*
  *
  * +--------+--------+--------+--------+
  * |      view       |    filename
@@ -255,22 +271,22 @@ enum mrt_state {
 };
 
 struct mrt {
-	enum mrt_type		type;
+	char			rib[PEER_DESCR_LEN];
+	struct msgbuf		wbuf;
+	LIST_ENTRY(mrt)		entry;
 	u_int32_t		peer_id;
 	u_int32_t		group_id;
-	u_int32_t		queued;
-	int			fd;
-	TAILQ_HEAD(, buf)	bufs;
-	LIST_ENTRY(mrt)		entry;
+	enum mrt_type		type;
+	enum mrt_state		state;
+	u_int16_t		seqnum;
 };
 
 struct mrt_config {
 	struct mrt		conf;
-	time_t			ReopenTimer;
-	time_t			ReopenTimerInterval;
-	enum mrt_state		state;
 	char			name[MRT_FILE_LEN];	/* base file name */
 	char			file[MRT_FILE_LEN];	/* actual file name */
+	time_t			ReopenTimer;
+	time_t			ReopenTimerInterval;
 };
 
 #define	MRT2MC(x)	((struct mrt_config *)(x))
@@ -278,16 +294,17 @@ struct mrt_config {
 
 struct peer;
 struct prefix;
-struct pt_entry;
+struct rib_entry;
 
 /* prototypes */
-int		 mrt_dump_bgp_msg(struct mrt *, void *, u_int16_t,
-		     struct peer *, struct bgpd_config *);
-int		 mrt_dump_state(struct mrt *, u_int16_t, u_int16_t,
-		     struct peer *, struct bgpd_config *);
+void		 mrt_dump_bgp_msg(struct mrt *, void *, u_int16_t,
+		     struct peer *);
+void		 mrt_dump_state(struct mrt *, u_int16_t, u_int16_t,
+		     struct peer *);
 void		 mrt_clear_seq(void);
-void		 mrt_dump_upcall(struct pt_entry *, void *);
-int		 mrt_write(struct mrt *);
+void		 mrt_dump_upcall(struct rib_entry *, void *);
+void		 mrt_dump_done(void *);
+void		 mrt_write(struct mrt *);
 void		 mrt_clean(struct mrt *);
 void		 mrt_init(struct imsgbuf *, struct imsgbuf *);
 int		 mrt_timeout(struct mrt_head *);
