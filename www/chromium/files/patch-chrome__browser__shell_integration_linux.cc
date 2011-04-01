--- ./chrome/browser/shell_integration_linux.cc.orig	2010-12-16 02:11:58.000000000 +0100
+++ ./chrome/browser/shell_integration_linux.cc	2010-12-20 20:15:08.000000000 +0100
@@ -118,6 +118,8 @@
   if (!PathService::Get(chrome::DIR_USER_DESKTOP, &desktop_path))
     return;
 
+#if !defined(OS_FREEBSD)
+// BSD: Linux-specific calls like openat are used so defined out for BSD.
   int desktop_fd = open(desktop_path.value().c_str(), O_RDONLY | O_DIRECTORY);
   if (desktop_fd < 0)
     return;
@@ -146,6 +148,7 @@
 
   if (HANDLE_EINTR(close(desktop_fd)) < 0)
     PLOG(ERROR) << "close";
+#endif  // !defined(OS_FREEBSD)
 }
 
 void CreateShortcutInApplicationsMenu(const FilePath& shortcut_filename,
