FXThread.cpp:929:5: error: no matching function for call to 'pthread_set_name_np'
    pthread_set_name_np(tid,desc.text());
    ^~~~~~~~~~~~~~~~~~~
/usr/include/pthread_np.h:67:6: note: candidate function not viable: no known
conversionfrom 'volatile FX::FXThreadID' (aka 'volatile unsigned long')
to 'pthread_t' (aka 'pthread *') for 1st argument
void pthread_set_name_np(pthread_t, const char *);
     ^
FXThread.cpp:962:8: error: no matching function for call to 'pthread_getname_np'
    if(pthread_getname_np(tid,desc,ARRAYNUMBER(desc))==0){
       ^~~~~~~~~~~~~~~~~~
/usr/include/pthread.h:305:6: note: candidate function not viable: no known
conversion from 'const volatile FX::FXThreadID' (aka 'const volatile unsigned long')
to 'pthread_t' (aka 'pthread *') for 1st argument
int             pthread_getname_np(pthread_t, char *, size_t);
                ^

--- lib/FXThread.cpp.orig	2020-11-30 16:10:17 UTC
+++ lib/FXThread.cpp
@@ -925,7 +925,10 @@ FXbool FXThread::description(const FXString& desc){
     return pthread_setname_np(desc.text())==0;
 #elif defined(__NetBSD__)
     return pthread_setname_np(tid,"%s",desc.text())==0;
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__)
+    pthread_set_name_np((pthread_t)tid,desc.text());
+    return true;
+#elif defined(__OpenBSD__)
     pthread_set_name_np(tid,desc.text());
     return true;
 #elif defined(HAVE_PTHREAD_SETNAME_NP)
@@ -955,6 +958,11 @@ FXString FXThread::description() const {
 #elif defined(__NetBSD__)
     FXchar desc[256];
     if(pthread_getname_np(tid,desc,ARRAYNUMBER(desc))==0){
+      return desc;
+      }
+#elif defined(__FreeBSD__) && (__FreeBSD_version >= 1300098)
+    FXchar desc[256];
+    if(pthread_getname_np((pthread_t)tid,desc,ARRAYNUMBER(desc))==0){
       return desc;
       }
 #elif defined(HAVE_PTHREAD_GETNAME_NP)
