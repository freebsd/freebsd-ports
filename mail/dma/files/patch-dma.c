--- ./dma.c.orig	2010-08-10 17:48:35.000000000 +0200
+++ ./dma.c	2010-08-11 08:02:15.966237154 +0200
@@ -295,7 +295,7 @@
 			exit(1);
 		}
 		if (gettimeofday(&now, NULL) == 0 &&
-		    (now.tv_sec - st.st_mtim.tv_sec > MAX_TIMEOUT)) {
+		    (now.tv_sec - st.st_mtime > MAX_TIMEOUT)) {
 			asprintf(__DECONST(void *, &errmsg),
 				 "Could not deliver for the last %d seconds. Giving up.",
 				 MAX_TIMEOUT);
