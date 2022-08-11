--- src/properties.c.orig	2022-06-28 06:17:34 UTC
+++ src/properties.c
@@ -406,8 +406,8 @@ get_properties(char *filename, const int dsize)
 	if (colorize == 1)
 		printf("%s", cend);
 
-#if defined(__OpenBSD__) || defined(__APPLE__)
-	printf(_("\tBlocks: %s%lld%s"), cbold, attr.st_blocks, cend);
+#if defined(__OpenBSD__) || defined(__APPLE__) || defined(__FreeBSD__)
+	printf(_("\tBlocks: %s%lld%s"), cbold, (long long)attr.st_blocks, cend);
 #else
 	printf(_("\tBlocks: %s%ld%s"), cbold, attr.st_blocks, cend);
 #endif
@@ -417,15 +417,15 @@ get_properties(char *filename, const int dsize)
 #else
 	printf(_("\tIO Block: %s%ld%s"), cbold, attr.st_blksize, cend);
 #endif
-#if defined(__OpenBSD__) || defined(__APPLE__)
-	printf(_("\tInode: %s%llu%s\n"), cbold, attr.st_ino, cend);
+#if defined(__OpenBSD__) || defined(__APPLE__) || defined(__FreeBSD__)
+	printf(_("\tInode: %s%llu%s\n"), cbold, (unsigned long long)attr.st_ino, cend);
 #else
 	printf(_("\tInode: %s%zu%s\n"), cbold, attr.st_ino, cend);
 #endif
 #if defined(__OpenBSD__) || defined(__APPLE__)
 	printf(_("Device: %s%d%s"), cbold, attr.st_dev, cend);
 #else
-	printf(_("Device: %s%zu%s"), cbold, attr.st_dev, cend);
+	printf(_("Device: %s%zu%s"), cbold, (size_t)attr.st_dev, cend);
 #endif
 	printf(_("\tUid: %s%u (%s)%s"), cid, attr.st_uid, !owner ? _("unknown")
 			: owner->pw_name, cend);
