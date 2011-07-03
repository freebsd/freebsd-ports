Index: bgpd/mrt.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/mrt.h,v
retrieving revision 1.1.1.6
retrieving revision 1.1.1.8
diff -u -p -r1.1.1.6 -r1.1.1.8
--- bgpd/mrt.h	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/mrt.h	12 Jun 2011 10:44:25 -0000	1.1.1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: mrt.h,v 1.23 2009/06/29 12:22:16 claudio Exp $ */
+/*	$OpenBSD: mrt.h,v 1.27 2010/06/04 10:13:00 claudio Exp $ */
 
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
 
@@ -75,8 +73,10 @@ enum MRT_BGP4MP_TYPES {
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
@@ -184,6 +184,7 @@ enum MRT_BGP4MP_TYPES {
 
 /* size of the dump header until attr_len */
 #define MRT_DUMP_HEADER_SIZE	22
+#define MRT_DUMP_HEADER_SIZE_V6	46
 
 /*
  * OLD MRT message headers. These structs are here for completion but
@@ -235,7 +236,7 @@ enum MRT_BGP_TYPES {
  * |    new_state    |
  * +--------+--------+
  *
- * State are defined in RFC 1771.
+ * State are defined in RFC 1771/4271.
  */
 
 /*
@@ -303,7 +304,7 @@ void		 mrt_dump_state(struct mrt *, u_in
 		     struct peer *);
 void		 mrt_clear_seq(void);
 void		 mrt_dump_upcall(struct rib_entry *, void *);
-void		 mrt_dump_done(void *);
+void		 mrt_done(void *);
 void		 mrt_write(struct mrt *);
 void		 mrt_clean(struct mrt *);
 void		 mrt_init(struct imsgbuf *, struct imsgbuf *);
