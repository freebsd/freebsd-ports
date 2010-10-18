--- ./dma.c.orig	2010-10-04 21:03:33.000000000 +0200
+++ ./dma.c	2010-10-18 13:25:47.331077938 +0200
@@ -293,7 +293,7 @@
 			exit(1);
 		}
 		if (gettimeofday(&now, NULL) == 0 &&
-		    (now.tv_sec - st.st_mtim.tv_sec > MAX_TIMEOUT)) {
+		    (now.tv_sec - st.st_mtime > MAX_TIMEOUT)) {
 			asprintf(__DECONST(void *, &errmsg),
 				 "Could not deliver for the last %d seconds. Giving up.",
 				 MAX_TIMEOUT);
