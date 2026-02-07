--- src/Launcher/SALOME_ExternalServerLauncher.cxx.orig	2023-07-03 21:31:03 UTC
+++ src/Launcher/SALOME_ExternalServerLauncher.cxx
@@ -40,6 +40,8 @@
 #include <memory>
 #include <functional>
 
+#include <sys/param.h>
+
 const char SALOME_ExternalServerLauncher::NAME_IN_NS[]="/ExternalServers";
 
 unsigned SALOME_ExternalServerLauncher::CNT = 0;
@@ -62,7 +64,7 @@ class ChdirRAII
 {
 public:
 #ifndef WIN32
-  ChdirRAII(const std::string& wd):_wd(wd) { if(_wd.empty()) return ; char *pwd(get_current_dir_name()); _od = pwd; free(pwd); chdir(_wd.c_str()); }
+  ChdirRAII(const std::string& wd):_wd(wd) { if(_wd.empty()) return ; char wd_[MAXPATHLEN]; getcwd(wd_, MAXPATHLEN); _od = wd_; chdir(_wd.c_str()); }
   ~ChdirRAII() { if(_od.empty()) return ; chdir(_od.c_str()); }
 #else
 	ChdirRAII(const std::string& wd) : _wd(wd) { 
