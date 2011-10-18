--- ui/gfx/surface/transport_dib.h.orig	2011-05-06 12:03:42.000000000 +0300
+++ ui/gfx/surface/transport_dib.h	2011-06-05 21:06:20.559165060 +0300
@@ -8,7 +8,7 @@
 
 #include "base/basictypes.h"
 
-#if defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_FREEBSD)
 #include "base/shared_memory.h"
 #endif
 
@@ -78,7 +78,7 @@
     static int fake_handle = 10;
     return reinterpret_cast<Handle>(fake_handle++);
   }
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
   typedef base::SharedMemoryHandle Handle;
   // On Mac, the inode number of the backing file is used as an id.
   typedef base::SharedMemoryId Id;
@@ -93,7 +93,7 @@
     static int fake_handle = 10;
     return Handle(fake_handle++, false);
   }
-#elif defined(USE_X11)
+#elif defined(OS_LINUX)
   typedef int Handle;  // These two ints are SysV IPC shared memory keys
   struct Id {
     // Ensure that default initialized Ids are invalid.
@@ -184,11 +184,12 @@
 
  private:
   TransportDIB();
-#if defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_FREEBSD)
   explicit TransportDIB(base::SharedMemoryHandle dib);
   base::SharedMemory shared_memory_;
   uint32 sequence_num_;
-#elif defined(USE_X11)
+#endif
+#if defined(USE_X11)
   Id key_;  // SysV shared memory id
   void* address_;  // mapped address
   XSharedMemoryId x_shm_;  // X id for the shared segment
