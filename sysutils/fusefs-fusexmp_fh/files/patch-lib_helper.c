--- lib/helper.c.orig	2012-04-10 15:28:55.000000000 +0200
+++ lib/helper.c	2012-07-31 00:06:11.384938678 +0200
@@ -31,7 +31,7 @@
 struct helper_opts {
 	int singlethread;
 	int foreground;
-	int nodefault_subtype;
+	int fsname;
 	char *mountpoint;
 };
 
@@ -42,8 +42,7 @@
 	FUSE_HELPER_OPT("debug",	foreground),
 	FUSE_HELPER_OPT("-f",		foreground),
 	FUSE_HELPER_OPT("-s",		singlethread),
-	FUSE_HELPER_OPT("fsname=",	nodefault_subtype),
-	FUSE_HELPER_OPT("subtype=",	nodefault_subtype),
+	FUSE_HELPER_OPT("fsname=",	fsname),
 
 	FUSE_OPT_KEY("-h",		KEY_HELP),
 	FUSE_OPT_KEY("--help",		KEY_HELP),
@@ -53,7 +52,6 @@
 	FUSE_OPT_KEY("-d",		FUSE_OPT_KEY_KEEP),
 	FUSE_OPT_KEY("debug",		FUSE_OPT_KEY_KEEP),
 	FUSE_OPT_KEY("fsname=",		FUSE_OPT_KEY_KEEP),
-	FUSE_OPT_KEY("subtype=",	FUSE_OPT_KEY_KEEP),
 	FUSE_OPT_END
 };
 
@@ -123,24 +121,24 @@
 	}
 }
 
-static int add_default_subtype(const char *progname, struct fuse_args *args)
+static int add_default_fsname(const char *progname, struct fuse_args *args)
 {
 	int res;
-	char *subtype_opt;
+	char *fsname_opt;
 	const char *basename = strrchr(progname, '/');
 	if (basename == NULL)
 		basename = progname;
 	else if (basename[1] != '\0')
 		basename++;
 
-	subtype_opt = (char *) malloc(strlen(basename) + 64);
-	if (subtype_opt == NULL) {
+	fsname_opt = (char *) malloc(strlen(basename) + 64);
+	if (fsname_opt == NULL) {
 		fprintf(stderr, "fuse: memory allocation failed\n");
 		return -1;
 	}
-	sprintf(subtype_opt, "-osubtype=%s", basename);
-	res = fuse_opt_add_arg(args, subtype_opt);
-	free(subtype_opt);
+	sprintf(fsname_opt, "-ofsname=%s", basename);
+	res = fuse_opt_add_arg(args, fsname_opt);
+	free(fsname_opt);
 	return res;
 }
 
@@ -156,8 +154,8 @@
 	if (res == -1)
 		return -1;
 
-	if (!hopts.nodefault_subtype) {
-		res = add_default_subtype(args->argv[0], args);
+	if (!hopts.fsname) {
+		res = add_default_fsname(args->argv[0], args);
 		if (res == -1)
 			goto err;
 	}
