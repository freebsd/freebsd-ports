--- source/global/management/include/tls.hh.orig	2022-09-16 07:46:17 UTC
+++ source/global/management/include/tls.hh
@@ -39,7 +39,8 @@
 
 #  if defined(G4MULTITHREADED)
 #    if(defined(__MACH__) && defined(__clang__)) ||                            \
-      (defined(__linux__) && defined(__clang__))
+      (defined(__linux__) && defined(__clang__)) ||                            \
+      (defined(__FreeBSD__) && defined(__clang__))
 #      define G4ThreadLocalStatic static thread_local
 #      define G4ThreadLocal thread_local
 #    elif((defined(__linux__) || defined(__MACH__)) &&                         \
