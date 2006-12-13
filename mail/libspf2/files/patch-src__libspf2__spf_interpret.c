--- src/libspf2/spf_interpret.c.orig	Wed Dec 13 00:46:58 2006
+++ src/libspf2/spf_interpret.c	Wed Dec 13 00:47:23 2006
@@ -49,8 +49,8 @@
 	SPF_record_t	*spf_record;
 	SPF_errcode_t	 err;
 	char			*buf;
-	int				 buflen;
-	int				 len;
+	size_t				 buflen;
+	size_t				 len;
 
 	SPF_ASSERT_NOTNULL(spf_response);
 	spf_request = spf_response->spf_request;
