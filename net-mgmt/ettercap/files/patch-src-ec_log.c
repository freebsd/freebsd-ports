Obtained from:	https://github.com/Ettercap/ettercap/commit/42600aada0ba56b9c63dabcc2b0cb1417fa27863

--- src/ec_log.c.orig	2014-10-17 01:29:44.000000000 +0800
+++ src/ec_log.c	2015-02-21 19:58:20.733803628 +0800
@@ -37,8 +37,11 @@
 
 /* globals */
 
-static struct log_fd fdp;
-static struct log_fd fdi;
+/* zero is formally a valid value for an opened file descriptor
+ * so we need a custom initializer
+ */
+static struct log_fd fdp = {0, NULL, -1};
+static struct log_fd fdi = {0, NULL, -1};
 
 /* protos */
 
@@ -79,7 +82,7 @@
    /* all the host type will be unknown, warn the user */
    if (GBL_OPTIONS->read) {
       USER_MSG("*********************************************************\n");
-      USER_MSG("WARNING: while reading form file we cannot determine    \n");
+      USER_MSG("WARNING: while reading form file we cannot determine     \n");
       USER_MSG("if an host is local or not because the ip address of     \n");
       USER_MSG("the NIC may have been changed from the time of the dump. \n");
       USER_MSG("*********************************************************\n\n");
@@ -168,23 +171,30 @@
 
 /*
  * open a file in the appropriate log_fd struct
+ *
+ * whether or not the log is compressed
+ * fd->fd becomes to always be a file descriptor of the opened file
+ * and fd->cfd is a non-NULL gzip stream descriptor when the log is to be compressed
+ *
+ * TODO: it is likely that we dont need 'type' field in 'log_fd' struct
+ *       to mark a compressed log; non-NULL 'cfd' field becomes such a flag
  */
 int log_open(struct log_fd *fd, char *filename)
 {
-   int zerr;
 
-   if (fd->type == LOG_COMPRESSED) {
-      fd->cfd = gzopen(filename, "wb9");
-      if (fd->cfd == NULL)
-         SEMIFATAL_ERROR("%s", gzerror(fd->cfd, &zerr));
-   } else {
-      fd->fd = open(filename, O_CREAT | O_TRUNC | O_RDWR | O_BINARY, S_IRUSR | S_IWUSR);
-      if (fd->fd == -1)
-         SEMIFATAL_ERROR("Can't create %s: %s", filename, strerror(errno));
-   }
-   
-   /* set the permissions */
-   chmod(filename, 0600);
+   fd->fd = open(filename, O_CREAT|O_TRUNC|O_RDWR|O_BINARY, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
+   if (fd->fd == -1)
+      SEMIFATAL_ERROR("Can't create %s: %s", filename, strerror(errno));
+   else
+   {
+      if (GBL_OPTIONS->compress)
+      {
+         int zerr;
+         fd->cfd = gzdopen(fd->fd, "wb9");
+         if (fd->cfd == NULL)
+            SEMIFATAL_ERROR("%s", gzerror(fd->cfd, &zerr));
+      };
+   };
 
    return E_SUCCESS;
 }
@@ -195,14 +205,66 @@
 void log_close(struct log_fd *fd)
 {
    DEBUG_MSG("log_close: type: %d [%p][%d]", fd->type, fd->cfd, fd->fd);
-   
-   if (fd->type == LOG_COMPRESSED && fd->cfd) {
+
+   if (fd->cfd)
+   {
+      /* gzclose() on the gzip stream descriptor (fd->cfd)
+       * will also close the file descriptor (fd->fd)
+       */
       gzclose(fd->cfd);
       fd->cfd = NULL;
-   } else if (fd->type == LOG_UNCOMPRESSED && fd->fd) {
+      fd->fd = -1;  /* to prevent double closing the file descriptor */
+   };
+
+   if (fd->fd >= 0)
+   {
       close(fd->fd);
-      fd->fd = 0;
-   }
+      fd->fd = -1;
+   };
+}
+
+/*
+ * set the owner:group of the packet and info logfiles to new_uid:new_gid
+ * if the current owners are old_uid:old_gid respectively
+ *
+ * prefer this way to unconditionally setting the new ownership as far as
+ * the file may be intentionally located in the set-group-ID directory
+ */
+void reset_logfile_owners(uid_t old_uid, gid_t old_gid, uid_t new_uid, gid_t new_gid)
+{
+   struct stat f;
+   uid_t uid;
+   gid_t gid;
+
+   /* packet logfile */
+   if (fdp.fd >= 0)
+   {
+      DEBUG_MSG("reset_logfile_owners: packet log file");
+      if (fstat(fdp.fd, &f) == 0)
+      {
+         uid = (f.st_uid == old_uid) ? new_uid : (uid_t)-1;
+         gid = (f.st_gid == old_gid) ? new_gid : (gid_t)-1;
+         if ( fchown(fdp.fd, uid, gid) != 0 )
+            ERROR_MSG("fchown()");
+      }
+      else
+         ERROR_MSG("fstat()");
+   };
+
+   /* info logfile */
+   if (fdi.fd >= 0)
+   {
+      DEBUG_MSG("reset_logfile_owners: info log file");
+      if (fstat(fdi.fd, &f) == 0)
+      {
+         uid = (f.st_uid == old_uid) ? new_uid : (uid_t)-1;
+         gid = (f.st_gid == old_gid) ? new_gid : (gid_t)-1;
+         if ( fchown(fdi.fd, uid, gid) != 0 )
+            ERROR_MSG("fchown()");
+      }
+      else
+         ERROR_MSG("fstat()");
+   };
 }
 
 /* 
