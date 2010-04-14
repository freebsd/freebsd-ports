--- ./rdup-tr.c.orig	2010-04-04 13:23:22.000000000 -0700
+++ ./rdup-tr.c	2010-04-08 20:21:36.000000000 -0700
@@ -100,7 +100,8 @@
 	struct archive_entry *entry;
 	struct stat     *s;
 	struct rdup  *rdup_entry = NULL;
-	GSList *hlinks, *hl      = NULL;
+	GSList *hlinks = NULL;
+	GSList *hl = NULL;
 	GHashTable *trhash;		/* look up for encrypted/decrypted strs */
 
 	delim   = '\n';
