--- vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/linux/invoke.go.orig	2026-09-29 13:43:24 UTC
+++ vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/linux/invoke.go
@@ -1,16 +1,25 @@
-//go:build linux
-// +build linux
+//go:build linux || freebsd
+// +build linux freebsd
 
 package linux
 
 /*
-#cgo linux pkg-config: gtk+-3.0
+#cgo linux freebsd pkg-config: gtk+-3.0
 
 #include <stdio.h>
 #include "gtk/gtk.h"
 
 extern gboolean invokeCallbacks(void *);
 
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+static inline int wailsGettid(void) { return pthread_getthreadid_np(); }
+#else
+#include <unistd.h>
+#include <sys/syscall.h>
+static inline int wailsGettid(void) { return (int)syscall(SYS_gettid); }
+#endif
+
 static inline void triggerInvokesOnMainThread() {
     g_idle_add((GSourceFunc)invokeCallbacks, NULL);
 }
@@ -20,8 +29,6 @@ import (
 	"runtime"
 	"sync"
 	"unsafe"
-
-	"golang.org/x/sys/unix"
 )
 
 var (
@@ -50,7 +57,7 @@ func tryInvokeOnCurrentGoRoutine(f func()) bool {
 	runtime.LockOSThread()
 	defer runtime.UnlockOSThread()
 
-	if mainThreadID != unix.Gettid() {
+	if mainThreadID != int(C.wailsGettid()) {
 		return false
 	}
 	f()
@@ -64,7 +71,7 @@ func invokeCallbacks(_ unsafe.Pointer) C.gboolean {
 
 	m.Lock()
 	if mainTid == 0 {
-		mainTid = unix.Gettid()
+		mainTid = int(C.wailsGettid())
 	}
 
 	q := append([]func(){}, dispatchq...)
