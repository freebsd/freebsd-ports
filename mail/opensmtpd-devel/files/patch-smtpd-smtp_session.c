--- smtpd/smtp_session.c.orig	2018-05-01 13:35:00.375262000 +0000
+++ smtpd/smtp_session.c	2018-05-01 13:37:22.637096000 +0000
@@ -1345,6 +1345,8 @@
 			s->dataeom = 1;
 			if (iobuf_queued(&s->obuf) == 0)
 				smtp_data_io_done(s);
+			else
+				io_reload(&s->oev);
 			return;
 		}
 
