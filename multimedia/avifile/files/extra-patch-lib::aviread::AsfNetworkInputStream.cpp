--- lib/aviread/AsfNetworkInputStream.cpp.orig	Fri Aug  6 12:35:40 2004
+++ lib/aviread/AsfNetworkInputStream.cpp	Fri Aug  6 12:46:32 2004
@@ -793,22 +793,24 @@
     return -1;
 }
 
-int AsfNetworkInputStream::write(const void* buffer, uint_t size)
+int AsfNetworkInputStream::write(const void* b, uint_t size)
 {
+    const char* buffer = (const char*) b;
     int wsize = size;
     while (wsize > 0)
     {
 	int i = ::write(m_iSocket, buffer, wsize);
 	if (i <= 0)
             return i;
-	(const char*)buffer += i;
+	buffer += i;
         wsize -= i;
     }
     return size;
 }
 
-int AsfNetworkInputStream::dwrite(const void* buffer, uint_t size)
+int AsfNetworkInputStream::dwrite(const void* b, uint_t size)
 {
+    const char* buffer = (const char*) b;
     if (m_lfd < 0)
     {
 	if (m_lfd == -12345)
@@ -843,7 +845,7 @@
 	int i = ::write(m_lfd, buffer, size);
 	if (i < 0)
             return i;
-	(const char*)buffer += i;
+	buffer += i;
 	size -= i;
     }
     fsync(m_lfd);
