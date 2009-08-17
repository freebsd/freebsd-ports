From af0f8f8de27901e2efb9560a1fc66c7af3cd810b Mon Sep 17 00:00:00 2001
From: Johannes Berg <johannes@sipsolutions.net>
Date: Thu, 2 Jul 2009 14:17:54 +0200
Subject: [PATCH 1/1] make it compile with dovecot 1.2

---
 antispam-plugin.h |   13 +++++++++++++
 1 files changed, 13 insertions(+), 0 deletions(-)

diff --git a/antispam-plugin.h b/antispam-plugin.h
index df59e88..493fd1e 100644
--- antispam-plugin.h
+++ antispam-plugin.h
@@ -113,11 +113,24 @@ o_stream_create_from_fd(int fd, pool_t pool ATTR_UNUSED)
 	return o_stream_create_fd(fd, 0, TRUE);
 }
 
+#if DOVECOT_VERSION_CODE(1, 2) == DOVECOT_VERSION
+static inline struct dict *
+string_dict_init(const char *uri, const char *username)
+{
+	const char *base_dir;
+
+	base_dir = getenv("BASE_DIR");
+	if (base_dir == NULL)
+		base_dir = "/var/run/dovecot";
+	return dict_init(uri, DICT_DATA_TYPE_STRING, username, base_dir);
+}
+#else /* 1.1 */
 static inline struct dict *
 string_dict_init(const char *uri, const char *username)
 {
 	return dict_init(uri, DICT_DATA_TYPE_STRING, username);
 }
+#endif
 #elif DOVECOT_VERSION_CODE(1, 0) == DOVECOT_VERSION
 #define ME(err)
 #define PLUGIN_ID
-- 
1.6.3.3

