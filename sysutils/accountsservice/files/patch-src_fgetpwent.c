--- src/fgetpwent.c.orig	2014-03-15 15:05:11.000000000 +0100
+++ src/fgetpwent.c	2014-03-15 15:02:41.000000000 +0100
@@ -0,0 +1,108 @@
+/*
+ * Copyright (C) 2013 Canonical Limited
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; either version 3 of the licence, or
+ * (at your option) any later version.
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License
+ * along with this program; if not, write to the Free Software
+ * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
+ *
+ * Authors: Ryan Lortie <desrt@desrt.ca>
+ */
+
+static gchar *
+fgetpwent_getline (FILE *fp)
+{
+  static GString str;
+
+  /* We could be "more clever" here and avoid the strlen() but this is a
+   * clear case of dumb is better.
+   */
+  str.len = 0;
+  while (!str.len || str.str[str.len - 1] != '\n')
+    {
+      if (str.allocated_len < str.len + 32)
+        {
+          str.allocated_len = str.len + 32;
+          str.str = g_realloc (str.str, str.allocated_len);
+        }
+
+      if (fgets (str.str + str.len, str.allocated_len - str.len, fp) == NULL)
+        return NULL;
+
+      str.len = strlen (str.str + str.len) + str.len;
+    }
+
+  /* chomp the '\n' */
+  str.str[str.len - 1] = '\0';
+
+  return str.str;
+}
+
+static struct passwd *
+fgetpwent (FILE *fp)
+{
+  static struct passwd pw;
+  guint64 intval;
+  gchar *line;
+
+  /* In case of failure, we ignore the line and start again */
+again:
+  line = fgetpwent_getline (fp);
+  if (!line)
+    return NULL;
+
+  while (g_ascii_isspace (*line))
+    line++;
+
+  /* comments, empty lines */
+  if (line[0] == '#' || line[0] == '\0')
+    goto again;
+
+  /* username */
+  pw.pw_name = line;
+  if (!(line = strchr (line, ':')))
+    goto again;
+  *line++ = '\0';
+
+  /* password */
+  pw.pw_passwd = line;
+  if (!(line = strchr (line, ':')))
+    goto again;
+  *line++ = '\0';
+
+  /* uid */
+  pw.pw_uid = intval = g_ascii_strtoull (line, &line, 10);
+  if (pw.pw_uid != intval || *line++ != ':')
+    goto again;
+
+  /* gid */
+  pw.pw_gid = intval = g_ascii_strtoull (line, &line, 10);
+  if (pw.pw_gid != intval || *line++ != ':')
+    goto again;
+
+  /* gecos */
+  pw.pw_gecos = line;
+  if (!(line = strchr (line, ':')))
+    goto again;
+  *line++ = '\0';
+
+  /* home directory */
+  pw.pw_dir = line;
+  if (!(line = strchr (line, ':')))
+    goto again;
+  *line++ = '\0';
+
+  /* shell */
+  pw.pw_shell = line;
+
+  return &pw;
+}
