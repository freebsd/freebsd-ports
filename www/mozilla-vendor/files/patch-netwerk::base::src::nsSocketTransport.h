--- netwerk/base/src/nsSocketTransport.h.orig	Sat Feb  2 11:45:25 2002
+++ netwerk/base/src/nsSocketTransport.h	Thu Mar 21 12:24:26 2002
@@ -208,6 +208,8 @@
     nsresult doReadWrite(PRInt16 aSelectFlags);
     nsresult doResolveHost();
 
+    PRBool TryNextAddress();
+
     void CompleteAsyncRead();
     void CompleteAsyncWrite();
 
@@ -378,7 +380,7 @@
 
     void        SetSocket(PRFileDesc *aSock) { mSock = aSock; }
     PRUint32    GetOffset() { return mOffset; }
-    void        SetOffset(PRUint32 o) { mOffset = o; }
+    void        SetOffset(PRUint32 offset) { mOffset = offset; }
     PRBool      GotWouldBlock() { return mError == PR_WOULD_BLOCK_ERROR; }
     PRBool      GotError() { return mError != 0; }
     PRErrorCode GetError() { return mError; }
