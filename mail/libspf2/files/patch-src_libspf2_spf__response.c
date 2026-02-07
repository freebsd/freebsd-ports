--- src/libspf2/spf_response.c.orig	Tue Oct 19 11:05:19 2004
+++ src/libspf2/spf_response.c	Mon Mar 28 10:58:26 2005
@@ -132,6 +132,9 @@
 SPF_result_t
 SPF_response_result(SPF_response_t *rp)
 {
+	if (rp == NULL)
+		return SPF_RESULT_NONE;
+
 	return rp->result;
 }
 
