--- metadata.c.orig	2022-08-30 05:42:54 UTC
+++ metadata.c
@@ -146,6 +146,11 @@ check_for_captions(const char *path, int64_t detailID)
 		strcpy(p, ".smi");
 		ret = access(file, R_OK);
 	}
+	if (ret != 0)
+	{
+		strcpy(p, ".ass");
+		ret = access(file, R_OK);
+	}
 
 	if (ret == 0)
 	{
