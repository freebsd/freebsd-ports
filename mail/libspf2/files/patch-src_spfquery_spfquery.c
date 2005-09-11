--- src/spfquery/spfquery.c.orig	Thu Jul 28 19:04:46 2005
+++ src/spfquery/spfquery.c	Thu Jul 28 19:04:54 2005
@@ -261,7 +261,7 @@
 response_print_errors(const char *context,
 				SPF_response_t *spf_response, SPF_errcode_t err)
 {
-	SPF_error_t		*spf_error;;
+	SPF_error_t		*spf_error;
 	int				 i;
 
 	printf("StartError\n");
