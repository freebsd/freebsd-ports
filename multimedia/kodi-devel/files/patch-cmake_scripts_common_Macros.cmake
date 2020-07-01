--- cmake/scripts/common/Macros.cmake.orig	2020-06-13 16:17:41 UTC
+++ cmake/scripts/common/Macros.cmake
@@ -571,7 +571,6 @@ function(core_find_git_rev stamp)
   # allow manual setting GIT_VERSION
   if(GIT_VERSION)
     set(${stamp} ${GIT_VERSION} PARENT_SCOPE)
-    string(TIMESTAMP APP_BUILD_DATE "%Y%m%d" UTC)
     set(APP_BUILD_DATE ${APP_BUILD_DATE} PARENT_SCOPE)
   else()
     find_package(Git)
