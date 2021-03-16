pthread_setname_np() and pthread_getname_np() are only implemented on FreeBSD
12.x >=  1201518 and 13.x >= 1300098. Port to pthread_set_name_np() and
pthread_get_name_np(), respectively, for older versions.

--- lib/FXThread.cpp.orig	2020-12-24 17:03:54 UTC
+++ lib/FXThread.cpp
@@ -911,7 +911,10 @@ FXbool FXThread::description(const FXString& desc){
     return 0<=fxSetThreadDescription((HANDLE)tid,udesc);
 #elif defined(__APPLE__)
     return pthread_setname_np(desc.text())==0;
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) && !defined(HAVE_PTHREAD_SETNAME_NP)
+    pthread_set_name_np((pthread_t)tid,desc.text());
+    return true;
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
     pthread_setname_np((pthread_t)tid,desc.text());
     return true;
 #elif defined(HAVE_PTHREAD_SETNAME_NP)
@@ -938,7 +941,13 @@ FXString FXThread::description() const {
     if(pthread_getname_np(*((pthread_t*)&tid),desc,ARRAYNUMBER(desc))==0){
       return desc;
       }
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) && !defined(HAVE_PTHREAD_GETNAME_NP)
+    FXchar desc[256];
+    pthread_get_name_np((pthread_t)tid,desc,ARRAYNUMBER(desc));
+    if(desc[0]!='\0'){
+      return desc;
+      }
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
     FXchar desc[256];
     if(pthread_getname_np((pthread_t)tid,desc,ARRAYNUMBER(desc))==0){
       return desc;
