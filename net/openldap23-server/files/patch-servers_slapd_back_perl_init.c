--- servers/slapd/back-perl/init.c.orig	Fri Aug 18 16:01:34 2006
+++ servers/slapd/back-perl/init.c	Fri Aug 18 16:04:28 2006
@@ -35,7 +35,9 @@
 	BackendInfo	*bi
 )
 {
-	bi->bi_open = perl_back_open;
+	char *embedding[] = { "", "-e", "0" };
+
+	bi->bi_open = NULL;
 	bi->bi_config = 0;
 	bi->bi_close = perl_back_close;
 	bi->bi_destroy = 0;
@@ -63,16 +65,8 @@
 	bi->bi_connection_init = 0;
 	bi->bi_connection_destroy = 0;
 
-	return 0;
-}
-		
-int
-perl_back_open(
-	BackendInfo	*bi
-)
-{
-	char *embedding[] = { "", "-e", "0" };
 
+	// injecting code from perl_back_open, because using fonction reference  (bi->bi_open) is not fonctionnal
 	Debug( LDAP_DEBUG_TRACE, "perl backend open\n", 0, 0, 0 );
 
 	if( PERL_INTERPRETER != NULL ) {
