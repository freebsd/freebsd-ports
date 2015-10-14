diff --git a/src/libutil/addr.c b/src/libutil/addr.c
index 5958e9e..7d0d5fe 100644
--- src/libutil/addr.c
+++ src/libutil/addr.c
@@ -279,7 +279,7 @@ static gboolean
 rspamd_parse_unix_path (rspamd_inet_addr_t **target, const char *src)
 {
 	gchar **tokens, **cur_tok, *p, *pwbuf;
-	gint pwlen;
+	glong pwlen;
 	struct passwd pw, *ppw;
 	struct group gr, *pgr;
 	rspamd_inet_addr_t *addr;
@@ -299,8 +299,15 @@ rspamd_parse_unix_path (rspamd_inet_addr_t **target, const char *src)
 	addr->u.un->group = (gid_t)-1;
 
 	cur_tok = &tokens[1];
+#ifdef _SC_GETPW_R_SIZE_MAX
 	pwlen = sysconf (_SC_GETPW_R_SIZE_MAX);
-	g_assert (pwlen > 0);
+	if (pwlen <= 0) {
+		pwlen = 8192;
+	}
+#else
+	pwlen = 8192;
+#endif
+
 	pwbuf = g_alloca (pwlen);
 
 	while (*cur_tok) {
