--- webmail/maildir.c.orig	2008-07-20 05:15:08.000000000 +0200
+++ webmail/maildir.c	2009-06-03 22:41:49.000000000 +0200
@@ -1091,6 +1091,42 @@
 	return (rc);
 }
 
+void maildir_msgmarkfile(const char *folder, const char *file, size_t pos)
+{
+char *filename=maildir_find(folder, file);
+char *new_filename;
+
+	if (filename)
+	{
+		if ((new_filename=maildir_addflagfilename(filename, 'F')) != 0)
+		{
+			rename(filename, new_filename);
+			update_foldermsgs(folder, new_filename, pos);
+			free(new_filename);
+		}
+
+		free(filename);
+	}
+}
+
+void maildir_msgunmarkfile(const char *folder, const char *file, size_t pos)
+{
+char *filename=maildir_find(folder, file);
+char *new_filename;
+
+	if (filename)
+	{
+		if ((new_filename = strdup(filename)) != 0)
+		{
+			maildir_remflagname(new_filename, 'F');
+			rename(filename, new_filename);
+			update_foldermsgs(folder, new_filename, pos);
+			free(new_filename);
+		}
+		free(filename);
+	}
+}
+
 static char *foldercountfilename(const char *folder)
 {
 	char *f=malloc(sizeof(MAILDIRCURCACHE "/cnt.") + strlen(folder));
@@ -1604,6 +1640,29 @@
 	return (MSGTYPE_NEW);
 }
 
+/*
+** maildirfile_flag(directory, filename) - boolean:
+**
+*/
+
+int maildirfile_flag(const char *p)
+{
+const char *q=strrchr(p, '/');
+int	seen_flag=0;
+
+	if (q)	p=q;
+
+	if ( !(p=strchr(p, ':')) || *++p != '2' || *++p != ',')
+		return (0);		/* No :2,info */
+
+	++p;
+	while (p && isalpha((int)(unsigned char)*p))
+		if (*p++ == 'F')
+			seen_flag=1;
+
+	return (seen_flag);
+}
+
 static int docount(const char *fn, unsigned *new_cnt, unsigned *other_cnt)
 {
 const char *filename=strrchr(fn, '/');
