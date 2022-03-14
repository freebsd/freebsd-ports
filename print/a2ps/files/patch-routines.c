--- lib/routines.c.orig	1999-10-16 04:46:37 UTC
+++ lib/routines.c
@@ -242,3 +242,50 @@ unlink2 (PARAM_UNUSED void * dummy, const char * filen
   /* Don't complain if you can't unlink.  Who cares of a tmp file? */
   unlink (filename);
 }
+
+/*
+ * Securely generate a temp file, and make sure it gets
+ * deleted upon exit.
+ */
+static char **	tempfiles;
+static unsigned	ntempfiles;
+
+static void
+cleanup_tempfiles()
+{
+	while (ntempfiles--)
+		unlink(tempfiles[ntempfiles]);
+}
+
+char *
+safe_tempnam(const char *pfx)
+{
+	char	*dirname, *filename;
+	int	fd;
+
+	if (!(dirname = getenv("TMPDIR")))
+		dirname = "/tmp";
+
+	tempfiles = (char **) realloc(tempfiles,
+			(ntempfiles+1) * sizeof(char *));
+	if (tempfiles == NULL)
+		return NULL;
+
+	filename = malloc(strlen(dirname) + strlen(pfx) + sizeof("/XXXXXX"));
+	if (!filename)
+		return NULL;
+
+	sprintf(filename, "%s/%sXXXXXX", dirname, pfx);
+
+	if ((fd = mkstemp(filename)) < 0) {
+		free(filename);
+		return NULL;
+	}
+	close(fd);
+
+	if (ntempfiles == 0)
+		atexit(cleanup_tempfiles);
+	tempfiles[ntempfiles++] = filename;
+
+	return filename;
+}
