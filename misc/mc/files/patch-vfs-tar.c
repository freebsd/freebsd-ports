--- vfs/tar.c.orig	Sun Dec  8 07:12:30 2002
+++ vfs/tar.c	Tue Jun 15 03:15:09 2004
@@ -264,19 +264,26 @@
 	char *bp, *data;
 	int size, written;
 
+	if (hstat.st_size > MC_MAXPATHLEN) {
+	    message_1s (1, MSG_ERROR, _("Inconsistent tar archive"));
+	    return STATUS_BADCHECKSUM;
+	}
+
 	longp = ((header->header.linkflag == LF_LONGNAME)
 		 ? &next_long_name
 		 : &next_long_link);
 
 	if (*longp)
 	    g_free (*longp);
-	bp = *longp = g_malloc (hstat.st_size);
+	bp = *longp = g_malloc (hstat.st_size + 1);
 
 	for (size = hstat.st_size;
 	     size > 0;
 	     size -= written) {
 	    data = get_next_record (archive, tard)->charptr;
 	    if (data == NULL) {
+		g_free (*longp);
+		*longp = NULL;
 		message_1s (1, MSG_ERROR, _("Unexpected EOF on archive file"));
 		return STATUS_BADCHECKSUM;
 	    }
@@ -287,10 +294,14 @@
 	    memcpy (bp, data, written);
 	    bp += written;
 	}
-#if 0
-	if (hstat.st_size > 1)
-	    bp [hstat.st_size - 1] = 0;	/* just to make sure */
-#endif
+
+	if (bp - *longp == MC_MAXPATHLEN && bp[-1] != '\0') {
+	    g_free (*longp);
+	    *longp = NULL;
+	    message_1s (1, MSG_ERROR, _("Inconsistent tar archive"));
+	    return STATUS_BADCHECKSUM;
+	}	 
+	*bp = 0;
 	goto recurse;
     } else {
 	struct stat st;
