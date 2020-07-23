--- src/dm_misc.c.orig	2020-06-29 22:53:45 UTC
+++ src/dm_misc.c
@@ -131,6 +131,10 @@ int drop_privileges(char *newuser, char *newgroup)
 
 int get_opened_fd_count(void)
 {
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__SUNPRO_C) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+	// BSD like systems don't use proc
+	return 0;
+#else
 	DIR* dir = NULL;
 	struct dirent* entry = NULL;
 	char buf[32];
@@ -147,6 +151,7 @@ int get_opened_fd_count(void)
 	closedir(dir);
 
 	return fd_count - 2; /* exclude '.' and '..' entries */
+#endif
 }
 
 void create_unique_id(char *target, uint64_t message_idnr)
