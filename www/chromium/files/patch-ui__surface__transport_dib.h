--- ui/surface/transport_dib.h.orig	2011-11-01 10:43:23.000000000 +0200
+++ ui/surface/transport_dib.h	2011-11-21 22:35:21.000000000 +0200
@@ -9,7 +9,7 @@
 #include "base/basictypes.h"
 #include "ui/gfx/surface/surface_export.h"
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_ANDROID)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
 #include "base/shared_memory.h"
 #endif
 
@@ -79,7 +79,7 @@
     static int fake_handle = 10;
     return reinterpret_cast<Handle>(fake_handle++);
   }
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
   typedef base::SharedMemoryHandle Handle;
   // On Mac, the inode number of the backing file is used as an id.
   typedef base::SharedMemoryId Id;
@@ -94,7 +94,7 @@
     static int fake_handle = 10;
     return Handle(fake_handle++, false);
   }
-#elif defined(USE_X11)
+#elif defined(OS_LINUX)
   typedef int Handle;  // These two ints are SysV IPC shared memory keys
   struct Id {
     // Ensure that default initialized Ids are invalid.
@@ -199,11 +199,12 @@
 
  private:
   TransportDIB();
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_ANDROID)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
   explicit TransportDIB(base::SharedMemoryHandle dib);
   base::SharedMemory shared_memory_;
   uint32 sequence_num_;
-#elif defined(USE_X11)
+#endif
+#if defined(USE_X11)
   Id key_;  // SysV shared memory id
   void* address_;  // mapped address
   XSharedMemoryId x_shm_;  // X id for the shared segment
