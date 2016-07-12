--- api/api.c.orig	2016-04-12 02:22:25 UTC
+++ api/api.c
@@ -495,45 +495,49 @@ static int API_env_set(va_list ap)
  */
 static int API_env_enum(va_list ap)
 {
-	int i, n;
-	char *last, **next;
+	int i;
+	char *last, **next, *s;
+	ENTRY *match, search;
+	static char *buf;
+	size_t buflen;
 
 	last = (char *)va_arg(ap, u_int32_t);
 
 	if ((next = (char **)va_arg(ap, u_int32_t)) == NULL)
 		return API_EINVAL;
 
-	if (last == NULL)
-		/* start over */
-		*next = ((char *)env_get_addr(0));
-	else {
-		*next = last;
-
-		for (i = 0; env_get_char(i) != '\0'; i = n + 1) {
-			for (n = i; env_get_char(n) != '\0'; ++n) {
-				if (n >= CONFIG_ENV_SIZE) {
-					/* XXX shouldn't we set *next = NULL?? */
-					return 0;
-				}
-			}
-
-			if (envmatch((uchar *)last, i) < 0)
-				continue;
-
-			/* try to get next name */
-			i = n + 1;
-			if (env_get_char(i) == '\0') {
-				/* no more left */
-				*next = NULL;
-				return 0;
-			}
-
-			*next = ((char *)env_get_addr(i));
-			return 0;
+	/*
+	 * This leverages realloc's behavior of growing but never shrinking the
+	 * existing buffer.
+	 */
+	if (last == NULL) {
+		i = 0;
+		buf = realloc(buf, 512); /* Start with reasonable size buf. */
+	} else {
+		buf = realloc(buf, strlen(last) + 1);
+		strcpy(buf, last);
+		if ((s = strchr(buf, '=')) != NULL)
+		     *s = 0;
+		search.key = buf;
+		if ((i = hsearch_r(search, FIND, &match, &env_htab, 0)) == 0) {
+			i = API_EINVAL;
+			goto done;
 		}
 	}
 
+	/* hmatch on empty string is effectively "get next entry after i". */
+	if ((i = hmatch_r("", i, &match, &env_htab)) == 0)
+		goto done;
+	buflen = strlen(match->key) + strlen(match->data) + 2;
+	buf = realloc(buf, buflen);
+	snprintf(buf, buflen, "%s=%s", match->key, match->data);
+	*next = buf;
 	return 0;
+done:
+	free(buf);
+	buf = NULL;
+	*next = NULL;
+	return i;
 }
 
 /*
