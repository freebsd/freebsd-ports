--- lib/aviread/AsfFileInputStream.cpp.orig	Tue Oct  5 14:00:28 2004
+++ lib/aviread/AsfFileInputStream.cpp	Tue Oct  5 14:00:38 2004
@@ -18,6 +18,8 @@
 #define O_LARGEFILE 0
 #endif
 
+#define lseek64 lseek
+
 AVM_BEGIN_NAMESPACE;
 
 #define __MODULE__ "AsfFileInputStream"
