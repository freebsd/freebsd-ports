--- ./src/libhydra/plugins/kernel_pfroute/kernel_pfroute_net.c.orig	2014-06-26 09:10:00.000000000 +0200
+++ ./src/libhydra/plugins/kernel_pfroute/kernel_pfroute_net.c	2014-08-19 09:48:46.000000000 +0200
@@ -1518,8 +1518,8 @@
 			{	/* timed out? */
 				break;
 			}
-			if (this->reply->rtm_msglen < sizeof(*this->reply) ||
-				msg.hdr.rtm_seq != this->reply->rtm_seq)
+			if ((this->reply == 0) || (this->reply->rtm_msglen < sizeof(*this->reply) ||
+				msg.hdr.rtm_seq != this->reply->rtm_seq))
 			{
 				continue;
 			}
