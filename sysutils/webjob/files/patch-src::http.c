diff -urP webjob-1.3.0/src/http.c webjob-1.3.0.amd64/src/http.c
--- src/http.c.orig	Wed Jul 23 15:16:07 2003
+++ src/http.c	Sun Apr  4 23:49:52 2004
@@ -144,7 +144,7 @@
     sprintf(pcRequest, "%s %s%s%s HTTP/1.1\r\n"
                        "Host: %s:%d\r\n"
                        "Content-Type: application/octet-stream\r\n"
-#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64)
+#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64) || defined(K_CPU_AMD64)
                        "Content-Length: %u\r\n"
 #else
                        "Content-Length: %lu\r\n"
@@ -166,7 +166,7 @@
     sprintf(pcRequest, "%s %s%s%s HTTP/1.1\r\n"
                        "Host: %s:%d\r\n"
                        "Content-Type: application/octet-stream\r\n"
-#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64)
+#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64) || defined(K_CPU_AMD64)
                        "Content-Length: %u\r\n"
 #else
                        "Content-Length: %lu\r\n"
@@ -1283,7 +1283,7 @@
    */
   if (ui32ContentLength > (K_UINT32) HTTP_MAX_MEMORY_SIZE)
   {
-#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64)
+#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64) || defined(K_CPU_AMD64)
     snprintf(pcError, MESSAGE_SIZE, "%s: Content-Length = [%u] > [%u]: Length exceeds internally defined limit.",
 #else
     snprintf(pcError, MESSAGE_SIZE, "%s: Content-Length = [%lu] > [%lu]: Length exceeds internally defined limit.",
@@ -1339,7 +1339,7 @@
   }
   if (ui32Offset != ui32ContentLength)
   {
-#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64)
+#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64) || defined(K_CPU_AMD64)
     snprintf(pcError, MESSAGE_SIZE, "%s: Actual-Length = [%u] != [%u]: Actual-Length vs Content-Length Mismatch.",
 #else
     snprintf(pcError, MESSAGE_SIZE, "%s: Actual-Length = [%lu] != [%lu]: Actual-Length vs Content-Length Mismatch.",
@@ -1409,7 +1409,7 @@
   }
   if (ui32Offset != ui32ContentLength)
   {
-#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64)
+#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64) || defined(K_CPU_AMD64)
     snprintf(pcError, MESSAGE_SIZE, "%s: Actual-Length = [%u] != [%u]: Actual-Length vs Content-Length Mismatch.",
 #else
     snprintf(pcError, MESSAGE_SIZE, "%s: Actual-Length = [%lu] != [%lu]: Actual-Length vs Content-Length Mismatch.",
@@ -2164,7 +2164,7 @@
    */
   if (psURL->ui32DownloadLimit != 0 && psResponseHeader->ui32ContentLength > psURL->ui32DownloadLimit)
   {
-#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64)
+#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64) || defined(K_CPU_AMD64)
     snprintf(pcError, MESSAGE_SIZE, "%s: Content-Length = [%u] > [%u]: Length exceeds user defined limit.",
 #else
     snprintf(pcError, MESSAGE_SIZE, "%s: Content-Length = [%lu] > [%lu]: Length exceeds user defined limit.",
