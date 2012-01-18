--- ./lib/timidity/timidity/gogo_a.c.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./lib/timidity/timidity/gogo_a.c	2012-01-02 10:14:38.000000000 +0100
@@ -108,6 +108,9 @@
 #elif defined(_BORLANDC_)
 #define crt_beginthreadex(security,stack_size,start_address,arglist,initflag,thrdaddr ) \
 (HANDLE)_beginthreadNT((BCC_BEGINTHREAD_START_ADDRESS)start_address,(unsigned)stack_size,(void *)arglist,(void *)security_attrib,(unsigned long)create_flags,(unsigned long *)thread_id)
+#elif defined(__FreeBSD__)
+#define crt_beginthreadex(security,stack_size,start_address,arglist,initflag,thrdaddr ) \
+(HANDLE)CreateThread((LPSECURITY_ATTRIBUTES)security,(DWORD)stack_size,(LPTHREAD_START_ROUTINE)start_address,(LPVOID)arglist,(DWORD)initflag,(LPLONG)thrdaddr)
 #else
 #define crt_beginthreadex(security,stack_size,start_address,arglist,initflag,thrdaddr ) \
 (HANDLE)CreateThread((LPSECURITY_ATTRIBUTES)security,(DWORD)stack_size,(LPTHREAD_START_ROUTINE)start_address,(LPVOID)arglist,(DWORD)initflag,(LPDWORD)thrdaddr)
