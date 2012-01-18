--- ./lib/timidity/interface/w32g.h.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./lib/timidity/interface/w32g.h	2012-01-02 10:14:38.000000000 +0100
@@ -64,6 +64,9 @@
 #elif defined(_BORLANDC_)
 #define crt_beginthread(start_address,stack_size,arglist) \
 (HANDLE)_beginthread((BCC_BEGINTHREAD_START_ADDRESS)start_address,(unsigned)stack_size,(void *)arglist)
+#elif defined(__FreeBSD__)
+#define crt_beginthread(start_address,stack_size,arglist) \
+(HANDLE)CreateThread(NULL,(DWORD)stack_size,(LPTHREAD_START_ROUTINE)start_address,(LPVOID)arglist,0,NULL)
 #else
 #define crt_beginthread(start_address,stack_size,arglist) \
 (HANDLE)CreateThread(NULL,(DWORD)stack_size,(LPTHREAD_START_ROUTINE)start_address,(LPVOID)arglist,0,&dwTmp)
@@ -76,6 +79,9 @@
 #elif defined(_BORLANDC_)
 #define crt_beginthreadex(security,stack_size,start_address,arglist,initflag,thrdaddr ) \
 (HANDLE)_beginthreadNT((BCC_BEGINTHREAD_START_ADDRESS)start_address,(unsigned)stack_size,(void *)arglist,(void *)security_attrib,(unsigned long)create_flags,(unsigned long *)thread_id)
+#elif defined(__FreeBSD__)
+#define crt_beginthreadex(security,stack_size,start_address,arglist,initflag,thrdaddr ) \
+(HANDLE)CreateThread((LPSECURITY_ATTRIBUTES)security,(DWORD)stack_size,(LPTHREAD_START_ROUTINE)start_address,(LPVOID)arglist,(DWORD)initflag,(LPLONG)thrdaddr)
 #else
 #define crt_beginthreadex(security,stack_size,start_address,arglist,initflag,thrdaddr ) \
 (HANDLE)CreateThread((LPSECURITY_ATTRIBUTES)security,(DWORD)stack_size,(LPTHREAD_START_ROUTINE)start_address,(LPVOID)arglist,(DWORD)initflag,(LPDWORD)thrdaddr)
