--- output.c.orig	2009-08-25 18:53:22 UTC
+++ output.c
@@ -119,15 +119,20 @@ EXPORT void write_metainfo(FILE *f, meta
 	printf("Writing metainfo file... ");
 	fflush(stdout);
 
-	/* every metainfo file is one big dictonary
-	   and the first entry is the announce URL */
-	fprintf(f, "d8:announce%lu:%s",
-		(unsigned long)strlen(m->announce_list->l->s),
-		m->announce_list->l->s);
-	/* write the announce-list entry if we have
-	   more than one announce URL */
-	if (m->announce_list->next || m->announce_list->l->next)
-		write_announce_list(f, m->announce_list);
+	/* every metainfo file is one big dictonary */
+	fprintf(f, "d");
+
+	/* first entry is the announce URL (optional) */
+	if (m->announce_list != NULL) {
+		fprintf(f, "8:announce%lu:%s",
+			(unsigned long)strlen(m->announce_list->l->s),
+			m->announce_list->l->s);
+		/* write the announce-list entry if we have
+		   more than one announce URL */
+		if (m->announce_list->next || m->announce_list->l->next)
+			write_announce_list(f, m->announce_list);
+	}
+
 	/* add the comment if one is specified */
 	if (m->comment != NULL)
 		fprintf(f, "7:comment%lu:%s",
