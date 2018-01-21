# Work around FreeBSD bug #189353 when /tmp is using tmpfs(5)

--- threading.c.orig	2017-11-28 16:54:05 UTC
+++ threading.c
@@ -33,6 +33,10 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
 #include <errno.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#endif
+
 #include "threading.h"
 
 
@@ -88,6 +92,11 @@ int semaphore_init(
   *semaphore = CreateSemaphore(NULL, value, 65535, NULL);
   if (*semaphore == NULL)
     return GetLastError();
+  #elif defined(__FreeBSD__)
+  *semaphore = malloc(sizeof(sem_t));
+  if (*semaphore == NULL)
+    return errno;
+  return sem_init(*semaphore, 0, value);
   #else
   // Mac OS X doesn't support unnamed semaphores via sem_init, that's why
   // we use sem_open instead sem_init and immediately unlink the semaphore
@@ -112,6 +121,9 @@ void semaphore_destroy(
 {
   #if defined(_WIN32) || defined(__CYGWIN__)
   CloseHandle(*semaphore);
+  #elif defined(__FreeBSD__)
+  sem_close(*semaphore);
+  free(*semaphore);
   #else
   sem_close(*semaphore);
   #endif
