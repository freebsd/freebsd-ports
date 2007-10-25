--- ./src/prelude-failover.c.orig	Thu Aug 30 15:24:30 2007
+++ ./src/prelude-failover.c	Tue Oct 23 10:16:45 2007
@@ -292,7 +292,7 @@
         struct stat jst, wst;
         failover_journal_entry_t jentry;
 
-        failover->jfd = open(filename, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
+        failover->jfd = open(filename, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
         if ( failover->jfd < 0 )
                 return prelude_error_verbose(PRELUDE_ERROR_GENERIC, "could not open '%s': %s", filename, strerror(errno));
 
@@ -357,7 +357,7 @@
 {
         int ret;
 
-        *fd = open(filename, flags, S_IRUSR|S_IWUSR);
+        *fd = open(filename, flags, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
         if ( *fd < 0 )
                 return prelude_error_verbose(PRELUDE_ERROR_GENERIC, "error opening '%s': %s", filename, strerror(errno));
 
@@ -498,33 +498,46 @@
 
 int prelude_failover_new(prelude_failover_t **out, const char *dirname)
 {
+        mode_t mode;
         size_t flen;
         int ret, wfd, rfd;
         char filename[PATH_MAX];
         prelude_failover_t *new;
 
+        mode = umask(S_IRWXO);
+
         ret = mkdir(dirname, S_IRWXU|S_IRWXG);
-        if ( ret < 0 && errno != EEXIST )
+        if ( ret < 0 && errno != EEXIST ) {
+                umask(mode);
                 return prelude_error_verbose(PRELUDE_ERROR_GENERIC, "could not create directory '%s': %s", dirname, strerror(errno));
+        }
 
         wfd = get_failover_data_filename_and_fd(dirname, filename, sizeof(filename));
-        if ( wfd < 0 )
+        if ( wfd < 0 ) {
+                umask(mode);
                 return wfd;
+        }
 
         rfd = open(filename, O_RDONLY);
         if ( rfd < 0 ) {
+                umask(mode);
                 close(wfd);
                 return prelude_error_verbose(PRELUDE_ERROR_GENERIC, "could not open '%s' for reading: %s", filename, strerror(errno));
         }
 
         new = calloc(1, sizeof(*new));
-        if ( ! new )
+        if ( ! new ) {
+                umask(mode);
+                close(rfd);
+                close(wfd);
                 return prelude_error_from_errno(errno);
+        }
 
         new->jfd = -1;
 
         ret = prelude_io_new(&new->wfd);
         if ( ret < 0 ) {
+                umask(mode);
                 close(rfd);
                 close(wfd);
                 free(new);
@@ -533,6 +546,7 @@
 
         ret = prelude_io_new(&new->rfd);
         if ( ret < 0 ) {
+                umask(mode);
                 close(rfd);
                 close(wfd);
                 free(new);
@@ -546,16 +560,19 @@
 
         ret = snprintf(filename + flen, sizeof(filename) - flen, ".journal");
         if ( ret < 0 || ret >= (sizeof(filename) - flen) ) {
+                umask(mode);
                 prelude_failover_destroy(new);
                 return -1;
         }
 
         ret = journal_initialize(new, filename);
         if ( ret < 0 ) {
+                umask(mode);
                 prelude_failover_destroy(new);
                 return ret;
         }
 
+        umask(mode);
         *out = new;
 
         return 0;
