--- m4/flags.m4.orig	2022-01-12 15:46:27 UTC
+++ m4/flags.m4
@@ -122,7 +122,7 @@ AC_DEFUN([SING_CHECK_SET_ARGS], [
  ## for clang: -Wunneeded-internal-declaration
 
  if test "x${ENABLE_OPTIMIZATION}" != xno; then
-  OPTFLAGS="-g0 -O3 -Wno-unused-function -Wno-trigraphs -Wno-unused-parameter -Wunknown-pragmas -Wno-unused-variable -fomit-frame-pointer -fwrapv -fvisibility=default -finline-functions -fno-exceptions -fno-threadsafe-statics -fno-enforce-eh-specs -fconserve-space -funroll-loops"
+  OPTFLAGS="-Wno-unused-function -Wno-trigraphs -Wno-unused-parameter -Wunknown-pragmas -Wno-unused-variable -fomit-frame-pointer -fwrapv -fvisibility=default -finline-functions -fno-exceptions -fno-threadsafe-statics -fno-enforce-eh-specs -fconserve-space -funroll-loops"
   #  -O3 - crashes gcc???!!!
   # -fpermissive
   AC_LANG_PUSH([C])
