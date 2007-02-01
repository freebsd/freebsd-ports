--- ./src/os/OsServerSocket.cpp.orig	Tue Jan  2 17:41:00 2007
+++ ./src/os/OsServerSocket.cpp	Tue Jan  2 18:00:22 2007
@@ -142,7 +142,8 @@
    {
       error = OsSocketGetERRNO();
       OsSysLog::add(FAC_KERNEL, PRI_ERR,
-                    "OsServerSocket:  bind to port %d failed with error: %d = 0x%x",
+                    "OsServerSocket:  bind to port %s:%d failed with error: %d = 0x%x",
+                    inet_ntoa(localAddr.sin_addr),
                     ((PORT_DEFAULT == serverPort) ? 0 : serverPort), error, error);
       socketDescriptor = OS_INVALID_SOCKET_DESCRIPTOR;
       goto EXIT;
