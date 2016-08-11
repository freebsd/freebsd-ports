--- net/proxy/proxy_config_service_linux.cc.orig	2016-05-11 19:02:24 UTC
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
@@ -859,6 +866,7 @@ class SettingGetterImplKDE : public Prox
  public:
   explicit SettingGetterImplKDE(base::Environment* env_var_getter)
       : inotify_fd_(-1),
+        config_fd_(-1),
         notify_delegate_(NULL),
         debounce_timer_(new base::OneShotTimer()),
         indirect_manual_(false),
@@ -933,9 +941,10 @@ class SettingGetterImplKDE : public Prox
     // and pending tasks may then be deleted without being run.
     // Here in the KDE version, we can safely close the file descriptor
     // anyway. (Not that it really matters; the process is exiting.)
-    if (inotify_fd_ >= 0)
+    if (inotify_fd_ >= 0 || config_fd_ >= 0)
       ShutDown();
     DCHECK(inotify_fd_ < 0);
+    DCHECK(config_fd_ < 0);
   }
 
   bool Init(const scoped_refptr<base::SingleThreadTaskRunner>& glib_task_runner,
@@ -944,9 +953,17 @@ class SettingGetterImplKDE : public Prox
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
     if (!base::SetNonBlocking(inotify_fd_)) {
@@ -970,22 +987,40 @@ class SettingGetterImplKDE : public Prox
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
     DCHECK(inotify_fd_ >= 0);
+    DCHECK(config_fd_ >= 0);
     DCHECK(file_task_runner_->BelongsToCurrentThread());
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
                           IN_MODIFY | IN_MOVED_TO) < 0) {
       return false;
     }
+#endif
     notify_delegate_ = delegate;
     if (!base::MessageLoopForIO::current()->WatchFileDescriptor(
             inotify_fd_, true, base::MessageLoopForIO::WATCH_READ,
@@ -1006,7 +1041,19 @@ class SettingGetterImplKDE : public Prox
   void OnFileCanReadWithoutBlocking(int fd) override {
     DCHECK_EQ(fd, inotify_fd_);
     DCHECK(file_task_runner_->BelongsToCurrentThread());
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
   void OnFileCanWriteWithoutBlocking(int fd) override { NOTREACHED(); }
 
@@ -1279,8 +1326,11 @@ class SettingGetterImplKDE : public Prox
   void OnChangeNotification() {
     DCHECK_GE(inotify_fd_,  0);
     DCHECK(file_task_runner_->BelongsToCurrentThread());
-    char event_buf[(sizeof(inotify_event) + NAME_MAX + 1) * 4];
     bool kioslaverc_touched = false;
+#if defined(OS_FREEBSD)
+    kioslaverc_touched = true;
+#else
+    char event_buf[(sizeof(inotify_event) + NAME_MAX + 1) * 4];
     ssize_t r;
     while ((r = read(inotify_fd_, event_buf, sizeof(event_buf))) > 0) {
       // inotify returns variable-length structures, which is why we have
@@ -1317,6 +1367,7 @@ class SettingGetterImplKDE : public Prox
         inotify_fd_ = -1;
       }
     }
+#endif
     if (kioslaverc_touched) {
       // We don't use Reset() because the timer may not yet be running.
       // (In that case Stop() is a no-op.)
@@ -1332,6 +1383,7 @@ class SettingGetterImplKDE : public Prox
                    std::vector<std::string> > strings_map_type;
 
   int inotify_fd_;
+  int config_fd_;
   base::MessagePumpLibevent::FileDescriptorWatcher inotify_watcher_;
   ProxyConfigServiceLinux::Delegate* notify_delegate_;
   scoped_ptr<base::OneShotTimer> debounce_timer_;
