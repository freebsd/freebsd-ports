Buffer handling:
- convert a strncpy() to snprintf() to ensure null-termination;
- explicitly pass sizeof(var) as the second argument of snprintf().

--- a/backfill.c
+++ b/backfill.c
@@ -56,7 +56,7 @@
 		return(-1);
 #endif
 	/*- format a new string */
-	snprintf(bak_file, MAX_BUFF, "%s.bak", filename);
+	snprintf(bak_file, sizeof(bak_file), "%s.bak", filename);
 	if (rename(filename, bak_file))
 	{
 		fprintf(stderr, "rename %s->%s: %s\n", filename, bak_file, strerror(errno));
@@ -155,7 +155,7 @@
 		fprintf(stderr, "%s: No such domain\n", domain);
 		return((char *) 0);
 	}
-	snprintf(filename, MAX_BUFF, "%s/.dir_control_free", ptr);
+	snprintf(filename, sizeof(filename), "%s/.dir_control_free", ptr);
 	if (operation == 1) /*- Delete */
 	{
 		if (!(fp = fopen(filename, "r")))
@@ -193,7 +193,7 @@
 	} else
 	if (operation == 2) /*- add */
 	{
-		(void) strncpy(tmpbuf, path, MAX_BUFF);
+		snprintf(tmpbuf, sizeof(tmpbuf), "%s", path);
 		if ((ptr = strstr(tmpbuf, username)))
 		{
 			if (ptr != tmpbuf)
