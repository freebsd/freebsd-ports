Index: bgpd/imsg.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/imsg.c,v
retrieving revision 1.1.1.6
retrieving revision 1.1.1.8
diff -u -p -r1.1.1.6 -r1.1.1.8
--- bgpd/imsg.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/imsg.c	10 Apr 2010 12:13:04 -0000	1.1.1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: imsg.c,v 1.47 2009/06/08 08:30:06 dlg Exp $	*/
+/*	$OpenBSD: imsg.c,v 1.49 2010/04/07 18:09:39 nicm Exp $	*/
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -79,7 +79,7 @@ imsg_read(struct imsgbuf *ibuf)
 		    cmsg->cmsg_type == SCM_RIGHTS) {
 			fd = (*(int *)CMSG_DATA(cmsg));
 			if ((ifd = calloc(1, sizeof(struct imsg_fd))) == NULL) {
-				/* XXX: this return can leak */
+				close(fd);
 				return (-1);
 			}
 			ifd->fd = fd;
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
