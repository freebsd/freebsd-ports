--- ./src/modules/rlm_detail/rlm_detail.c.orig	2011-08-09 23:23:35.000000000 -0400
+++ ./src/modules/rlm_detail/rlm_detail.c	2011-08-09 23:25:09.000000000 -0400
@@ -463,11 +463,11 @@
 	 */
 	if (fflush(fp) != 0) {
 		ftruncate(outfd, fsize); /* ignore errors! */
-		close(outfd);
+		fclose(fp);
 		return RLM_MODULE_FAIL;
 	}
 
-	close(outfd);
+	fclose(fp);
 
 	/*
 	 *	And everything is fine.
