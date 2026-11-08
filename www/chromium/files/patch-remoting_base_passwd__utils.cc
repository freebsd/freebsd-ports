--- remoting/base/passwd_utils.cc.orig	2026-09-25 15:26:43 UTC
+++ remoting/base/passwd_utils.cc
@@ -49,7 +49,7 @@ base::expected<PasswdUserInfo, Loggable> GetPasswdUser
   user_info.gid = result->pw_gid;
   user_info.home_dir = base::FilePath(result->pw_dir);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   long max_groups = sysconf(_SC_NGROUPS_MAX);
   constexpr int kDefaultNgroups = 64;
   int ngroups =
