--- ./app/surface/transport_dib.h.orig	2010-12-16 02:11:21.000000000 +0100
+++ ./app/surface/transport_dib.h	2010-12-20 20:15:07.000000000 +0100
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
   typedef int Id;
 
@@ -171,11 +171,12 @@
 
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
   int key_;  // SysV shared memory id
   void* address_;  // mapped address
   XSharedMemoryId x_shm_;  // X id for the shared segment
