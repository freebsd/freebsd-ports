--- ui/gfx/ipc/gfx_param_traits_macros.h.orig	2019-07-24 18:59:22 UTC
+++ ui/gfx/ipc/gfx_param_traits_macros.h
@@ -18,7 +18,7 @@
 #include "ui/gfx/selection_bound.h"
 #include "ui/gfx/swap_result.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #endif
 
@@ -51,7 +51,7 @@ IPC_STRUCT_TRAITS_BEGIN(gfx::GpuMemoryBufferHandle)
   IPC_STRUCT_TRAITS_MEMBER(region)
   IPC_STRUCT_TRAITS_MEMBER(offset)
   IPC_STRUCT_TRAITS_MEMBER(stride)
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(native_pixmap_handle)
 #elif defined(OS_MACOSX)
   IPC_STRUCT_TRAITS_MEMBER(mach_port)
@@ -66,12 +66,12 @@ IPC_STRUCT_TRAITS_BEGIN(gfx::GpuMemoryBufferId)
   IPC_STRUCT_TRAITS_MEMBER(id)
 IPC_STRUCT_TRAITS_END()
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 IPC_STRUCT_TRAITS_BEGIN(gfx::NativePixmapPlane)
   IPC_STRUCT_TRAITS_MEMBER(stride)
   IPC_STRUCT_TRAITS_MEMBER(offset)
   IPC_STRUCT_TRAITS_MEMBER(size)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(fd)
 #elif defined(OS_FUCHSIA)
   IPC_STRUCT_TRAITS_MEMBER(vmo)
