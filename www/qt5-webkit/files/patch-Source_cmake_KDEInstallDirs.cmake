--- Source/cmake/KDEInstallDirs.cmake.orig	2017-06-15 23:36:48 UTC
+++ Source/cmake/KDEInstallDirs.cmake
@@ -420,7 +420,7 @@ endif()
 if(NOT KDE_INSTALL_DIRS_NO_DEPRECATED)
     set(KF5_LIBEXEC_INSTALL_DIR "${CMAKE_INSTALL_LIBEXECDIR_KF5}")
 endif()
-_define_relative(CMAKEPACKAGEDIR LIBDIR "cmake"
+_define_relative(CMAKEPACKAGEDIR "" "lib/cmake"
     "CMake packages, including config files"
     CMAKECONFIG_INSTALL_PREFIX)
 
@@ -442,8 +442,8 @@ if(KDE_INSTALL_USE_QT_SYS_PATHS)
     file(RELATIVE_PATH LIB_INSTALL_DIR ${qt_install_prefix} ${qt_lib_dir})
     set(KDE_INSTALL_LIBDIR ${LIB_INSTALL_DIR})
 
-    set(CMAKECONFIG_INSTALL_PREFIX "${LIB_INSTALL_DIR}/cmake")
-    set(KDE_INSTALL_CMAKEPACKAGEDIR "${LIB_INSTALL_DIR}/cmake")
+    set(CMAKECONFIG_INSTALL_PREFIX "${qt_install_prefix}/lib/cmake")
+    set(KDE_INSTALL_CMAKEPACKAGEDIR "${qt_install_prefix}/lib/cmake")
 
     query_qmake(qt_include_dir QT_INSTALL_HEADERS)
     file(RELATIVE_PATH INCLUDE_INSTALL_DIR ${qt_install_prefix} ${qt_include_dir})
