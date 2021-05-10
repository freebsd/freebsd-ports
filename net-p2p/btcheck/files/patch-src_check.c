--- src/check.c.orig	2017-08-26 19:37:29 UTC
+++ src/check.c
@@ -36,7 +36,7 @@ int check(btree_t *torrentbtree)
 	btfile_t *btfile;
 	void *piecebuffer, *piecedigest;
 	size_t size, length;
-	int ret, pieceindex, failure;
+	int ret, pieceindex, failure, numpieces;
 		
 	torrentinfo = search_dict_value(torrentbtree, TorrentInfoSearch);
 	if (torrentinfo == NULL) {
@@ -80,6 +80,7 @@ int check(btree_t *torrentbtree)
 		fprintf(stderr, "Can't open btfile.\n");
 	}
 	
+	numpieces = (torrentinfolength + torrentinfopiecelength - 1) / torrentinfopiecelength;
 	failure = 0;
 	pieceindex = 0;
 	readlength = 0;
@@ -99,10 +100,10 @@ int check(btree_t *torrentbtree)
 		}	
 		if (ret == 0) {
 			if (Verbose >= 0)
-				printf("\rpiece[%d] OK ", pieceindex);
+				printf("\rpiece[%d/%d] OK ", pieceindex, numpieces);
 		} else {
 			if (Verbose >= 0)
-				printf("\rpiece[%d] BAD \n", pieceindex);
+				printf("\rpiece[%d/%d] BAD \n", pieceindex, numpieces);
 			failure++;
 		}
 		fflush(stdout);
