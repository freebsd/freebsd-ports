--- libs/maildir/maildircreate.c.orig	2022-05-23 09:00:05 UTC
+++ libs/maildir/maildircreate.c
@@ -146,6 +146,7 @@ static int maildir_tmpcreate_fd_do(struct maildir_tmpc
 	strcat(info->tmpname, hostname);
 	strcat(info->tmpname, len_buf);
 
+	errno = 0;
 	if (stat( info->tmpname, &stat_buf) == 0)
 	{
 		maildir_tmpcreate_free(info);
@@ -153,7 +154,7 @@ static int maildir_tmpcreate_fd_do(struct maildir_tmpc
 		return -1;
 	}
 
-	if (errno != ENOENT)
+	if (errno != 0 && errno != ENOENT)
 	{
 		maildir_tmpcreate_free(info);
 		if (errno == EAGAIN)
