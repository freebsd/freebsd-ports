--- src/manual.c.orig	2021-07-01 13:36:26 UTC
+++ src/manual.c
@@ -182,7 +182,7 @@ set_initial_history(char *name)
 		char buf[1024];
 		char *str, *lastSlash, *lastButOneSlash;
 		FILE *pathFile;
-		snprintf(buf, sizeof(buf), "man -w -W %s %s", ManOptions, name);
+		snprintf(buf, sizeof(buf), "man -w %s %s", ManOptions, name);
 		pathFile = popen(buf, "r");
 		if (fgets(buf, sizeof(buf), pathFile)==NULL)
 		{
