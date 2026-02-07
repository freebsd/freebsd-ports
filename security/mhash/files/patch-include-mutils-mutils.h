Description: Protect some macro parameters with parentheses.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- include/mutils/mutils.h.orig
+++ include/mutils/mutils.h
@@ -103,22 +103,22 @@
 #endif
 
 #if defined(false)
-#define MUTILS_FALSE (mutils_boolean) false
+#define MUTILS_FALSE ((mutils_boolean) false)
 #else
 #if defined(FALSE)
-#define MUTILS_FALSE (mutils_boolean) FALSE
+#define MUTILS_FALSE ((mutils_boolean) FALSE)
 #else
-#define MUTILS_FALSE (mutils_boolean) 0
+#define MUTILS_FALSE ((mutils_boolean) 0)
 #endif /* FALSE */
 #endif /* false */
 
 #if defined(true)
-#define MUTILS_TRUE (mutils_boolean) true
+#define MUTILS_TRUE ((mutils_boolean) true)
 #else
 #if defined(TRUE)
-#define MUTILS_TRUE (mutils_boolean) TRUE
+#define MUTILS_TRUE ((mutils_boolean) TRUE)
 #else
-#define MUTILS_TRUE (mutils_boolean) -1
+#define MUTILS_TRUE ((mutils_boolean) -1)
 #endif /* TRUE */
 #endif /* true */
 
@@ -167,16 +167,16 @@
 
 #define mutils_swapendian32(a) \
 	((mutils_word32) \
-		(((a & (mutils_word32) 0x000000ffU) << 24) | \
-		 ((a & (mutils_word32) 0x0000ff00U) << 8)  | \
-		 ((a & (mutils_word32) 0x00ff0000U) >> 8)  | \
-		 ((a & (mutils_word32) 0xff000000U) >> 24))  \
+		((((a) & (mutils_word32) 0x000000ffU) << 24) | \
+		 (((a) & (mutils_word32) 0x0000ff00U) << 8)  | \
+		 (((a) & (mutils_word32) 0x00ff0000U) >> 8)  | \
+		 (((a) & (mutils_word32) 0xff000000U) >> 24))  \
 	)
 
 #define mutils_swapendian16(a) \
 	((mutils_word16) \
-		(((a & (mutils_word16) 0x00ffU) << 8) | \
-		 ((a & (mutils_word16) 0xff00U) >> 8))  \
+		((((a) & (mutils_word16) 0x00ffU) << 8) | \
+		 (((a) & (mutils_word16) 0xff00U) >> 8))  \
 	 )
 
 
@@ -193,30 +193,30 @@
 #define mutils_lend32(n) mutils_swapendian32(n)
 #define mutils_lend16(n) mutils_swapendian16(n)
 
-#define mutils_bend64(n) n
-#define mutils_bend32(n) n
-#define mutils_bend16(n) n
+#define mutils_bend64(n) (n)
+#define mutils_bend32(n) (n)
+#define mutils_bend16(n) (n)
 
 #define mutils_lend2sys64(n) mutils_swapendian64(n)
 #define mutils_lend2sys32(n) mutils_swapendian32(n)
 #define mutils_lend2sys16(n) mutils_swapendian16(n)
 
-#define mutils_bend2sys32(n) n
-#define mutils_bend2sys16(n) n
+#define mutils_bend2sys32(n) (n)
+#define mutils_bend2sys16(n) (n)
 
 #else
 
-#define mutils_lend64(n) n
-#define mutils_lend32(n) n
-#define mutils_lend16(n) n
+#define mutils_lend64(n) (n)
+#define mutils_lend32(n) (n)
+#define mutils_lend16(n) (n)
 
 #define mutils_bend64(n) mutils_swapendian64(n)
 #define mutils_bend32(n) mutils_swapendian32(n)
 #define mutils_bend16(n) mutils_swapendian16(n)
 
-#define mutils_lend2sys64(n) n
-#define mutils_lend2sys32(n) n
-#define mutils_lend2sys16(n) n
+#define mutils_lend2sys64(n) (n)
+#define mutils_lend2sys32(n) (n)
+#define mutils_lend2sys16(n) (n)
 
 #define mutils_bend2sys64(n) mutils_swapendian64(n)
 #define mutils_bend2sys32(n) mutils_swapendian32(n)
