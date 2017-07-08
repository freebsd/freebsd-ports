--- net/proxy/proxy_config_service_linux.cc.orig	2017-06-05 19:03:10 UTC
+++ net/proxy/proxy_config_service_linux.cc
@@ -11,7 +11,14 @@
 #include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
+#if defined(OS_FREEBSD)
+#include <fcntl.h>
+#include <sys/types.h>
+#include <sys/event.h>
+#include <sys/time.h>
+#else
 #include <sys/inotify.h>
+#endif
 #include <unistd.h>
 
 #include <map>
@@ -863,6 +870,7 @@ class SettingGetterImplKDE : public ProxyConfigService
  public:
   explicit SettingGetterImplKDE(base::Environment* env_var_getter)
       : inotify_fd_(-1),
+        config_fd_(-1),
         inotify_watcher_(FROM_HERE),
         notify_delegate_(nullptr),
         debounce_timer_(new base::OneShotTimer()),
@@ -938,9 +946,10 @@ class SettingGetterImplKDE : public ProxyConfigService
     // and pending tasks may then be deleted without being run.
     // Here in the KDE version, we can safely close the file descriptor
     // anyway. (Not that it really matters; the process is exiting.)
-    if (inotify_fd_ >= 0)
+    if (inotify_fd_ >= 0 || config_fd_ >= 0)
       ShutDown();
     DCHECK_LT(inotify_fd_, 0);
+    DCHECK_LT(config_fd_, 0);
   }
 
   bool Init(const scoped_refptr<base::SingleThreadTaskRunner>& glib_task_runner,
@@ -949,9 +958,17 @@ class SettingGetterImplKDE : public ProxyConfigService
     // This has to be called on the UI thread (http://crbug.com/69057).
     base::ThreadRestrictions::ScopedAllowIO allow_io;
     DCHECK_LT(inotify_fd_, 0);
+#if defined(OS_BSD)
+    inotify_fd_ = kqueue();
+#else
     inotify_fd_ = inotify_init();
+#endif
     if (inotify_fd_ < 0) {
+#if defined(OS_BSD)
+      PLOG(ERROR) << "kqueue failed";
+#else
       PLOG(ERROR) << "inotify_init failed";
+#endif
       return false;
     }
     if (!base::SetNonBlocking(inotify_fd_)) {
@@ -975,22 +992,40 @@ class SettingGetterImplKDE : public ProxyConfigService
       close(inotify_fd_);
       inotify_fd_ = -1;
     }
+    if (config_fd_ >= 0) {
+      close(config_fd_);
+      config_fd_ = -1;
+    }
     debounce_timer_.reset();
   }
 
   bool SetUpNotifications(
       ProxyConfigServiceLinux::Delegate* delegate) override {
     DCHECK_GE(inotify_fd_, 0);
+    DCHECK_GE(config_fd_, 0);
     DCHECK(file_task_runner_->BelongsToCurrentThread());
     // We can't just watch the kioslaverc file directly, since KDE will write
     // a new copy of it and then rename it whenever settings are changed and
     // inotify watches inodes (so we'll be watching the old deleted file after
     // the first change, and it will never change again). So, we watch the
     // directory instead. We then act only on changes to the kioslaverc entry.
+#if defined(OS_BSD)
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
                           IN_MODIFY | IN_MOVED_TO) < 0) {
       return false;
     }
+#endif
     notify_delegate_ = delegate;
     if (!base::MessageLoopForIO::current()->WatchFileDescriptor(
             inotify_fd_, true, base::MessageLoopForIO::WATCH_READ,
@@ -1011,7 +1046,19 @@ class SettingGetterImplKDE : public ProxyConfigService
   void OnFileCanReadWithoutBlocking(int fd) override {
     DCHECK_EQ(fd, inotify_fd_);
     DCHECK(file_task_runner_->BelongsToCurrentThread());
+#if defined(OS_BSD)
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
   void OnFileCanWriteWithoutBlocking(int fd) override { NOTREACHED(); }
 
@@ -1284,8 +1331,11 @@ class SettingGetterImplKDE : public ProxyConfigService
   void OnChangeNotification() {
     DCHECK_GE(inotify_fd_,  0);
     DCHECK(file_task_runner_->BelongsToCurrentThread());
-    char event_buf[(sizeof(inotify_event) + NAME_MAX + 1) * 4];
     bool kioslaverc_touched = false;
+#if defined(OS_BSD)
+    kioslaverc_touched = true;
+#else
+    char event_buf[(sizeof(inotify_event) + NAME_MAX + 1) * 4];
     ssize_t r;
     while ((r = read(inotify_fd_, event_buf, sizeof(event_buf))) > 0) {
       // inotify returns variable-length structures, which is why we have
@@ -1322,6 +1372,7 @@ class SettingGetterImplKDE : public ProxyConfigService
         inotify_fd_ = -1;
       }
     }
+#endif
     if (kioslaverc_touched) {
       // We don't use Reset() because the timer may not yet be running.
       // (In that case Stop() is a no-op.)
@@ -1337,6 +1388,7 @@ class SettingGetterImplKDE : public ProxyConfigService
                    std::vector<std::string> > strings_map_type;
 
   int inotify_fd_;
+  int config_fd_;
   base::MessagePumpLibevent::FileDescriptorWatcher inotify_watcher_;
   ProxyConfigServiceLinux::Delegate* notify_delegate_;
   std::unique_ptr<base::OneShotTimer> debounce_timer_;
