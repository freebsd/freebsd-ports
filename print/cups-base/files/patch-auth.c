--- scheduler/auth.c.orig	2008-03-03 20:49:42.000000000 +0300
+++ scheduler/auth.c	2008-03-03 20:53:19.000000000 +0300
@@ -652,8 +652,7 @@
 	    {
 	      cupsdLogMessage(CUPSD_LOG_ERROR,
 	                      "cupsdAuthorize: pam_start() returned %d (%s)!\n",
-        	              pamerr, pam_strerror(pamh, pamerr));
-	      pam_end(pamh, 0);
+        	              pamerr, pam_strerror(NULL, pamerr));
 	      return;
 	    }
 
