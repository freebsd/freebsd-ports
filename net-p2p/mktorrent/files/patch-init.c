--- init.c.orig	2009-08-25 18:53:22 UTC
+++ init.c
@@ -277,7 +277,7 @@ static void print_help()
 	  "Options:\n"
 #ifdef USE_LONG_OPTIONS
 	  "-a, --announce=<url>[,<url>]* : specify the full announce URLs\n"
-	  "                                at least one is required\n"
+	  "                                at least one is required on private torrent\n"
 	  "                                additional -a adds backup trackers\n"
 	  "-c, --comment=<comment>       : add a comment to the metainfo\n"
 	  "-d, --no-date                 : don't write the creation date\n"
@@ -298,7 +298,7 @@ static void print_help()
 	  "                                additional -w adds more URLs\n"
 #else
 	  "-a <url>[,<url>]* : specify the full announce URLs\n"
-	  "                    at least one is required\n"
+	  "                    at least one is required on private torrent\n"
 	  "                    additional -a adds backup trackers\n"
 	  "-c <comment>      : add a comment to the metainfo\n"
 	  "-d                : don't write the creation date\n"
@@ -343,7 +343,7 @@ static void print_announce_list(llist_t 
  */
 static void print_web_seed_list(slist_t *list)
 {
-	printf("  Web Seed URL: ");
+	printf("  Web Seed URLs: ");
 
 	if (list == NULL) {
 		printf("none\n");
@@ -361,17 +361,20 @@ static void print_web_seed_list(slist_t 
 static void dump_options(metafile_t *m)
 {
 	printf("Options:\n"
-	       "  Announce URLs:\n");
+	       "  Announce URLs:");
 
-	print_announce_list(m->announce_list);
+	if (m->announce_list) {
+		printf("\n");
+		print_announce_list(m->announce_list);
+	} else
+		printf(" none\n");
 
-	printf("  Torrent name: %s\n"
-	       "  Metafile:     %s\n"
-	       "  Piece length: %u\n"
-	       "  Be verbose:   yes\n",
+	printf("  Torrent name:  %s\n"
+	       "  Metafile:      %s\n"
+	       "  Piece length:  %u\n",
 	       m->torrent_name, m->metainfo_file_path, m->piece_length);
 
-	printf("  Write date:   ");
+	printf("  Write date:    ");
 	if (m->no_creation_date)
 		printf("no\n");
 	else
@@ -379,11 +382,17 @@ static void dump_options(metafile_t *m)
 
 	print_web_seed_list(m->web_seed_list);
 
-	printf("  Comment:      ");
+	printf("  Comment:       ");
 	if (m->comment == NULL)
-		printf("none\n\n");
+		printf("none\n");
 	else
-		printf("\"%s\"\n\n", m->comment);
+		printf("\"%s\"\n", m->comment);
+
+	printf("  Private:       ");
+	if (m->private)
+		printf("yes\n\n");
+	else
+		printf("no\n\n");
 }
 
 /*
@@ -495,22 +504,25 @@ EXPORT void init(metafile_t *m, int argc
 
 	/* set the correct piece length.
 	   default is 2^18 = 256kb. */
-	if (m->piece_length < 15 || m->piece_length > 28) {
+	if (m->piece_length < 15 || m->piece_length > 30) {
 		fprintf(stderr,
 			"The piece length must be a number between "
-			"15 and 28.\n");
+			"15 and 30.\n");
 		exit(EXIT_FAILURE);
 	}
 	m->piece_length = 1 << m->piece_length;
 
-	/* user must specify at least one announce URL as it wouldn't make
-	 * any sense to have a default for this */
+	/* user must specify at least one announce URL when private flag set
+	   as it wouldn't make any sense to have a default for this */
 	if (m->announce_list == NULL) {
-		fprintf(stderr, "Must specify an announce URL. "
-			"Use -h for help.\n");
-		exit(EXIT_FAILURE);
+		if (m->private == 1) {
+			fprintf(stderr, "Must specify an announce URL. "
+					"Use -h for help.\n");
+			exit(EXIT_FAILURE);
+		}
+	} else {
+		announce_last->next = NULL;
 	}
-	announce_last->next = NULL;
 
 	/* ..and a file or directory from which to create the torrent */
 	if (optind >= argc) {
