--- src/utils/util.cc.orig	2024-05-27 16:02:34 UTC
+++ src/utils/util.cc
@@ -83,14 +83,7 @@ bool get_file_size(const std::string& path, size_t& si
 }
 
 #if defined(NOCOREFILE)
-void SetNoCores()
-{
-    struct rlimit rlim;
-
-    getrlimit(RLIMIT_CORE, &rlim);
-    rlim.rlim_max = 0;
-    setrlimit(RLIMIT_CORE, &rlim);
-}
+void SetNoCores();
 #endif
 
 namespace snort
