--- libobs/util/platform-nix.c.orig	2020-03-19 16:51:06 UTC
+++ libobs/util/platform-nix.c
@@ -40,6 +40,7 @@
 #include <sys/socket.h>
 #include <sys/sysctl.h>
 #include <sys/user.h>
+#include <sys/sysctl.h>
 #include <unistd.h>
 #include <libprocstat.h>
 #else
@@ -275,7 +276,11 @@ char *os_get_program_data_path_ptr(const char *name)
 char *os_get_executable_path_ptr(const char *name)
 {
 	char exe[PATH_MAX];
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+	ssize_t count = readlink("/proc/curproc/file", exe, PATH_MAX);
+#else
 	ssize_t count = readlink("/proc/self/exe", exe, PATH_MAX);
+#endif
 	const char *path_out = NULL;
 	struct dstr path;
 
