--- src/lib/librumpuser/sp_common.c.orig	2025-09-09 03:27:37 UTC
+++ src/lib/librumpuser/sp_common.c
@@ -701,15 +701,21 @@ static int
 
 /*ARGSUSED*/
 static int
-notsupp(void)
+addrparse_notsupp(const char *addr __unused, struct sockaddr **sa __unused,
+		  int allow_wildcard __unused)
 {
 
 	fprintf(stderr, "rump_sp: support not yet implemented\n");
 	return EOPNOTSUPP;
 }
 
+static void
+cleanup_success(struct sockaddr *sa __unused)
+{
+}
+
 static int
-success(void)
+connecthook_success(int s __unused)
 {
 
 	return 0;
@@ -724,12 +730,12 @@ static struct {
 	cleanup_fn cleanup;
 } parsetab[] = {
 	{ "tcp", PF_INET, sizeof(struct sockaddr_in),
-	    tcp_parse, tcp_connecthook, (cleanup_fn)success },
+	    tcp_parse, tcp_connecthook, cleanup_success },
 	{ "unix", PF_LOCAL, sizeof(struct sockaddr_un),
-	    unix_parse, (connecthook_fn)success, unix_cleanup },
+	    unix_parse, connecthook_success, unix_cleanup },
 	{ "tcp6", PF_INET6, sizeof(struct sockaddr_in6),
-	    (addrparse_fn)notsupp, (connecthook_fn)success,
-	    (cleanup_fn)success },
+	    addrparse_notsupp, connecthook_success,
+	    cleanup_success },
 };
 #define NPARSE (sizeof(parsetab)/sizeof(parsetab[0]))
 
