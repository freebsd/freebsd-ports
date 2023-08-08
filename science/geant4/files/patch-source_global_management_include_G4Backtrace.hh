--- source/global/management/include/G4Backtrace.hh.orig	2022-09-16 07:46:17 UTC
+++ source/global/management/include/G4Backtrace.hh
@@ -114,7 +114,7 @@ using G4ResultOf_t = std::invoke_result_t<FuncT, ArgTy
 #endif
 
 #if !defined(G4PSIGINFO_AVAILABLE)
-#  if _XOPEN_SOURCE >= 700 || _POSIX_C_SOURCE >= 200809L
+#  if (_XOPEN_SOURCE >= 700 || _POSIX_C_SOURCE >= 200809L) && !defined(__FreeBSD__)
 #    define G4PSIGINFO_AVAILABLE 1
 #  else
 #    define G4PSIGINFO_AVAILABLE 0
