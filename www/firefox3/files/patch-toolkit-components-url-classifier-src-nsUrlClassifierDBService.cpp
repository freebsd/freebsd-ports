# reported upstream as: https://bugzilla.mozilla.org/show_bug.cgi?id=469276

--- toolkit/components/url-classifier/src/nsUrlClassifierDBService.cpp.orig	2008-08-25 22:59:14.000000000 +0200
+++ toolkit/components/url-classifier/src/nsUrlClassifierDBService.cpp	2008-12-12 16:31:11.000000000 +0100
@@ -2023,8 +2023,9 @@
           return NS_ERROR_FAILURE;
         }
         const nsCSubstring& str = Substring(chunk, start, 4);
-        const PRUint32 *p = reinterpret_cast<const PRUint32*>(str.BeginReading());
-        entry->mAddChunkId = PR_ntohl(*p);
+        PRUint32 p;
+	memcpy(&p, str.BeginReading(), 4);
+        entry->mAddChunkId = PR_ntohl(p);
         if (entry->mAddChunkId == 0) {
           NS_WARNING("Received invalid chunk number.");
           return NS_ERROR_FAILURE;
@@ -2052,8 +2053,9 @@
 
         if (chunkType == CHUNK_SUB) {
           const nsCSubstring& str = Substring(chunk, start, 4);
-          const PRUint32 *p = reinterpret_cast<const PRUint32*>(str.BeginReading());
-          entry->mAddChunkId = PR_ntohl(*p);
+	  PRUint32 p;
+	  memcpy(&p, str.BeginReading(), 4);
+          entry->mAddChunkId = PR_ntohl(p);
           if (entry->mAddChunkId == 0) {
             NS_WARNING("Received invalid chunk number.");
             return NS_ERROR_FAILURE;
