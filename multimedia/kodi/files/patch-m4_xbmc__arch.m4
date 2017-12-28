--- m4/xbmc_arch.m4.orig	2017-11-14 16:55:01 UTC
+++ m4/xbmc_arch.m4
@@ -14,6 +14,9 @@ case $build in
   amd64-*-freebsd*)
      AC_SUBST(NATIVE_ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_FREEBSD -D_LINUX")
      ;;
+  armv*-*-freebsd*)
+     AC_SUBST(NATIVE_ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_FREEBSD -D_LINUX")
+     ;;
   *86*-apple-darwin*)
      AC_SUBST(NATIVE_ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_DARWIN -DTARGET_DARWIN_OSX -D_LINUX")
      ;;
@@ -45,6 +48,9 @@ case $host in
   amd64-*-freebsd*)
      AC_SUBST(ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_FREEBSD -D_LINUX")
      ;;
+  armv*-*-freebsd*)
+     AC_SUBST(ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_FREEBSD -D_LINUX")
+     ;;
   arm-apple-darwin*)
      AC_SUBST(ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_DARWIN -DTARGET_DARWIN_IOS -D_LINUX")
      ;;
@@ -78,6 +84,6 @@ if test "$target_platform" = "target_android" ; then
 fi
 
 if test "$target_platform" = "target_raspberry_pi" ; then
-  AC_SUBST(ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_LINUX -D_LINUX -D_ARMEL -DTARGET_RASPBERRY_PI")
+  AC_SUBST(ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_FREEBSD -D_LINUX -D_ARMEL -DTARGET_RASPBERRY_PI")
 fi
 ])
