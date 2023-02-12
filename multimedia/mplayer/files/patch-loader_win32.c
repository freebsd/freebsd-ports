--- loader/win32.c.orig	2021-01-23 18:22:09 UTC
+++ loader/win32.c
@@ -1504,7 +1504,7 @@ static void WINAPI expDeleteCriticalSection(CRITICAL_S
 static int WINAPI expGetCurrentThreadId(void)
 {
     dbgprintf("GetCurrentThreadId() => %d\n", pthread_self());
-    return pthread_self();
+    return (int)pthread_self();
 }
 static int WINAPI expGetCurrentProcess(void)
 {
@@ -2019,15 +2019,15 @@ static DWORD WINAPI expSignalObjectAndWait(HANDLE hObj
         expSetEvent(mlist);
         break;
     case 1:  // Semaphore
-        expReleaseSemaphore(mlist, 1, NULL);
+        expReleaseSemaphore((long)mlist, 1, NULL);
         break;
     case 2:  // Mutex
-        expReleaseMutex(mlist);
+        expReleaseMutex((long)mlist);
         break;
     default:
         dbgprintf("Signalling unknown object type %d!\n", hObjectToSignal);
     }
-    return expWaitForSingleObject(hObjectToWaitOn, dwMilliseconds);
+    return (DWORD)expWaitForSingleObject((void*)hObjectToWaitOn, dwMilliseconds);
 }
 
 static long WINAPI expRegOpenKeyExA(long key, const char* subkey, long reserved, long access, int* newkey)
@@ -2751,7 +2751,7 @@ static int WINAPI expEnumDisplayMonitors(void *dc, REC
 {
     dbgprintf("EnumDisplayMonitors(0x%x, 0x%x, 0x%x, 0x%x) => ?\n",
 	dc, r, callback_proc, callback_param);
-    return callback_proc(0, dc, r, callback_param);
+    return callback_proc(0, (HDC)dc, r, (LPARAM)callback_param);
 }
 
 #if 0
@@ -2851,14 +2851,14 @@ static int WINAPI expEnumWindows(int (*callback_func)(
 {
     int i, i2;
     dbgprintf("EnumWindows(0x%x, 0x%x) => 1\n", callback_func, callback_param);
-    i = callback_func(0, callback_param);
-    i2 = callback_func(1, callback_param);
+    i = callback_func(0, (LPARAM)callback_param);
+    i2 = callback_func(1, (LPARAM)callback_param);
     return i && i2;
 }
 
 static int WINAPI expGetWindowThreadProcessId(HWND win, int *pid_data)
 {
-    int tid = pthread_self();
+    int tid = (int)pthread_self();
     dbgprintf("GetWindowThreadProcessId(0x%x, 0x%x) => %d\n",
 	win, pid_data, tid);
     if (pid_data)
@@ -4940,7 +4940,7 @@ static HPALETTE WINAPI expCreatePalette(CONST LOGPALET
     dbgprintf("CreatePalette(%x) => NULL\n", lpgpl);
 
     i = sizeof(LOGPALETTE)+((lpgpl->palNumEntries-1)*sizeof(PALETTEENTRY));
-    test = malloc(i);
+    test = (HPALETTE)malloc(i);
     memcpy((void *)test, lpgpl, i);
 
     return test;
