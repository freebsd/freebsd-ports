--- netwerk/base/src/nsSocketTransport.cpp.orig	Thu Feb  7 11:26:46 2002
+++ netwerk/base/src/nsSocketTransport.cpp	Thu Mar 21 12:24:23 2002
@@ -513,21 +513,8 @@
 
             // on connection failure, reuse next address if one exists
             if (mStatus == NS_ERROR_CONNECTION_REFUSED) {
-                mNetAddress = mNetAddrList.GetNext(mNetAddress);
-                if (mNetAddress) {
-#if defined(PR_LOGGING)
-                    char buf[50];
-                    PR_NetAddrToString(mNetAddress, buf, sizeof(buf));
-                    LOG(("connection failed... trying %s\n", buf));
-#endif
-                    PR_Close(mSocketFD);
-                    mSocketFD = nsnull;
-
-                    // mask error status so we'll return to this state
-                    mStatus = NS_OK;
-
-                    // need to re-enter Process() asynchronously
-                    mService->AddToWorkQ(this);
+                LOG(("connection failed [this=%x error=%x]\n", this, mStatus));
+                if (TryNextAddress()) {
                     done = PR_TRUE;
                     continue;
                 }
@@ -545,6 +532,23 @@
             LOG(("nsSocketTransport: Transport [host=%s:%d this=%x] is in Timeout state.\n",
                 mHostName, mPort, this));
             mStatus = NS_ERROR_NET_TIMEOUT;
+
+            // on timeout, reuse next address if one exists ... do this only
+            // if we haven't already fired OnStartRequest.
+            if (mReadRequest || mWriteRequest) {
+                PRBool firedOnStart = PR_TRUE; // initial value doesn't matter
+                if (mReadRequest)
+                    firedOnStart = mReadRequest->IsInitialized();
+                if (!firedOnStart && mWriteRequest)
+                    firedOnStart = mWriteRequest->IsInitialized();
+                if (!firedOnStart && TryNextAddress()) {
+                    // a little bit of hackery here so we'll end up in the
+                    // WaitConnect state...
+                    mCurrentState = eSocketState_WaitConnect;
+                    done = PR_TRUE;
+                    continue;
+                }
+            }
             break;
 
         default:
@@ -591,6 +595,29 @@
     if (mWriteRequest)
         mWriteRequest->Cancel(status);
     return NS_OK;
+}
+
+PRBool
+nsSocketTransport::TryNextAddress()
+{
+    mNetAddress = mNetAddrList.GetNext(mNetAddress);
+    if (mNetAddress) {
+#if defined(PR_LOGGING)
+        char buf[64];
+        PR_NetAddrToString(mNetAddress, buf, sizeof(buf));
+        LOG(("  ...trying next address: %s\n", buf));
+#endif
+        PR_Close(mSocketFD);
+        mSocketFD = nsnull;
+
+        // mask error status so we'll return to this state
+        mStatus = NS_OK;
+
+        // need to re-enter Process() asynchronously
+        mService->AddToWorkQ(this);
+        return PR_TRUE;
+    }
+    return PR_FALSE;
 }
 
 void
