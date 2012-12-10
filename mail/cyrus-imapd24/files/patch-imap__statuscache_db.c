Index: imap/statuscache_db.c
diff -u -p imap/statuscache_db.c.orig imap/statuscache_db.c
--- imap/statuscache_db.c.orig	2012-12-02 04:57:54.000000000 +0900
+++ imap/statuscache_db.c	2012-12-10 13:17:11.621360294 +0900
@@ -150,9 +150,11 @@ static char *statuscache_buildkey(const 
 
     /* Build statuscache key */
     len = strlcpy(key, mailboxname, sizeof(key));
+    /* double % is a safe separator, it can't exist in a mailboxname */
     key[len++] = '%';
     key[len++] = '%';
-    len += strlcpy(key + len, userid, sizeof(key) - len);
+    if (userid)
+	len += strlcpy(key + len, userid, sizeof(key) - len);
 
     *keylen = len;
 
@@ -410,11 +412,9 @@ int statuscache_invalidate(const char *m
     drock.db = statuscachedb;
     drock.tid = NULL;
 
-    key = statuscache_buildkey(mboxname, "", &keylen);
+    key = statuscache_buildkey(mboxname, /*userid*/NULL, &keylen);
 
-    /* strip off the second NULL that buildkey added, so we match 
-     * the entires for all users */
-    r = DB->foreach(drock.db, key, keylen - 1, NULL, delete_cb,
+    r = DB->foreach(drock.db, key, keylen, NULL, delete_cb,
 		    &drock, &drock.tid);
     if (r != CYRUSDB_OK) {
 	syslog(LOG_ERR, "DBERROR: error invalidating: %s (%s)",
