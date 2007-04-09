--- src/os/linux/OsBSemLinux.cpp.orig	Sat Apr  7 20:19:17 2007
+++ src/os/linux/OsBSemLinux.cpp	Sat Apr  7 20:19:47 2007
@@ -7,6 +7,7 @@
 
 // SYSTEM INCLUDES
 #include <assert.h>
+#include <stdint.h>
 
 // APPLICATION INCLUDES
 #include "os/OsDefs.h"
@@ -58,7 +59,7 @@
    {
       OsSysLog::add(FAC_KERNEL, PRI_ERR,
                     "OsBSemLinux::~OsBSemLinux pt_sem_destroy returned %d in task %u",
-                    res, (unsigned int)pthread_self()
+                    res, (unsigned int)((uintptr_t)pthread_self())
                     );
    }
 #  ifdef OS_SYNC_DEBUG
