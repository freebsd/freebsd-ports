--- src/bbcp_BuffPool.C.orig	2015-01-16 13:30:31.000000000 -0800
+++ src/bbcp_BuffPool.C	2015-01-16 13:33:14.000000000 -0800
@@ -32,7 +32,7 @@
 #include <inttypes.h>
 #include <sys/mman.h>
 
-#if defined(MACOS) || defined(AIX)
+#if defined(MACOS) || defined(AIX) || defined(FREEBSD)
 #define memalign(pgsz,amt) valloc(amt)
 #else
 #include <malloc.h>
@@ -84,14 +84,14 @@
 
 // Free all of the buffers in the empty queue
 //
-   while(currp = last_empty)
+   while((currp = last_empty))
         {last_empty = last_empty->next; delete currp;}
 //cerr <<bbcp_Debug.Who <<"Bdestroy num " <<j++ <<" @ " <<hex <<(int)currp <<dec <<endl;
 
 // Free all full buffers
 //
    FullPool.Lock();
-   while(currp = next_full)
+   while((currp = next_full))
         {next_full = next_full->next; delete currp;}
    FullPool.UnLock();
 }
