--- netwerk/base/src/nsSocketTransport.h.orig	Fri Feb  8 11:20:24 2002
+++ netwerk/base/src/nsSocketTransport.h	Fri Feb  8 11:20:29 2002
@@ -176,7 +176,7 @@
     PRFileDesc* GetSocket(void)      { return mSocketFD;    }
     PRInt16     GetSelectFlags(void) { return mSelectFlags; }
     PRCList*    GetListNode(void)    { return &mListLink;   }
-    
+
     static nsSocketTransport* GetInstance(PRCList* qp) { return (nsSocketTransport*)((char*)qp - offsetof(nsSocketTransport, mListLink)); }
     
     PRBool CanBeReused() { return 
@@ -237,8 +237,27 @@
     inline void ClearFlag(nsSocketReadWriteInfo aFlag) {
         mReadWriteState &= ~aFlag;
     } 
+
+    PRInt32     GetSocketPort(void)  { return (mProxyPort != -1 && !mProxyTransparent) ? mProxyPort : mPort; }
+    const char *GetSocketHost(void)  { return (mProxyHost && !mProxyTransparent) ? mProxyHost : mHostName; }
     
 protected:
+    class nsNetAddrList {
+    public:
+        nsNetAddrList() : mList(nsnull), mLen(0) {}
+       ~nsNetAddrList() { delete[] mList; }
+
+        // allocate space for the address list
+        nsresult Init(PRUint32 len);
+
+        // given a net addr in the list, return the next addr.
+        // if given NULL, then return the first addr in the list.
+        // returns NULL if given addr is the last addr.
+        PRNetAddr *GetNext(PRNetAddr *currentAddr);
+    private:
+        PRNetAddr *mList;
+        PRUint32   mLen;
+    };
     
     nsSocketState                   mCurrentState;
     nsCOMPtr<nsIRequest>            mDNSRequest;
@@ -249,7 +268,8 @@
     PRIntervalTime                  mLastActiveTime;
     PRCList                         mListLink;
     PRMonitor*                      mMonitor;
-    PRNetAddr                       mNetAddress;
+    nsNetAddrList                   mNetAddrList;
+    PRNetAddr                      *mNetAddress;
     nsSocketOperation               mOperation;
     nsCOMPtr<nsISupports>           mSecurityInfo;
 
@@ -415,6 +435,7 @@
     PRBool IsInitialized() { return mStartFired; }
     PRBool IsSuspended() { return mSuspendCount > 0; }
     PRBool IsCanceled() { return mCanceled; }
+    PRBool HasFailed() { return NS_FAILED(mStatus); }
 
     void SetTransport(nsSocketTransport *);
     void SetObserver(nsIRequestObserver *obs) { mObserver = obs; }
