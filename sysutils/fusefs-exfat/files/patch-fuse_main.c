--- fuse/main.c.orig	2021-11-24 20:45:02 UTC
+++ fuse/main.c
@@ -451,7 +451,7 @@ static char* add_ro_option(char* options, bool ro)
 	return ro ? add_option(options, "ro", NULL) : options;
 }
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__)
 static char* add_user_option(char* options)
 {
 	struct passwd* pw;
@@ -492,12 +492,10 @@ static char* add_fuse_options(char* options, const cha
 	options = add_ro_option(options, ro);
 	if (options == NULL)
 		return NULL;
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__)
 	options = add_user_option(options);
 	if (options == NULL)
 		return NULL;
-#endif
-#if defined(__linux__)
 	options = add_blksize_option(options, CLUSTER_SIZE(*ef.sb));
 	if (options == NULL)
 		return NULL;
