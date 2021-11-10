--- src/fts-xapian-plugin.c.orig	2021-11-10 13:11:59 UTC
+++ src/fts-xapian-plugin.c
@@ -30,7 +30,14 @@ static void fts_xapian_mail_user_created(struct mail_u
         fuser->set.lowmemory 	= XAPIAN_MIN_RAM;
         fuser->set.partial 	= XAPIAN_DEFAULT_PARTIAL;
         fuser->set.full 	= XAPIAN_DEFAULT_FULL;
-	
+
+#ifdef __FreeBSD__
+	size_t len = sizeof(fuser->set.pagesize);
+	sysctlbyname("hw.pagesize", &(fuser->set.pagesize), &len, NULL, 0);
+#else
+	fuser->set.pagesize = sysconf(_SC_PAGE_SIZE);
+#endif
+
 	const char * env = mail_user_plugin_getenv(user, "fts_xapian");
         if (env == NULL)
         {
@@ -93,7 +100,6 @@ static void fts_xapian_mail_user_created(struct mail_u
                 fuser->set.partial = XAPIAN_DEFAULT_PARTIAL;
                 fuser->set.full = XAPIAN_DEFAULT_FULL;
         }
-
 
 	if (fts_mail_user_init(user, FALSE, &error) < 0) i_error("FTS Xapian: %s", error);
 
