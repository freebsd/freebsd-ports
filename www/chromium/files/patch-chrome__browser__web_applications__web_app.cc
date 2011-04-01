--- ./chrome/browser/web_applications/web_app.cc.orig	2010-12-16 02:11:54.000000000 +0100
+++ ./chrome/browser/web_applications/web_app.cc	2010-12-20 20:15:08.000000000 +0100
@@ -34,9 +34,9 @@
 #include "chrome/common/url_constants.h"
 #include "chrome/common/web_apps.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "base/environment.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(OS_WIN)
 #include "base/win_util.h"
@@ -261,7 +261,7 @@
 bool CreateShortcutTask::CreateShortcut() {
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::FILE));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   scoped_ptr<base::Environment> env(base::Environment::Create());
 
   std::string shortcut_template;
