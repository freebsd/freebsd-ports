--- src/ucs/vfs/fuse/vfs_fuse.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/vfs/fuse/vfs_fuse.c
@@ -37,6 +37,7 @@ static struct {
 
 static struct {
     pthread_t       thread_id;
+    int             thread_started;
     pthread_mutex_t mutex;
     struct fuse     *fuse;
     int             fuse_fd;
@@ -44,15 +45,20 @@ static struct {
     int             inotify_fd;
     int             watch_desc;
 } ucs_vfs_fuse_context = {
-    .thread_id  = -1,
-    .mutex      = PTHREAD_MUTEX_INITIALIZER,
-    .fuse       = NULL,
-    .fuse_fd    = -1,
-    .stop       = 0,
-    .inotify_fd = -1,
-    .watch_desc = -1
+    .thread_started = 0,
+    .mutex          = PTHREAD_MUTEX_INITIALIZER,
+    .fuse           = NULL,
+    .fuse_fd        = -1,
+    .stop           = 0,
+    .inotify_fd     = -1,
+    .watch_desc     = -1
 };
 
+static void ucs_vfs_sigusr1_handler(int signo)
+{
+    (void)signo;
+}
+
 static void ucs_vfs_enum_dir_cb(const char *name, void *arg)
 {
     ucs_vfs_enum_dir_context_t *ctx = arg;
@@ -492,10 +498,10 @@ static void ucs_fuse_thread_stop()
 
 static void ucs_fuse_thread_stop()
 {
-    sighandler_t orig_handler;
+    sig_t orig_handler;
     int ret;
 
-    orig_handler = signal(SIGUSR1, (sighandler_t)ucs_empty_function);
+    orig_handler = signal(SIGUSR1, ucs_vfs_sigusr1_handler);
 
     pthread_mutex_lock(&ucs_vfs_fuse_context.mutex);
 
@@ -518,15 +524,20 @@ static void ucs_fuse_thread_stop()
     if (ucs_vfs_fuse_context.fuse != NULL) {
         fuse_exit(ucs_vfs_fuse_context.fuse);
         ucs_fuse_replace_fd_devnull();
-        pthread_kill(ucs_vfs_fuse_context.thread_id, SIGUSR1);
+        if (ucs_vfs_fuse_context.thread_started) {
+            pthread_kill(ucs_vfs_fuse_context.thread_id, SIGUSR1);
+        }
     }
 
     pthread_mutex_unlock(&ucs_vfs_fuse_context.mutex);
 
-    ret = pthread_join(ucs_vfs_fuse_context.thread_id, NULL);
-    if (ret != 0) {
-        ucs_warn("pthread_join(0x%lx) failed: %m",
-                 ucs_vfs_fuse_context.thread_id);
+    if (ucs_vfs_fuse_context.thread_started) {
+        ret = pthread_join(ucs_vfs_fuse_context.thread_id, NULL);
+        if (ret != 0) {
+            ucs_warn("pthread_join(0x%lx) failed: %m",
+                     ucs_vfs_fuse_context.thread_id);
+        }
+        ucs_vfs_fuse_context.thread_started = 0;
     }
 
     signal(SIGUSR1, orig_handler);
@@ -536,11 +547,11 @@ static void ucs_vfs_fuse_atfork_child()
 {
     /* Reset thread context at fork, since doing inotify_rm_watch() from child
        will prevent doing it later from the parent */
-    ucs_vfs_fuse_context.thread_id  = -1;
-    ucs_vfs_fuse_context.fuse       = NULL;
-    ucs_vfs_fuse_context.fuse_fd    = -1;
-    ucs_vfs_fuse_context.inotify_fd = -1;
-    ucs_vfs_fuse_context.watch_desc = -1;
+    ucs_vfs_fuse_context.thread_started  = 0;
+    ucs_vfs_fuse_context.fuse            = NULL;
+    ucs_vfs_fuse_context.fuse_fd         = -1;
+    ucs_vfs_fuse_context.inotify_fd      = -1;
+    ucs_vfs_fuse_context.watch_desc      = -1;
 }
 
 void UCS_F_CTOR ucs_vfs_fuse_init()
@@ -549,12 +560,13 @@ void UCS_F_CTOR ucs_vfs_fuse_init()
         pthread_atfork(NULL, NULL, ucs_vfs_fuse_atfork_child);
         ucs_pthread_create(&ucs_vfs_fuse_context.thread_id,
                            ucs_vfs_fuse_thread_func, NULL, "fuse");
+        ucs_vfs_fuse_context.thread_started = 1;
     }
 }
 
 void UCS_F_DTOR ucs_vfs_fuse_cleanup()
 {
-    if (ucs_vfs_fuse_context.thread_id != -1) {
+    if (ucs_vfs_fuse_context.thread_started) {
         ucs_fuse_thread_stop();
     }
 }
