Bug 4889: No connections are accepted after ECONNABORTED

Ignore ECONNABORTED errors when accepting connections. These "client
decided not to wait for accept(2)" errors do not indicate a problem with
the listening socket and should not lead to listening socket closure.

Also polished errno checking code for non-ignored errors.

Also documented a bug that prevents TcpAcceptor::acceptOne() from
stopping to listen on non-ignored accept errors.

Also documented ENFILE and EMFILE mishandling.

--- src/comm/TcpAcceptor.cc.orig	2018-09-30 20:57:54.000000000 +0200
+++ src/comm/TcpAcceptor.cc	2018-10-10 18:10:05.897616000 +0200
@@ -297,6 +297,7 @@
         if (intendedForUserConnections())
             logAcceptError(newConnDetails);
         notify(flag, newConnDetails);
+        // XXX: Will not stop because doAccept() is not called asynchronously.
         mustStop("Listener socket closed");
         return;
     }
@@ -366,11 +367,12 @@
 
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
