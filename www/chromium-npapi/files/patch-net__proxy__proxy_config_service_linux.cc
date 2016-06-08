--- ./net/proxy/proxy_config_service_linux.cc.orig	2014-04-30 22:43:07.000000000 +0200
+++ ./net/proxy/proxy_config_service_linux.cc	2014-05-04 14:38:48.000000000 +0200
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
@@ -846,9 +852,10 @@
                              public base::MessagePumpLibevent::Watcher {
  public:
   explicit SettingGetterImplKDE(base::Environment* env_var_getter)
-      : inotify_fd_(-1), notify_delegate_(NULL), indirect_manual_(false),
-        auto_no_pac_(false), reversed_bypass_list_(false),
-        env_var_getter_(env_var_getter), file_loop_(NULL) {
+      : inotify_fd_(-1), config_fd_(-1), notify_delegate_(NULL),
+        indirect_manual_(false),  auto_no_pac_(false),
+        reversed_bypass_list_(false), env_var_getter_(env_var_getter),
+        file_loop_(NULL) {
     // This has to be called on the UI thread (http://crbug.com/69057).
     base::ThreadRestrictions::ScopedAllowIO allow_io;
 
@@ -912,9 +919,10 @@
     // and pending tasks may then be deleted without being run.
     // Here in the KDE version, we can safely close the file descriptor
     // anyway. (Not that it really matters; the process is exiting.)
-    if (inotify_fd_ >= 0)
+    if (inotify_fd_ >= 0 || config_fd_ >= 0)
       ShutDown();
     DCHECK(inotify_fd_ < 0);
+    DCHECK(config_fd_ < 0);
   }
 
   virtual bool Init(base::SingleThreadTaskRunner* glib_thread_task_runner,
@@ -922,11 +930,21 @@
     // This has to be called on the UI thread (http://crbug.com/69057).
     base::ThreadRestrictions::ScopedAllowIO allow_io;
     DCHECK(inotify_fd_ < 0);
+#if defined(OS_FREEBSD)
+    inotify_fd_ = kqueue();
+#else
     inotify_fd_ = inotify_init();
+#endif
     if (inotify_fd_ < 0) {
+#if defined(OS_FREEBSD)
+      PLOG(ERROR) << "kqueue failed";
+#else
       PLOG(ERROR) << "inotify_init failed";
+#endif
       return false;
     }
+
+#if !defined(OS_FREEBSD)
     int flags = fcntl(inotify_fd_, F_GETFL);
     if (fcntl(inotify_fd_, F_SETFL, flags | O_NONBLOCK) < 0) {
       PLOG(ERROR) << "fcntl failed";
@@ -934,6 +952,7 @@
       inotify_fd_ = -1;
       return false;
     }
+#endif
     file_loop_ = file_loop;
     // The initial read is done on the current thread, not |file_loop_|,
     // since we will need to have it for SetUpAndFetchInitialConfig().
@@ -948,20 +967,38 @@
       close(inotify_fd_);
       inotify_fd_ = -1;
     }
+    if (config_fd_ >= 0) {
+      close(config_fd_);
+      config_fd_ = -1;
+    }
   }
 
   virtual bool SetUpNotifications(
       ProxyConfigServiceLinux::Delegate* delegate) OVERRIDE {
     DCHECK(inotify_fd_ >= 0);
+    DCHECK(config_fd_ >= 0);
     DCHECK(base::MessageLoop::current() == file_loop_);
     // We can't just watch the kioslaverc file directly, since KDE will write
     // a new copy of it and then rename it whenever settings are changed and
     // inotify watches inodes (so we'll be watching the old deleted file after
     // the first change, and it will never change again). So, we watch the
     // directory instead. We then act only on changes to the kioslaverc entry.
+#if defined(OS_FREEBSD)
+    config_fd_ = HANDLE_EINTR(open(kde_config_dir_.value().c_str(), O_RDONLY));
+
+    if (config_fd_ == -1)
+      return false;
+
+    struct kevent ev;
+    EV_SET(&ev, config_fd_, EVFILT_VNODE, EV_ADD | EV_CLEAR, NOTE_WRITE,
+            0, NULL);
+    if (kevent(inotify_fd_, &ev, 1, NULL, 0, NULL) == -1)
+      return false;
+#else
     if (inotify_add_watch(inotify_fd_, kde_config_dir_.value().c_str(),
                           IN_MODIFY | IN_MOVED_TO) < 0)
       return false;
+#endif
     notify_delegate_ = delegate;
     if (!file_loop_->WatchFileDescriptor(inotify_fd_,
                                          true,
@@ -982,7 +1019,19 @@
   virtual void OnFileCanReadWithoutBlocking(int fd) OVERRIDE {
     DCHECK_EQ(fd, inotify_fd_);
     DCHECK(base::MessageLoop::current() == file_loop_);
+#if defined(OS_FREEBSD)
+    struct kevent ev;
+    int rv = kevent(inotify_fd_, NULL, 0, &ev, 1, NULL);
+
+    if (rv != -1 && (ev.flags & EV_ERROR) == 0) {
+      OnChangeNotification();
+    } else {
+      LOG(ERROR) << "kevent() failure; no longer watching kioslaverc!";
+      ShutDown();
+    }
+#else
     OnChangeNotification();
+#endif
   }
   virtual void OnFileCanWriteWithoutBlocking(int fd) OVERRIDE {
     NOTREACHED();
@@ -1261,8 +1310,11 @@
   void OnChangeNotification() {
     DCHECK_GE(inotify_fd_,  0);
     DCHECK(base::MessageLoop::current() == file_loop_);
-    char event_buf[(sizeof(inotify_event) + NAME_MAX + 1) * 4];
     bool kioslaverc_touched = false;
+#if defined(OS_BSD)
+    kioslaverc_touched = true;
+#else
+    char event_buf[(sizeof(inotify_event) + NAME_MAX + 1) * 4];
     ssize_t r;
     while ((r = read(inotify_fd_, event_buf, sizeof(event_buf))) > 0) {
       // inotify returns variable-length structures, which is why we have
@@ -1299,6 +1351,7 @@
         inotify_fd_ = -1;
       }
     }
+#endif
     if (kioslaverc_touched) {
       // We don't use Reset() because the timer may not yet be running.
       // (In that case Stop() is a no-op.)
@@ -1314,6 +1367,7 @@
                    std::vector<std::string> > strings_map_type;
 
   int inotify_fd_;
+  int config_fd_;
   base::MessagePumpLibevent::FileDescriptorWatcher inotify_watcher_;
   ProxyConfigServiceLinux::Delegate* notify_delegate_;
   base::OneShotTimer<SettingGetterImplKDE> debounce_timer_;
