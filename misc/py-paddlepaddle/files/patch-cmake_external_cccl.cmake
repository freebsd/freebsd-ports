-- Replace git commands with patch command because the cccl source
-- is fetched as a tarball (via GH_TUPLE) and is not a git repository.
-- The source is already at the correct commit, so only patches need to be applied.
--- cmake/external/cccl.cmake.orig	2026-06-19 08:41:53 UTC
+++ cmake/external/cccl.cmake
@@ -7,9 +7,8 @@ set(CCCL_SOURCE_DIR ${PADDLE_SOURCE_DIR}/third_party/c
 set(CCCL_SOURCE_DIR ${PADDLE_SOURCE_DIR}/third_party/cccl)
 
 # The latest commit has bugs in windows, so we set a fix commit.
+# NOTE: git checkout removed for FreeBSD ports (source is tarball, not git repo)
 set(CCCL_TAG 1f6e4bcae0fbf1bbed87f88544d8d2161c490fc1)
-execute_process(COMMAND git --git-dir=${CCCL_SOURCE_DIR}/.git
-                        --work-tree=${CCCL_SOURCE_DIR} checkout ${CCCL_TAG})
 
 set(CCCL_INCLUDE_DIR ${CCCL_SOURCE_DIR})
 message("CCCL_INCLUDE_DIR is ${CCCL_INCLUDE_DIR}")
@@ -17,8 +16,8 @@ file(TO_NATIVE_PATH ${PADDLE_SOURCE_DIR}/patches/cccl/
 
 file(TO_NATIVE_PATH ${PADDLE_SOURCE_DIR}/patches/cccl/util_device.cuh.patch
      native_src)
-set(CCCL_PATCH_COMMAND git checkout -- . && git checkout ${CCCL_TAG} && git
-                       apply ${native_src})
+# NOTE: git commands replaced with patch for FreeBSD ports (source is tarball, not git repo)
+set(CCCL_PATCH_COMMAND patch -p1 -i ${native_src})
 
 ExternalProject_Add(
   extern_cccl
