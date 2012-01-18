--- ./xbmc/linux/XThreadUtils.h.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/linux/XThreadUtils.h	2012-01-02 10:14:38.000000000 +0100
@@ -30,7 +30,11 @@
           LPTHREAD_START_ROUTINE lpStartAddress,
             LPVOID lpParameter,
         DWORD dwCreationFlags,
+#ifdef __FreeBSD__
+          LPLONG lpThreadId
+#else
           LPDWORD lpThreadId
+#endif
     );
 
 HANDLE _beginthreadex(
@@ -39,7 +43,11 @@
    int ( *start_address )( void * ),
    void *arglist,
    unsigned initflag,
+#ifdef __FreeBSD__
+   unsigned long *thrdaddr
+#else
    unsigned *thrdaddr
+#endif
 );
 
 uintptr_t _beginthread(
