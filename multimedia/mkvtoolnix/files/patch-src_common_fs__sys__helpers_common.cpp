--- src/common/fs_sys_helpers/common.cpp.orig	2022-03-13 12:54:56 UTC
+++ src/common/fs_sys_helpers/common.cpp
@@ -14,12 +14,36 @@
 #include "common/common_pch.h"
 
 #include "common/fs_sys_helpers.h"
+#include "common/path.h"
+#include "common/strings/parsing.h"
 
 namespace mtx::sys {
 
-static std::filesystem::path s_current_executable_path;
+namespace {
 
+std::filesystem::path s_current_executable_path;
+std::unordered_map<std::string, std::filesystem::path> s_exes_in_path;
+
 std::filesystem::path
+find_exe_in_path_worker(std::filesystem::path const &exe) {
+  auto paths = mtx::string::split(get_environment_variable("PATH"), ":");
+
+  for (auto const &path : paths) {
+    auto potential_exe = mtx::fs::to_path(path) / exe;
+    if (std::filesystem::exists(potential_exe))
+      return potential_exe;
+
+    potential_exe += mtx::fs::to_path(".exe");
+    if (std::filesystem::exists(potential_exe))
+      return potential_exe;
+  }
+
+  return {};
+}
+
+} // anonymous
+
+std::filesystem::path
 get_installation_path() {
   return s_current_executable_path;
 }
@@ -27,6 +51,17 @@ get_installation_path() {
 void
 determine_path_to_current_executable(std::string const &argv0) {
   s_current_executable_path = get_current_exe_path(argv0);
+}
+
+std::filesystem::path
+find_exe_in_path(std::filesystem::path const &exe) {
+  auto const exe_str = exe.u8string();
+  auto const itr     = s_exes_in_path.find(exe_str);
+
+  if (itr == s_exes_in_path.end())
+    s_exes_in_path[exe_str] = find_exe_in_path_worker(exe);
+
+  return s_exes_in_path[exe_str];
 }
 
 }
