--- net/proxy/proxy_config_service_linux.cc.orig	2011-07-01 00:30:51.106692749 +0300
+++ net/proxy/proxy_config_service_linux.cc	2011-07-01 01:15:28.391693775 +0300
@@ -18,7 +18,13 @@
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
@@ -861,9 +867,10 @@
                              public base::MessagePumpLibevent::Watcher {
  public:
   explicit SettingGetterImplKDE(base::Environment* env_var_getter)
-      : inotify_fd_(-1), notify_delegate_(NULL), indirect_manual_(false),
-        auto_no_pac_(false), reversed_bypass_list_(false),
-        env_var_getter_(env_var_getter), file_loop_(NULL) {
+      : config_fd_(-1), inotify_fd_(-1), notify_delegate_(NULL),
+        indirect_manual_(false), auto_no_pac_(false),
+        reversed_bypass_list_(false), env_var_getter_(env_var_getter),
+        file_loop_(NULL) {
     // This has to be called on the UI thread (http://crbug.com/69057).
     base::ThreadRestrictions::ScopedAllowIO allow_io;
 
@@ -926,9 +933,14 @@
     // task is left pending on the file loop after the loop was quit,
     // and pending tasks may then be deleted without being run.
     // Here in the KDE version, we can safely close the file descriptor
-    // anyway. (Not that it really matters; the process is exiting.)
+    // anyway. (Not that it really matters; the process is exiting.)  
+    if(config_fd_ >= 0) {
+      close(config_fd_);
+      config_fd_ = -1;
+    }  
     if (inotify_fd_ >= 0)
       ShutDown();
+    DCHECK(config_fd_ < 0);
     DCHECK(inotify_fd_ < 0);
   }
 
@@ -937,18 +949,25 @@
     // This has to be called on the UI thread (http://crbug.com/69057).
     base::ThreadRestrictions::ScopedAllowIO allow_io;
     DCHECK(inotify_fd_ < 0);
+#if defined(OS_FREEBSD)
+    inotify_fd_ = kqueue();
+#else
     inotify_fd_ = inotify_init();
+#endif
     if (inotify_fd_ < 0) {
       PLOG(ERROR) << "inotify_init failed";
       return false;
     }
+#if !defined(OS_FREEBSD)
     int flags = fcntl(inotify_fd_, F_GETFL);
+    // This call returns ENOTTY on FreeBSD.
     if (fcntl(inotify_fd_, F_SETFL, flags | O_NONBLOCK) < 0) {
       PLOG(ERROR) << "fcntl failed";
       close(inotify_fd_);
       inotify_fd_ = -1;
       return false;
     }
+#endif
     file_loop_ = file_loop;
     // The initial read is done on the current thread, not |file_loop_|,
     // since we will need to have it for SetUpAndFetchInitialConfig().
@@ -968,6 +987,18 @@
   bool SetUpNotifications(ProxyConfigServiceLinux::Delegate* delegate) {
     DCHECK(inotify_fd_ >= 0);
     DCHECK(MessageLoop::current() == file_loop_);
+#if defined(OS_FREEBSD)
+    config_fd_ = open(kde_config_dir_.value().c_str(), O_RDONLY);
+
+    if (config_fd_ == -1)
+      return false;
+
+    struct kevent ev;
+    EV_SET(&ev, config_fd_, EVFILT_VNODE,
+           (EV_ADD | EV_CLEAR), NOTE_WRITE, 0, NULL);
+    if (kevent(inotify_fd_, &ev, 1, NULL, 0, NULL) == -1)
+      return false;
+#else
     // We can't just watch the kioslaverc file directly, since KDE will write
     // a new copy of it and then rename it whenever settings are changed and
     // inotify watches inodes (so we'll be watching the old deleted file after
@@ -976,6 +1007,7 @@
     if (inotify_add_watch(inotify_fd_, kde_config_dir_.value().c_str(),
                           IN_MODIFY | IN_MOVED_TO) < 0)
       return false;
+#endif
     notify_delegate_ = delegate;
     if (!file_loop_->WatchFileDescriptor(inotify_fd_, true,
             MessageLoopForIO::WATCH_READ, &inotify_watcher_, this))
@@ -993,7 +1025,23 @@
   void OnFileCanReadWithoutBlocking(int fd) {
     DCHECK(fd == inotify_fd_);
     DCHECK(MessageLoop::current() == file_loop_);
+#if defined(OS_FREEBSD)
+    struct kevent ev;
+    int rv = kevent(inotify_fd_, NULL, 0, &ev, 1, NULL);
+
+    if (rv != -1 && (ev.flags & EV_ERROR) == 0) {
+      OnChangeNotification();
+    } else {
+      LOG(ERROR) << "kevent() failure; no longer watching kioslaverc!";
+      inotify_watcher_.StopWatchingFileDescriptor();      
+      close(config_fd_);
+      config_fd_ = -1;
+      close(inotify_fd_);
+      inotify_fd_ = -1;
+    }
+#else
     OnChangeNotification();
+#endif
   }
   void OnFileCanWriteWithoutBlocking(int fd) {
     NOTREACHED();
@@ -1262,10 +1310,14 @@
   // from the inotify file descriptor and starts up a debounce timer if
   // an event for kioslaverc is seen.
   void OnChangeNotification() {
+    DCHECK(config_fd_ >= 0);
     DCHECK(inotify_fd_ >= 0);
     DCHECK(MessageLoop::current() == file_loop_);
-    char event_buf[(sizeof(inotify_event) + NAME_MAX + 1) * 4];
     bool kioslaverc_touched = false;
+#if defined(OS_FREEBSD)
+    kioslaverc_touched = true;
+#else
+    char event_buf[(sizeof(inotify_event) + NAME_MAX + 1) * 4];
     ssize_t r;
     while ((r = read(inotify_fd_, event_buf, sizeof(event_buf))) > 0) {
       // inotify returns variable-length structures, which is why we have
@@ -1302,6 +1354,7 @@
         inotify_fd_ = -1;
       }
     }
+#endif
     if (kioslaverc_touched) {
       // We don't use Reset() because the timer may not yet be running.
       // (In that case Stop() is a no-op.)
@@ -1316,6 +1369,7 @@
   typedef std::map<StringListSetting,
                    std::vector<std::string> > strings_map_type;
 
+  int config_fd_;  
   int inotify_fd_;
   base::MessagePumpLibevent::FileDescriptorWatcher inotify_watcher_;
   ProxyConfigServiceLinux::Delegate* notify_delegate_;
