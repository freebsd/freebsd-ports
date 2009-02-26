--- spamd/grey.c.orig	2009-02-26 13:27:35.159368721 -0500
+++ spamd/grey.c	2009-02-26 13:31:07.469474893 -0500
@@ -376,7 +376,7 @@
 	static char buf[MAX_MAIL];
 	char *cp;
 
-	if (*addr == '<');
+	if (*addr == '<')
 		addr++;
 	(void) strlcpy(buf, addr, sizeof(buf));
 	cp = strrchr(buf, '>');
@@ -398,8 +398,11 @@
 	size_t len;
 	struct mail_addr *m;
 
-	while (!SLIST_EMPTY(&match_suffix))
+	while (!SLIST_EMPTY(&match_suffix)) {
+		m = SLIST_FIRST(&match_suffix);
 		SLIST_REMOVE_HEAD(&match_suffix, entry);
+		free(m);
+	}
 	if ((fp = fopen(alloweddomains_file, "r")) != NULL) {
 		while ((buf = fgetln(fp, &len))) {
 #ifdef __FreeBSD__
@@ -410,11 +413,11 @@
 				buf++;
 				len--;
 			}
+			if (len == 0)
+				continue;
 			/* jump over comments and blank lines */
 			if (*buf == '#' || *buf == '\n')
 				continue;
-			if (len == 0)
-				continue;
 #endif
 			if (buf[len-1] == '\n')
 				len--;
@@ -434,8 +437,11 @@
 	}
 	return;
 bad:
-	while (!SLIST_EMPTY(&match_suffix))
+	while (!SLIST_EMPTY(&match_suffix)) {
+		m = SLIST_FIRST(&match_suffix);
 		SLIST_REMOVE_HEAD(&match_suffix, entry);
+		free(m);
+	}
 }
 
 void
@@ -609,6 +615,7 @@
 		dbc->act = 0;
 		dbc->dsiz = 0;
 		SLIST_REMOVE_HEAD(&db_changes, entry);
+		free(dbc);
 
 	}
 	return(ret);
@@ -795,7 +802,7 @@
 
 	now = time(NULL);
 	/* expiry times have to be in the future */
-	expire = strtonum(expires, now, UINT_MAX, NULL);
+	expire = strtonum(expires, now, INT_MAX, NULL);
 	if (expire == 0)
 		return(-1);
 
