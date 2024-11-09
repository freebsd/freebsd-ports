Fix build with LLVM 19

/wrkdirs/usr/ports/science/py-hoomd-blue/work/hoomd-blue-4.9.0/hoomd/GPUFlags.h:160:27:
error: reference to non-static member function must be called
  160 |     this->resetFlags(from.readFlags);
      |                      ~~~~~^~~~~~~~~

--- hoomd/GPUFlags.h.orig	2024-10-31 16:09:15 UTC
+++ hoomd/GPUFlags.h
@@ -157,7 +157,7 @@ GPUFlags<T>::GPUFlags(const GPUFlags& from)
     memclear();
 
     // copy over the data to the new GPUFlags
-    this->resetFlags(from.readFlags);
+    this->resetFlags(from.readFlags());
     }
 
 template<class T> GPUFlags<T>& GPUFlags<T>::operator=(const GPUFlags& rhs)
