--- src/bin/lttng-sessiond/ust-metadata.c.orig	2017-01-09 19:26:28 UTC
+++ src/bin/lttng-sessiond/ust-metadata.c
@@ -50,6 +50,7 @@ int _lttng_field_statedump(struct ust_registry_session
 		const struct ustctl_field *fields, size_t nr_fields,
 		size_t *iter_field, size_t nesting);
 
+#if !defined(__FreeBSD__)
 static inline
 int fls(unsigned int x)
 {
@@ -79,6 +80,7 @@ int fls(unsigned int x)
 	}
 	return r;
 }
+#endif
 
 static inline
 int get_count_order(unsigned int count)
@@ -879,7 +881,7 @@ int ust_metadata_session_statedump(struct ust_registry
 	char uuid_s[UUID_STR_LEN],
 		clock_uuid_s[UUID_STR_LEN];
 	int ret = 0;
-	char hostname[HOST_NAME_MAX];
+	char hostname[_POSIX_HOST_NAME_MAX];
 
 	assert(session);
 
@@ -940,7 +942,7 @@ int ust_metadata_session_statedump(struct ust_registry
 	hostname[0] = '\0';
 	ret = gethostname(hostname, sizeof(hostname));
 	if (ret && errno == ENAMETOOLONG)
-		hostname[HOST_NAME_MAX - 1] = '\0';
+		hostname[_POSIX_HOST_NAME_MAX - 1] = '\0';
 	ret = lttng_metadata_printf(session,
 		"env {\n"
 		"	hostname = \"%s\";\n"
