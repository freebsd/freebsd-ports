Index: bgpd/imsg.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/imsg.c,v
retrieving revision 1.1.1.6
retrieving revision 1.1.1.7
diff -u -p -r1.1.1.6 -r1.1.1.7
--- bgpd/imsg.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/imsg.c	14 Feb 2010 20:27:06 -0000	1.1.1.7
@@ -1,4 +1,4 @@
-/*	$OpenBSD: imsg.c,v 1.47 2009/06/08 08:30:06 dlg Exp $	*/
+/*	$OpenBSD: imsg.c,v 1.48 2009/08/08 18:33:40 nicm Exp $	*/
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -263,6 +263,9 @@ imsg_flush(struct imsgbuf *ibuf)
 void
 imsg_clear(struct imsgbuf *ibuf)
 {
-	while (ibuf->w.queued)
-		msgbuf_clear(&ibuf->w);
+	int	fd;
+
+	msgbuf_clear(&ibuf->w);
+	while ((fd = imsg_get_fd(ibuf)) != -1)
+		close(fd);
 }
