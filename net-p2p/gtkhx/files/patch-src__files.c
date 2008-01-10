--- src/files.c.orig	Tue Apr  8 05:05:31 2003
+++ src/files.c	Sun Jan  6 01:52:06 2008
@@ -1000,7 +1000,7 @@
 	gtk_hlist_clear(GTK_HLIST(files_list));
 
 	for (fh = cfl->fh; (guint32)((char *)fh - (char *)cfl->fh) < cfl->fhlen;
-		 (char *)fh += fh->len + SIZEOF_HL_DATA_HDR) {
+		 fh = (char *)fh + fh->len + SIZEOF_HL_DATA_HDR) {
 		fh->fnlen = ntohl(fh->fnlen);
 		fh->len = ntohs(fh->len);
 		fh->fsize = ntohl(fh->fsize);
@@ -1304,7 +1304,7 @@
 		return 0;
 
 	for (fh = cfl->fh; (guint32)((char *)fh - (char *)cfl->fh) < cfl->fhlen;
-		 (char *)fh += fh->len + SIZEOF_HL_DATA_HDR) {
+		 fh = (char *)fh + fh->len + SIZEOF_HL_DATA_HDR) {
 		if ((int)fh->fnlen == len && !strncmp(fh->fname, ent, len))
 			return 1;
 	}
