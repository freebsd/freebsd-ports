--- src/bin/lttng-sessiond/ust-metadata.c.orig	2016-11-29 22:48:37 UTC
+++ src/bin/lttng-sessiond/ust-metadata.c
@@ -50,6 +50,7 @@ int _lttng_field_statedump(struct ust_re
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
@@ -879,6 +881,9 @@ int ust_metadata_session_statedump(struc
 	char uuid_s[UUID_STR_LEN],
 		clock_uuid_s[UUID_STR_LEN];
 	int ret = 0;
+#if defined(__FreeBSD__)
+	const size_t HOST_NAME_MAX = sysconf(_SC_HOST_NAME_MAX);
+#endif
 	char hostname[HOST_NAME_MAX];
 
 	assert(session);
