--- netwerk/base/src/nsSocketTransport.cpp.orig	Fri Feb  8 11:20:08 2002
+++ netwerk/base/src/nsSocketTransport.cpp	Fri Feb  8 11:20:16 2002
@@ -143,6 +143,7 @@
     mHostName(nsnull),
     mPort(-1),
     mMonitor(nsnull),
+    mNetAddress(nsnull),
     mOperation(eSocketOperation_None),
     mProxyPort(-1),
     mProxyHost(nsnull),
@@ -183,12 +184,6 @@
     SetWriteType(eSocketWrite_None);
     
     //
-    // Set up Internet defaults...
-    //
-    memset(&mNetAddress, 0, sizeof(mNetAddress));
-    PR_SetNetAddr(PR_IpAddrAny, PR_AF_INET6, 0, &mNetAddress);
-    
-    //
     // Initialize the global connect timeout value if necessary...
     //
     if (PR_INTERVAL_NO_WAIT == gConnectTimeout)
@@ -415,6 +410,14 @@
 
     while (!done) {
         //
+        // Check for failure on any socket requests
+        //
+        if (mReadRequest && mReadRequest->HasFailed())
+            mReadRequest->GetStatus(&mStatus);
+        else if (mWriteRequest && mWriteRequest->HasFailed())
+            mWriteRequest->GetStatus(&mStatus);
+
+        //
         // If an error has occurred then move into the error state...
         //
         if (NS_FAILED(mStatus) && (NS_BASE_STREAM_WOULD_BLOCK != mStatus))
@@ -495,17 +498,40 @@
             // Send status message
             // only send a status if doResolveHost is going to do some
             // resolution
-            if (mStatus != NS_OK)
+            if (mStatus == NS_BASE_STREAM_WOULD_BLOCK)
                 OnStatus_Locked(NS_NET_STATUS_RESOLVING_HOST);
             break;
 
         case eSocketState_WaitConnect:
             LOG(("nsSocketTransport: Transport [host=%s:%d this=%x] is in WaitConnect state.\n",
                 mHostName, mPort, this));
-            mStatus = doConnection(aSelectFlags);
 
             // Send status message
             OnStatus_Locked(NS_NET_STATUS_CONNECTING_TO);
+
+            mStatus = doConnection(aSelectFlags);
+
+            // on connection failure, reuse next address if one exists
+            if (mStatus == NS_ERROR_CONNECTION_REFUSED) {
+                mNetAddress = mNetAddrList.GetNext(mNetAddress);
+                if (mNetAddress) {
+#if defined(PR_LOGGING)
+                    char buf[50];
+                    PR_NetAddrToString(mNetAddress, buf, sizeof(buf));
+                    LOG(("connection failed... trying %s\n", buf));
+#endif
+                    PR_Close(mSocketFD);
+                    mSocketFD = nsnull;
+
+                    // mask error status so we'll return to this state
+                    mStatus = NS_OK;
+
+                    // need to re-enter Process() asynchronously
+                    mService->AddToWorkQ(this);
+                    done = PR_TRUE;
+                    continue;
+                }
+            }
             break;
 
         case eSocketState_WaitReadWrite:
@@ -633,21 +659,19 @@
 
     NS_ASSERTION(eSocketState_WaitDNS == mCurrentState, "Wrong state.");
 
-    LOG(("nsSocketTransport: Entering doResolveHost() [host=%s:%d this=%x].\n", 
+    LOG(("nsSocketTransport: Entering doResolveHost() [host=%s:%d %x].\n", 
         mHostName, mPort, this));
 
+    // 
+    // The hostname is being resolved...
+    //
+    if (mDNSRequest)
+        return NS_BASE_STREAM_WOULD_BLOCK;
+
     //
     // The hostname has not been resolved yet...
     //
-    if (PR_IsNetAddrType(&mNetAddress, PR_IpAddrAny)) {
-        //
-        // Initialize the port used for the connection...
-        //
-        // XXX: The list of ports must be restricted - see net_bad_ports_table[] in 
-        //      mozilla/network/main/mkconect.c
-        //
-        mNetAddress.ipv6.port = PR_htons(((mProxyPort != -1 && !mProxyTransparent) ? mProxyPort : mPort));
-
+    if (mNetAddress == nsnull) {
         PR_ExitMonitor(mMonitor);
 
         nsIDNSService* pDNSService = mService->GetCachedDNSService();
@@ -659,9 +683,7 @@
         // Give up the SocketTransport lock.  This allows the DNS thread to call the
         // nsIDNSListener notifications without blocking...
         //
-        rv = pDNSService->Lookup((mProxyHost && !mProxyTransparent) ? mProxyHost : mHostName, 
-                                 this, 
-                                 nsnull, 
+        rv = pDNSService->Lookup(GetSocketHost(), this, nsnull, 
                                  getter_AddRefs(mDNSRequest));
         //
         // Aquire the SocketTransport lock again...
@@ -672,7 +694,7 @@
             //
             // The DNS lookup has finished...  It has either failed or succeeded.
             //
-            if (NS_FAILED(mStatus) || !PR_IsNetAddrType(&mNetAddress, PR_IpAddrAny)) {
+            if (NS_FAILED(mStatus) || mNetAddress) {
                 mDNSRequest = 0;
                 rv = mStatus;
             } 
@@ -687,10 +709,8 @@
         }
     }
 
-    LOG(("nsSocketTransport: Leaving doResolveHost() [%s:%d %x].\t"
-        "rv = %x.\n\n",
+    LOG(("nsSocketTransport: Leaving doResolveHost() [%s:%d %x] rv = %x\n",
         mHostName, mPort, this, rv));
-
     return rv;
 }
 
@@ -832,7 +852,7 @@
         //    This is only done the first time doConnection(...) is called.
         //
         if (NS_SUCCEEDED(rv)) {
-            status = PR_Connect(mSocketFD, &mNetAddress, gConnectTimeout);
+            status = PR_Connect(mSocketFD, mNetAddress, gConnectTimeout);
             if (PR_SUCCESS != status) {
                 PRErrorCode code = PR_GetError();
                 //
@@ -932,14 +952,17 @@
     //
     // The hostname has not been resolved yet...
     //
-    if (PR_IsNetAddrType(&mNetAddress, PR_IpAddrAny)) {
+    if (mNetAddress == nsnull) {
         nsIDNSService* pDNSService = mService->GetCachedDNSService();
         if (!pDNSService) {
             return NS_ERROR_UNEXPECTED;
         }
 
         nsXPIDLCString result;
-        const char *host = (mProxyHost && !mProxyTransparent) ? mProxyHost : mHostName;
+        const char *host = GetSocketHost();
+
+        // XXX DNS service does not provide a synchronous resolver that returns
+        // the entire nsHostEnt struct.
         rv = pDNSService->Resolve(host, getter_Copies(result));
         if (NS_FAILED(rv)) return rv;
 
@@ -953,16 +976,18 @@
             return NS_ERROR_FAILURE;
         }
 
+        mNetAddrList.Init(1);
+        mNetAddress = mNetAddrList.GetNext(nsnull);
+
+        PR_SetNetAddr(PR_IpAddrAny, PR_AF_INET6, GetSocketPort(), mNetAddress);
+
         if (addr.raw.family == PR_AF_INET)
-            PR_ConvertIPv4AddrToIPv6(addr.inet.ip, &mNetAddress.ipv6.ip);
+            PR_ConvertIPv4AddrToIPv6(addr.inet.ip, &mNetAddress->ipv6.ip);
         else
-            memcpy(&mNetAddress.ipv6.ip, &addr.ipv6.ip, sizeof(mNetAddress.ipv6.ip));
-
-        mNetAddress.ipv6.port
-            = PR_htons(((mProxyPort != -1 && !mProxyTransparent) ? mProxyPort : mPort));
+            memcpy(&mNetAddress->ipv6.ip, &addr.ipv6.ip, sizeof(mNetAddress->ipv6.ip));
 
         LOG(("address { family=%hu, port=%hu }\n",
-            mNetAddress.ipv6.family, PR_ntohs(mNetAddress.ipv6.port)));
+            mNetAddress->ipv6.family, PR_ntohs(mNetAddress->ipv6.port)));
     }
 
     //
@@ -1036,7 +1061,6 @@
     if (mReadRequest) {
         if (mReadRequest->IsCanceled() || (mBytesExpected == 0)) {
             LOG(("nsSocketTransport: [this=%x] completing read request due to cancelation\n", this));
-            mSelectFlags &= ~PR_POLL_READ;
             mReadRequest->GetStatus(&readStatus);
             CompleteAsyncRead();
             if (NS_FAILED(readStatus))
@@ -1078,7 +1102,6 @@
     if (mWriteRequest) {
         if (mWriteRequest->IsCanceled()) {
             LOG(("nsSocketTransport: [this=%x] completing write request due to cancelation\n", this));
-            mSelectFlags &= ~PR_POLL_WRITE;
             mWriteRequest->GetStatus(&writeStatus);
             CompleteAsyncWrite();
             if (NS_FAILED(writeStatus))
@@ -1485,23 +1508,44 @@
     nsAutoMonitor mon(mMonitor);
     nsresult rv = NS_OK;
 
-    if (aHostEnt->hostEnt.h_addr_list && aHostEnt->hostEnt.h_addr_list[0]) {
-        if (aHostEnt->hostEnt.h_addrtype == PR_AF_INET6)
-            memcpy(&mNetAddress.ipv6.ip, aHostEnt->hostEnt.h_addr_list[0], sizeof(mNetAddress.ipv6.ip));
-        else
-            PR_ConvertIPv4AddrToIPv6(*(PRUint32*)aHostEnt->hostEnt.h_addr_list[0], &mNetAddress.ipv6.ip);
+    char **addrList = aHostEnt->hostEnt.h_addr_list;
+    
+    if (addrList && addrList[0]) {
+        PRUint32 len = 0;
+
+        LOG(("nsSocketTransport::OnFound [%s:%d %x] lookup succeeded [FQDN=%s]\n",
+            mHostName, mPort, this, aHostEnt->hostEnt.h_name));
+
+        // determine the number of address in the list
+        for (; *addrList; ++addrList)
+            ++len;
+        addrList -= len;
+
+        // allocate space for the addresses
+        mNetAddrList.Init(len);
+
+        // populate the address list
+        PRNetAddr *addr = nsnull;
+        while ((addr = mNetAddrList.GetNext(addr)) != nsnull) {
+            PR_SetNetAddr(PR_IpAddrAny, PR_AF_INET6, GetSocketPort(), addr);
+            if (aHostEnt->hostEnt.h_addrtype == PR_AF_INET6)
+                memcpy(&addr->ipv6.ip, *addrList, sizeof(addr->ipv6.ip));
+            else
+                PR_ConvertIPv4AddrToIPv6(*(PRUint32 *)(*addrList), &addr->ipv6.ip);
+            ++addrList;
 #if defined(PR_LOGGING)
-        char addrbuf[50];
-        PR_NetAddrToString(&mNetAddress, addrbuf, sizeof(addrbuf));
-        LOG(("nsSocketTransport: OnFound(...) [%s:%d %x]."
-            "  DNS lookup succeeded => %s (%s)\n",
-            mHostName, mPort, this,
-            aHostEnt->hostEnt.h_name,
-            addrbuf));
+            char buf[50];
+            PR_NetAddrToString(addr, buf, sizeof(buf));
+            LOG(("  => %s\n", buf));
 #endif
-    } else {
-        // XXX: What should happen here?  The GetHostByName(...) succeeded but 
-        //      there are *no* A records...
+        }
+
+        // start with first address in list
+        mNetAddress = mNetAddrList.GetNext(nsnull);
+    }
+    else {
+        // XXX: What should happen here?  The DNS lookup succeeded, but there
+        //      are no address records...
         rv = NS_ERROR_FAILURE;
 
         LOG(("nsSocketTransport: OnFound(...) [%s:%d %x]."
@@ -1531,7 +1575,7 @@
     // If the lookup failed, set the status...
     if (NS_FAILED(aStatus))
         mStatus = aStatus;
-    else if (PR_IsNetAddrType(&mNetAddress, PR_IpAddrAny))
+    else if (mNetAddress == nsnull)
         mStatus = NS_ERROR_ABORT;
 
     // Start processing the transport again - if necessary...
@@ -1852,7 +1896,7 @@
     *_retval = (char*)nsMemory::Alloc(aLen);
     if (!*_retval) return NS_ERROR_FAILURE;
 
-    PRStatus status = PR_NetAddrToString(&mNetAddress, *_retval, aLen);
+    PRStatus status = PR_NetAddrToString(mNetAddress, *_retval, aLen);
 
     if (PR_FAILURE == status) {
         nsMemory::Free(*_retval);
@@ -1968,6 +2012,37 @@
     
     if (--mSocketRef == 0)
         CloseConnection();
+}
+
+//
+//----------------------------------------------------------------------------
+// nsSocketTransport::nsNetAddrList
+//----------------------------------------------------------------------------
+//
+
+nsresult nsSocketTransport::
+nsNetAddrList::Init(PRUint32 len)
+{
+    NS_ASSERTION(!mList, "already initialized");
+    mList = new PRNetAddr[len];
+    if (!mList)
+        return NS_ERROR_OUT_OF_MEMORY;
+    mLen = len;
+    return NS_OK;
+}
+
+PRNetAddr *nsSocketTransport::
+nsNetAddrList::GetNext(PRNetAddr *addr)
+{
+    if (!addr)
+        return mList;
+
+    PRUint32 offset = addr - mList;
+    NS_ASSERTION(offset < mLen, "invalid address");
+    if (offset + 1 < mLen)
+        return addr + 1;
+
+    return nsnull;
 }
 
 //
