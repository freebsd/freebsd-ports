-- The sleef ExternalProject's PATCH_COMMAND runs "git checkout" to pin the
-- submodule to SLEEF_TAG, but FreeBSD's GH_TUPLE fetches third_party/sleef as
-- a plain tarball (no .git metadata) already at the exact SLEEF_TAG commit.
-- Make the PATCH_COMMAND a no-op to avoid "fatal: not a git repository".
--- cmake/external/sleef.cmake.orig	2026-09-25 23:46:24 UTC
+++ cmake/external/sleef.cmake
@@ -27,7 +27,9 @@ set(SLEEF_INSTALL_DIR ${THIRD_PARTY_PATH}/install/slee
 set(SLEEF_INSTALL_DIR ${THIRD_PARTY_PATH}/install/sleef)
 
 # Pin sleef to the required tag inside the third_party submodule before build.
-set(SLEEF_PATCH_COMMAND git checkout -- . && git checkout ${SLEEF_TAG})
+# NOTE: FreeBSD port already fetches the third_party/sleef source at the
+# SLEEF_TAG commit (no .git metadata present), so the git checkout is a no-op.
+set(SLEEF_PATCH_COMMAND ${CMAKE_COMMAND} -E true)
 
 set(SLEEF_INCLUDE_DIR
     "${SLEEF_INSTALL_DIR}/include"
