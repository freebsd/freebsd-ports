--- imap/lmtp_sieve.c.orig	2015-10-17 06:54:40 UTC
+++ imap/lmtp_sieve.c
@@ -511,7 +511,7 @@ static int sieve_fileinto(void *ac, 
 	/* Try to deliver the mail again. */
         if (!ret)
             ret = deliver_mailbox(md->f, mdata->content, mdata->stage, md->size,
-                                  fc->imapflags->flag, fc->imapflags->nflags,
+                                  fc->imapflags,
                                   (char *) sd->username, sd->authstate, md->id,
                                   sd->username, mdata->notifyheader,
                                   namebuf, md->date, quotaoverride, 0);
