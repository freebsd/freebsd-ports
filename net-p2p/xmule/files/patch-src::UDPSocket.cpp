--- src/UDPSocket.cpp.orig	Sun Mar 23 00:20:02 2003
+++ src/UDPSocket.cpp	Sun Mar 23 00:22:39 2003
@@ -25,7 +25,7 @@
 static pthread_attr_t attr;//=PTHREAD_CREATE_DETACHED;
 
 #ifdef __FreeBSD__
-static pthread_mutex_t gethostby_mutex = PTHREAD_MUTEX_INITIALIZER;
+static wxMutex *s_mutexProtectingGetHostByName;
 
 static int
 convert (struct hostent *host, struct hostent *result,
@@ -131,7 +131,7 @@
 {
   struct hostent *host;
 
-  pthread_mutex_lock (&gethostby_mutex);
+  s_mutexProtectingGetHostByName->Lock();
 
   host = gethostbyname (name);
   if (!host ||
@@ -140,7 +140,7 @@
     result = NULL;
   }
 
-  pthread_mutex_unlock (&gethostby_mutex);
+  s_mutexProtectingGetHostByName->Unlock();
   return result;
 }
 
