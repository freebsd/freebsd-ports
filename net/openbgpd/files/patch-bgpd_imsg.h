Index: bgpd/imsg.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/imsg.h,v
retrieving revision 1.1.1.5
retrieving revision 1.1.1.6
diff -u -p -r1.1.1.5 -r1.1.1.6
--- bgpd/imsg.h	14 Feb 2010 20:19:57 -0000	1.1.1.5
+++ bgpd/imsg.h	14 Feb 2010 20:27:06 -0000	1.1.1.6
@@ -90,6 +90,7 @@ void		 buf_free(struct buf *);
 void		 msgbuf_init(struct msgbuf *);
 void		 msgbuf_clear(struct msgbuf *);
 int		 msgbuf_write(struct msgbuf *);
+void		 msgbuf_drain(struct msgbuf *, size_t);
 
 /* imsg.c */
 void	 imsg_init(struct imsgbuf *, int);
