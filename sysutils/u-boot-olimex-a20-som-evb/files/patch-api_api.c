--- api/api.c.orig	2016-07-11 19:01:01 UTC
+++ api/api.c
@@ -290,6 +290,14 @@ static int API_dev_close(va_list ap)
 	if (!err)
 		di->state = DEV_STA_CLOSED;
 
+	/*
+	 * FreeBSD loader(8) just loaded code to some random location that may
+	 * contain stale icache entries.  Now that the device is closed it's
+	 * about to run that code, so clean the caches.
+	 */
+	flush_dcache_all();
+	invalidate_icache_all();
+
 	return err;
 }
 
@@ -495,45 +503,48 @@ static int API_env_set(va_list ap)
  */
 static int API_env_enum(va_list ap)
 {
-	int i, n;
-	char *last, **next;
+	int i, buflen;
+	char *last, **next, *s;
+	ENTRY *match, search;
+	static char *buf;
 
 	last = (char *)va_arg(ap, unsigned long);
 
 	if ((next = (char **)va_arg(ap, uintptr_t)) == NULL)
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
-		}
-	}
-
-	return 0;
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
+ 		}
+ 	}
+ 
+	/* hmatch on empty string is effectively "get next entry after i". */
+	if ((i = hmatch_r("", i, &match, &env_htab)) == 0)
+		goto done;
+	buflen = strlen(match->key) + strlen(match->data) + 2;
+	buf = realloc(buf, buflen);
+	snprintf(buf, buflen, "%s=%s", match->key, match->data);
+	*next = buf;
+ 	return 0;
+done:
+	free(buf);
+	buf = NULL;
+	*next = NULL;
+	return i;
 }
 
 /*
