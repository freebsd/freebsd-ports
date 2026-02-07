Description: Fix a bug in checking a memory allocation's result.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- lib/mhash.c.orig
+++ lib/mhash.c
@@ -299,7 +299,7 @@
 	{
 		ret->hmac_key = (mutils_word8 *) mutils_malloc(ret->hmac_key_size);
 
-		if (ret == NULL)
+		if (ret->hmac_key == NULL)
 		{
 			mutils_free(ret->state);
 			mutils_free(ret);
