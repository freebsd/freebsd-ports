--- ./xbmc/cores/DllLoader/exports/emu_msvcrt.h.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/cores/DllLoader/exports/emu_msvcrt.h	2012-01-02 10:14:38.000000000 +0100
@@ -132,7 +132,11 @@
   uintptr_t dll_beginthread(void( *start_address )( void * ),unsigned stack_size,void *arglist);
   HANDLE dll_beginthreadex(LPSECURITY_ATTRIBUTES lpThreadAttributes, DWORD dwStackSize,
                            LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags,
+#ifdef __FreeBSD__
+                           LPLONG lpThreadId);
+#else
                            LPDWORD lpThreadId);
+#endif
   int dll_stati64(const char *path, struct _stati64 *buffer);
   int dll_stat64(const char *path, struct __stat64 *buffer);
 #ifdef _WIN32
