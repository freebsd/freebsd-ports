Index: bgpd/mrt.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/mrt.h,v
retrieving revision 1.1.1.6
retrieving revision 1.1.1.7
diff -u -p -r1.1.1.6 -r1.1.1.7
--- bgpd/mrt.h	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/mrt.h	14 Feb 2010 20:27:06 -0000	1.1.1.7
@@ -1,4 +1,4 @@
-/*	$OpenBSD: mrt.h,v 1.23 2009/06/29 12:22:16 claudio Exp $ */
+/*	$OpenBSD: mrt.h,v 1.24 2009/10/26 09:27:58 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -303,7 +303,7 @@ void		 mrt_dump_state(struct mrt *, u_in
 		     struct peer *);
 void		 mrt_clear_seq(void);
 void		 mrt_dump_upcall(struct rib_entry *, void *);
-void		 mrt_dump_done(void *);
+void		 mrt_done(void *);
 void		 mrt_write(struct mrt *);
 void		 mrt_clean(struct mrt *);
 void		 mrt_init(struct imsgbuf *, struct imsgbuf *);
