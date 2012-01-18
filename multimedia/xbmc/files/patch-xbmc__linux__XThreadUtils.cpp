--- ./xbmc/linux/XThreadUtils.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/linux/XThreadUtils.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -38,7 +38,11 @@
           LPTHREAD_START_ROUTINE lpStartAddress,
             LPVOID lpParameter,
         DWORD dwCreationFlags,
+#ifdef __FreeBSD__
+          LPLONG lpThreadId
+#else
           LPDWORD lpThreadId
+#endif
     ) {
 
   // a thread handle would actually contain an event
@@ -62,8 +66,12 @@
   pthread_attr_destroy(&attr);
 
   if (h && lpThreadId)
+#ifdef __FreeBSD__
+    *lpThreadId = (LONG)h->m_hThread;
+#else
     // WARNING: This can truncate thread IDs on x86_64.
     *lpThreadId = (DWORD)h->m_hThread;
+#endif
   return h;
 }
 
@@ -89,10 +97,18 @@
    int ( *start_address )( void * ),
    void *arglist,
    unsigned initflag,
+#ifdef __FreeBSD__
+   unsigned long *thrdaddr
+#else
    unsigned *thrdaddr
+#endif
 ) {
 
+#ifdef __FreeBSD__
+  HANDLE h = CreateThread(NULL, stack_size, start_address, arglist, initflag, (LPLONG)thrdaddr);
+#else
   HANDLE h = CreateThread(NULL, stack_size, start_address, arglist, initflag, (LPDWORD)thrdaddr);
+#endif
   return h;
 
 }
