--- src/comm/TcpAcceptor.cc.orig	2018-10-27 20:44:55 UTC
+++ src/comm/TcpAcceptor.cc
@@ -297,6 +297,7 @@ Comm::TcpAcceptor::acceptOne()
         if (intendedForUserConnections())
             logAcceptError(newConnDetails);
         notify(flag, newConnDetails);
+        // XXX: Will not stop because doAccept() is not called asynchronously.
         mustStop("Listener socket closed");
         return;
     }
@@ -366,11 +367,12 @@ Comm::TcpAcceptor::oldAccept(Comm::Conne
 
         PROF_stop(comm_accept);
 
-        if (ignoreErrno(errcode)) {
+        if (ignoreErrno(errcode) || errcode == ECONNABORTED) {
             debugs(50, 5, status() << ": " << xstrerr(errcode));
             return Comm::NOMESSAGE;
-        } else if (ENFILE == errno || EMFILE == errno) {
+        } else if (errcode == ENFILE || errcode == EMFILE) {
             debugs(50, 3, status() << ": " << xstrerr(errcode));
+            // XXX: These errors do not imply that we should stop listening.
             return Comm::COMM_ERROR;
         } else {
             debugs(50, DBG_IMPORTANT, MYNAME << status() << ": " << xstrerr(errcode));
