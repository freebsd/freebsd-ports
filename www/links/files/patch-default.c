--- default.c.orig	Wed Jan 30 06:53:48 2002
+++ default.c	Fri Apr 26 09:12:21 2002
@@ -265,7 +265,7 @@
 	get_system_name();
 	links_home = get_home(&first_use);
 	if (!links_home) {
-		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n\007");
+		fprintf(stderr, "Unable to find or create links config directory. Please check, that you have $HOME variable set correctly and that you have write permission to your home directory.\n");
 		sleep(3);
 		return;
 	}
@@ -697,6 +697,11 @@
 	anonymous = 1;
 	return NULL;
 }
+unsigned char *force_html_cmd(struct option *o, unsigned char ***argv, int *argc)
+{
+	force_html = 1;
+	return NULL;
+}
 unsigned char *dump_cmd(struct option *o, unsigned char ***argv, int *argc)
 {
 	if (dmp != o->min && dmp) return "Can't use both -dump and -source";
@@ -769,6 +774,9 @@
   is allowed, but user can't add or modify entries in\n\
   association table.\n\
 \n\
+ -force-html\n\
+  Treat file as if it had an .html extension.\n\
+\n\
  -dump\n\
   Write a plain-text version of the given HTML document to\n\
   stdout.\n\
@@ -826,6 +834,7 @@
 int no_connect = 0;
 int base_session = 0;
 int dmp = 0;
+int force_html = 0;
 
 int async_lookup = 1;
 int download_utime = 0;
@@ -877,6 +886,7 @@
 	1, no_connect_cmd, NULL, NULL, 0, 0, NULL, NULL, "no-connect",
 	1, anonymous_cmd, NULL, NULL, 0, 0, NULL, NULL, "anonymous",
 	1, gen_cmd, num_rd, NULL, 0, MAXINT, &base_session, NULL, "base-session",
+	1, force_html_cmd, NULL, NULL, 0, 0, NULL, NULL, "force-html",
 	1, dump_cmd, NULL, NULL, D_DUMP, 0, NULL, NULL, "dump",
 	1, dump_cmd, NULL, NULL, D_SOURCE, 0, NULL, NULL, "source",
 	1, gen_cmd, num_rd, num_wr, 0, 1, &async_lookup, "async_dns", "async-dns",
