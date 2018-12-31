--- Telegram/ThirdParty/libtgvoip/threading.h.orig	2018-11-23 01:03:16 UTC
+++ Telegram/ThirdParty/libtgvoip/threading.h
@@ -18,6 +18,9 @@
 #ifdef __APPLE__
 #include "os/darwin/DarwinSpecific.h"
 #endif
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
 
 namespace tgvoip{
 	class Mutex{
@@ -92,7 +95,9 @@ namespace tgvoip{
 		static void* ActualEntryPoint(void* arg){
 			Thread* self=reinterpret_cast<Thread*>(arg);
 			if(self->name){
-#if !defined(__APPLE__) && !defined(__gnu_hurd__)
+#if defined(__FreeBSD__)
+				pthread_set_name_np(self->thread, self->name);
+#elif !defined(__APPLE__) && !defined(__gnu_hurd__)
 				pthread_setname_np(self->thread, self->name);
 #elif !defined(__gnu_hurd__)
 				pthread_setname_np(self->name);
