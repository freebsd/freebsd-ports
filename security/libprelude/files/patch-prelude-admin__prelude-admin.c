--- ./prelude-admin/prelude-admin.c.orig	Mon Oct  1 12:47:42 2007
+++ ./prelude-admin/prelude-admin.c	Tue Oct 23 10:16:42 2007
@@ -69,7 +69,6 @@
 #ifdef WIN32
 # define chown(x, y, z) (0)
 # define fchown(x, y, z) (0)
-# define fchmod(x, y) (0)
 # define getuid(x) (0)
 # define getgid(x) (0)
 # define mkdir(x, y) mkdir(x)
@@ -710,10 +709,6 @@
                 return -1;
         }
 
-        ret = fchmod(fileno(fd), S_IRUSR|S_IWUSR|S_IRGRP);
-        if ( ret < 0 )
-                fprintf(stderr, "error changing '%s' permission: %s.\n", filename, strerror(errno));
-
         ret = fchown(fileno(fd), prelude_client_profile_get_uid(profile), prelude_client_profile_get_gid(profile));
         if ( ret < 0 )
                 fprintf(stderr, "error changing '%s' ownership: %s.\n", filename, strerror(errno));
@@ -752,19 +747,18 @@
 
         already_exist = access(filename, F_OK);
 
-        fd = fopen(filename, (already_exist == 0) ? "r" : "w");
-        if ( ! fd ) {
-                fprintf(stderr, "error opening %s: %s.\n", filename, strerror(errno));
+        ret = open(filename, (already_exist == 0) ? O_RDONLY : O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP);
+        if ( ret < 0 ) {
+                fprintf(stderr, "error opening '%s': %s.\n", filename, strerror(errno));
                 return -1;
         }
 
-        ret = fchown(fileno(fd), prelude_client_profile_get_uid(profile), prelude_client_profile_get_gid(profile));
-        if ( ret < 0 )
-                fprintf(stderr, "couldn't change %s owner.\n", filename);
-
-        ret = fchmod(fileno(fd), S_IRUSR|S_IWUSR|S_IRGRP);
-        if ( ret < 0 )
-                fprintf(stderr, "couldn't make ident file readable for all.\n");
+        fd = fdopen(ret, (already_exist == 0) ? "r" : "w");
+        if ( ! fd ) {
+                close(ret);
+                fprintf(stderr, "error opening '%s': %s.\n", filename, strerror(errno));
+                return -1;
+        }
 
         if ( already_exist == 0 ) {
                 if ( ! fgets(buf, sizeof(buf), fd) ) {
@@ -945,11 +939,11 @@
 
 
 
-static int create_directory(prelude_client_profile_t *profile, const char *dirname)
+static int create_directory(prelude_client_profile_t *profile, const char *dirname, int flags)
 {
         int ret;
 
-        ret = mkdir(dirname, S_IRWXU|S_IRWXG);
+        ret = mkdir(dirname, flags);
         if ( ret < 0 && errno != EEXIST ) {
                 fprintf(stderr, "error creating directory %s: %s.\n", dirname, strerror(errno));
                 return -1;
@@ -977,7 +971,7 @@
 
         prelude_client_profile_get_profile_dirname(profile, buf, sizeof(buf));
 
-        ret = create_directory(profile, buf);
+        ret = create_directory(profile, buf, S_IRWXU|S_IRGRP|S_IXGRP);
         if ( ret < 0 ) {
                 fprintf(stderr, "error creating directory %s: %s.\n", buf, strerror(errno));
                 return -1;
@@ -1000,7 +994,7 @@
         prelude_client_profile_set_analyzerid(profile, *analyzerid);
 
         prelude_client_profile_get_backup_dirname(profile, buf, sizeof(buf));
-        return create_directory(profile, buf);
+        return create_directory(profile, buf, S_IRWXU|S_IRWXG);
 }
 
 
@@ -2128,6 +2122,8 @@
 #ifndef WIN32
         signal(SIGPIPE, SIG_IGN);
 #endif
+
+        umask(S_IRWXO);
 
         for ( i = 0; i < sizeof(tbl) / sizeof(*tbl); i++ ) {
                 if ( strcmp(tbl[i].cmd, argv[1]) != 0 )
