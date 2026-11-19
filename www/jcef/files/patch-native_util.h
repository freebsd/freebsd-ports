--- native/util.h.orig	2026-09-08 14:07:06 UTC
+++ native/util.h
@@ -16,7 +16,7 @@
 #include "include/cef_browser.h"
 #include "include/cef_task.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "critical_wait.h"
 #endif
 
@@ -112,7 +112,7 @@ void SetParent(CefWindowHandle browserHandle,
                CefWindowHandle parentHandle,
                base::OnceClosure callback);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 void SetParentSync(CefWindowHandle browserHandle,
                    CefWindowHandle parentHandle,
                    CriticalWait* waitCond,
