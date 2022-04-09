--- src/common/fs_sys_helpers.h.orig	2022-03-13 12:54:56 UTC
+++ src/common/fs_sys_helpers.h
@@ -26,6 +26,7 @@ void determine_path_to_current_executable(std::string 
 std::filesystem::path get_current_exe_path(std::string const &argv0);
 std::filesystem::path get_application_data_folder();
 std::filesystem::path get_installation_path();
+std::filesystem::path find_exe_in_path(std::filesystem::path const &exe);
 uint64_t get_memory_usage();
 
 bool is_installed();
