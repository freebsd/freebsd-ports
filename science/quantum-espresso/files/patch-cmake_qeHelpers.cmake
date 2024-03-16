- workaround for https://gitlab.com/QEF/q-e/-/issues/668

--- cmake/qeHelpers.cmake.orig	2024-03-16 03:55:17 UTC
+++ cmake/qeHelpers.cmake
@@ -96,6 +96,7 @@ function(qe_git_submodule_update PATH)
 endfunction(_qe_add_cuda_link_flags)
 
 function(qe_git_submodule_update PATH)
+    return()
     # validate submodule_commit_hash_records against git database
     get_filename_component(SUBMODULE_NAME ${PATH} NAME)
     get_filename_component(SUBMODULE_UPPER_DIR ${PATH} DIRECTORY)
