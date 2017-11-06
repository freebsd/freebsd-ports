--- ui/gfx/ipc/gfx_param_traits_macros.h.orig	2017-08-02 17:11:09.924017000 +0200
+++ ui/gfx/ipc/gfx_param_traits_macros.h	2017-08-02 17:11:50.017756000 +0200
@@ -15,7 +15,7 @@
 #include "ui/gfx/selection_bound.h"
 #include "ui/gfx/swap_result.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #endif
 
@@ -39,7 +39,7 @@
   IPC_STRUCT_TRAITS_MEMBER(handle)
   IPC_STRUCT_TRAITS_MEMBER(offset)
   IPC_STRUCT_TRAITS_MEMBER(stride)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(native_pixmap_handle)
 #elif defined(OS_MACOSX)
   IPC_STRUCT_TRAITS_MEMBER(mach_port)
@@ -50,7 +50,7 @@
   IPC_STRUCT_TRAITS_MEMBER(id)
 IPC_STRUCT_TRAITS_END()
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 IPC_STRUCT_TRAITS_BEGIN(gfx::NativePixmapPlane)
   IPC_STRUCT_TRAITS_MEMBER(stride)
   IPC_STRUCT_TRAITS_MEMBER(offset)
