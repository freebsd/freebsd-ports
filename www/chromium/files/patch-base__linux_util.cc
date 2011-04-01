--- base/linux_util.cc.orig	2011-03-21 20:43:02.797111222 +0200
+++ base/linux_util.cc	2011-03-21 20:44:28.268111587 +0200
@@ -133,12 +133,14 @@
 char g_linux_distro[kDistroSize] =
 #if defined(OS_CHROMEOS)
     "CrOS";
+#elif defined(OS_FREEBSD)
+    "FreeBSD";
 #else  // if defined(OS_LINUX)
     "Unknown";
 #endif
 
 std::string GetLinuxDistro() {
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) || defined(OS_FREEBSD)
   return g_linux_distro;
 #elif defined(OS_LINUX)
   LinuxDistroHelper* distro_state_singleton = LinuxDistroHelper::GetInstance();
@@ -194,6 +196,7 @@
   return true;
 }
 
+#if defined(OS_LINUX)
 bool FindProcessHoldingSocket(pid_t* pid_out, ino_t socket_inode) {
   DCHECK(pid_out);
   bool already_found = false;
@@ -293,5 +296,5 @@
   }
   return -1;
 }
-
+#endif // if defined(OS_LINUX)
 }  // namespace base
