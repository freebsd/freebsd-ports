--- m4/flags.m4.orig	2020-01-24 09:42:54 UTC
+++ m4/flags.m4
@@ -122,7 +122,7 @@ AC_DEFUN([SING_CHECK_SET_ARGS], [
  ## for clang: -Wunneeded-internal-declaration
 
  if test "x${ENABLE_OPTIMIZATION}" != xno; then
-  OPTFLAGS="-g0 -O3 -Wno-unused-function -Wno-trigraphs -Wno-unused-parameter -Wunknown-pragmas -Wno-unused-variable -fomit-frame-pointer -fwrapv -fvisibility=default -finline-functions -fno-exceptions -fno-threadsafe-statics -fno-enforce-eh-specs -fconserve-space -funroll-loops -fno-delete-null-pointer-checks"
+  OPTFLAGS="-Wno-unused-function -Wno-trigraphs -Wno-unused-parameter -Wunknown-pragmas -Wno-unused-variable -fomit-frame-pointer -fwrapv -fvisibility=default -finline-functions -fno-exceptions -fno-threadsafe-statics -fno-enforce-eh-specs -fconserve-space -funroll-loops -fno-delete-null-pointer-checks"
   #  -O3 - crashes gcc???!!!
   # -fpermissive
   AC_LANG_PUSH([C])
