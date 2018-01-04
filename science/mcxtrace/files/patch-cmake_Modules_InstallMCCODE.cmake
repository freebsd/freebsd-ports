--- cmake/Modules/InstallMCCODE.cmake.orig	2015-07-01 22:44:39 UTC
+++ cmake/Modules/InstallMCCODE.cmake
@@ -291,15 +291,14 @@ macro(installMCCODE)
     # Man pages
     install (
       FILES "${WORK}/doc/man/${FLAVOR}.1"
-      DESTINATION ${FLAVOR}/${MCCODE_VERSION}/doc/man/man1
-      RENAME "${FLAVOR}${PROGRAM_SUFFIX}.1"
+      DESTINATION "man/man1"
+      RENAME "${FLAVOR}.1"
       )
     install (
       FILES "${WORK}/doc/man/${FLAVOR_FMT}.1"
-      DESTINATION "${FLAVOR}/${MCCODE_VERSION}/doc/man/man1"
-      RENAME "${FLAVOR_FMT}${PROGRAM_SUFFIX}.1"
+      DESTINATION "man/man1"
+      RENAME "${FLAVOR_FMT}.1"
       )
-
     # Binaries
     install (
       PROGRAMS "${PROJECT_BINARY_DIR}/${FLAVOR}${DOT_EXE_SUFFIX}"
