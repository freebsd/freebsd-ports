--- chunkTab.cxx.orig	Sat Dec 11 18:33:22 2004
+++ chunkTab.cxx	Fri Sep 30 11:29:15 2005
@@ -142,7 +142,7 @@
 	off_t part,nparts;
 	chunk* tempchunk = new chunk;
 	tempchunk->file = 0;
-	tempchunk->from = -1;
+	tempchunk->from = 0;
 	tempchunk->to = -1;
 	tempchunk->to_included = false;
 	tempchunk->from_included = false;
@@ -626,7 +626,7 @@
 	for (i = 1; i <= n; i++) {
 		tempchunk = new chunk;
 		tempchunk->file = 0;
-		tempchunk->from = -1;
+		tempchunk->from = 0;
 		tempchunk->to = -1;
 		tempchunk->to_included = true;
 		tempchunk->from_included = false;

