--- net/proxy/proxy_config_service_linux.cc.orig	2011-04-04 10:01:16.000000000 +0200
+++ net/proxy/proxy_config_service_linux.cc	2011-04-11 00:23:55.000000000 +0200
@@ -12,7 +12,13 @@
 #include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
+#if defined(OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/event.h>
+#include <sys/time.h>
+#else
 #include <sys/inotify.h>
+#endif
 #include <unistd.h>
 
 #include <map>
@@ -433,7 +439,7 @@
       public base::MessagePumpLibevent::Watcher {
  public:
   explicit GConfSettingGetterImplKDE(base::Environment* env_var_getter)
-      : inotify_fd_(-1), notify_delegate_(NULL), indirect_manual_(false),
+      : notify_fd_(-1), notify_delegate_(NULL), indirect_manual_(false),
         auto_no_pac_(false), reversed_bypass_list_(false),
         env_var_getter_(env_var_getter), file_loop_(NULL) {
     // This has to be called on the UI thread (http://crbug.com/69057).
@@ -492,33 +498,37 @@
   }
 
   virtual ~GConfSettingGetterImplKDE() {
-    // inotify_fd_ should have been closed before now, from
+    // notify_fd_ should have been closed before now, from
     // Delegate::OnDestroy(), while running on the file thread. However
     // on exiting the process, it may happen that Delegate::OnDestroy()
     // task is left pending on the file loop after the loop was quit,
     // and pending tasks may then be deleted without being run.
     // Here in the KDE version, we can safely close the file descriptor
     // anyway. (Not that it really matters; the process is exiting.)
-    if (inotify_fd_ >= 0)
+    if (notify_fd_ >= 0)
       Shutdown();
-    DCHECK(inotify_fd_ < 0);
+    DCHECK(notify_fd_ < 0);
   }
 
   virtual bool Init(MessageLoop* glib_default_loop,
                     MessageLoopForIO* file_loop) {
     // This has to be called on the UI thread (http://crbug.com/69057).
     base::ThreadRestrictions::ScopedAllowIO allow_io;
-    DCHECK(inotify_fd_ < 0);
-    inotify_fd_ = inotify_init();
-    if (inotify_fd_ < 0) {
+    DCHECK(notify_fd_ < 0);
+#if defined(OS_FREEBSD)
+    notify_fd_ = kqueue();
+#else
+    notify_fd_ = inotify_init();
+#endif
+    if (notify_fd_ < 0) {
       PLOG(ERROR) << "inotify_init failed";
       return false;
     }
-    int flags = fcntl(inotify_fd_, F_GETFL);
-    if (fcntl(inotify_fd_, F_SETFL, flags | O_NONBLOCK) < 0) {
+    int flags = fcntl(notify_fd_, F_GETFL);
+    if (fcntl(notify_fd_, F_SETFL, flags | O_NONBLOCK) < 0) {
       PLOG(ERROR) << "fcntl failed";
-      close(inotify_fd_);
-      inotify_fd_ = -1;
+      close(notify_fd_);
+      notify_fd_ = -1;
       return false;
     }
     file_loop_ = file_loop;
@@ -529,28 +539,41 @@
   }
 
   void Shutdown() {
-    if (inotify_fd_ >= 0) {
+    if (notify_fd_ >= 0) {
       ResetCachedSettings();
-      inotify_watcher_.StopWatchingFileDescriptor();
-      close(inotify_fd_);
-      inotify_fd_ = -1;
+      notify_watcher_.StopWatchingFileDescriptor();
+      close(notify_fd_);
+      notify_fd_ = -1;
     }
   }
 
   bool SetupNotification(ProxyConfigServiceLinux::Delegate* delegate) {
-    DCHECK(inotify_fd_ >= 0);
+    DCHECK(notify_fd_ >= 0);
     DCHECK(file_loop_);
+#if defined(OS_FREEBSD)
+    // catch the deletion event of kioslaverc
+    int kioslavercfd = open(kde_config_dir_.Append("kioslaverc").value().c_str(), O_RDONLY);
+    if (kioslavercfd == -1)
+      return false;
+
+    struct kevent ke;
+    EV_SET(&ke, kioslavercfd, EVFILT_VNODE, EV_ADD | EV_ONESHOT, NOTE_DELETE | NOTE_RENAME, 0, NULL);
+
+    if (kevent(notify_fd_, &ke, 1, NULL, 0, NULL) == -1)
+      return false;
+#else
     // We can't just watch the kioslaverc file directly, since KDE will write
     // a new copy of it and then rename it whenever settings are changed and
     // inotify watches inodes (so we'll be watching the old deleted file after
     // the first change, and it will never change again). So, we watch the
     // directory instead. We then act only on changes to the kioslaverc entry.
-    if (inotify_add_watch(inotify_fd_, kde_config_dir_.value().c_str(),
+    if (inotify_add_watch(notify_fd_, kde_config_dir_.value().c_str(),
                           IN_MODIFY | IN_MOVED_TO) < 0)
       return false;
+#endif
     notify_delegate_ = delegate;
-    return file_loop_->WatchFileDescriptor(inotify_fd_, true,
-        MessageLoopForIO::WATCH_READ, &inotify_watcher_, this);
+    return file_loop_->WatchFileDescriptor(notify_fd_, true,
+        MessageLoopForIO::WATCH_READ, &notify_watcher_, this);
   }
 
   virtual MessageLoop* GetNotificationLoop() {
@@ -559,7 +582,7 @@
 
   // Implement base::MessagePumpLibevent::Delegate.
   void OnFileCanReadWithoutBlocking(int fd) {
-    DCHECK(fd == inotify_fd_);
+    DCHECK(fd == notify_fd_);
     DCHECK(MessageLoop::current() == file_loop_);
     OnChangeNotification();
   }
@@ -830,12 +853,24 @@
   // from the inotify file descriptor and starts up a debounce timer if
   // an event for kioslaverc is seen.
   void OnChangeNotification() {
-    DCHECK(inotify_fd_ >= 0);
+    DCHECK(notify_fd_ >= 0);
     DCHECK(MessageLoop::current() == file_loop_);
+#if defined(OS_FREEBSD)
+    bool kioslaverc_touched = true;
+    struct kevent ke;
+    if (kevent(notify_fd_, NULL, 0, &ke, 1, NULL) == -1) {
+      LOG(ERROR) << "kevent() failure: no longer watching kioslaverc";
+      notify_watcher_.StopWatchingFileDescriptor();
+      close(notify_fd_);
+      notify_fd_ = -1;
+      kioslaverc_touched = false;
+    }
+    close(ke.ident);
+#else
     char event_buf[(sizeof(inotify_event) + NAME_MAX + 1) * 4];
     bool kioslaverc_touched = false;
     ssize_t r;
-    while ((r = read(inotify_fd_, event_buf, sizeof(event_buf))) > 0) {
+    while ((r = read(notify_fd_, event_buf, sizeof(event_buf))) > 0) {
       // inotify returns variable-length structures, which is why we have
       // this strange-looking loop instead of iterating through an array.
       char* event_ptr = event_buf;
@@ -865,9 +900,9 @@
         // large), but if it does we'd warn continuously since |inotify_fd_|
         // would be forever ready to read. Close it and stop watching instead.
         LOG(ERROR) << "inotify failure; no longer watching kioslaverc!";
-        inotify_watcher_.StopWatchingFileDescriptor();
-        close(inotify_fd_);
-        inotify_fd_ = -1;
+        notify_watcher_.StopWatchingFileDescriptor();
+        close(notify_fd_);
+        notify_fd_ = -1;
       }
     }
     if (kioslaverc_touched) {
@@ -883,8 +918,8 @@
   typedef std::map<std::string, std::string> string_map_type;
   typedef std::map<std::string, std::vector<std::string> > strings_map_type;
 
-  int inotify_fd_;
-  base::MessagePumpLibevent::FileDescriptorWatcher inotify_watcher_;
+  int notify_fd_;
+  base::MessagePumpLibevent::FileDescriptorWatcher notify_watcher_;
   ProxyConfigServiceLinux::Delegate* notify_delegate_;
   base::OneShotTimer<GConfSettingGetterImplKDE> debounce_timer_;
   FilePath kde_config_dir_;
