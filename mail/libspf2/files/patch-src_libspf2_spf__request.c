--- src/libspf2/spf_request.c.orig	Mon Feb 21 23:38:57 2005
+++ src/libspf2/spf_request.c	Mon Mar 28 10:37:52 2005
@@ -307,6 +307,9 @@
 	char			*record;
 	size_t			 len;
 
+	if ( (spf_request == NULL) || (rcpt_to == NULL) )
+		return SPF_E_INVALID_OPT;
+
 	SPF_ASSERT_NOTNULL(spf_request);
 	spf_server = spf_request->spf_server;
 	SPF_ASSERT_NOTNULL(spf_server);
