commit 120bf44989391164c924e97d3142dc1352ab7970
Author: Miroslav Lichvar <mlichvar@redhat.com>
Date:   Thu Aug 28 09:33:34 2025 +0200

    test: fix socket unit test to use non-blocking accepted sockets
    
    SCK_AcceptConnection() always returns a non-blocking socket. Clear the
    O_NONBLOCK flag in the socket unit test, which relies on blocking, to
    avoid failures.
    
    Reported-by: Matthias Andree <matthias.andree@gmx.de>

--- test/unit/socket.c.orig	2025-08-27 12:05:31 UTC
+++ test/unit/socket.c
@@ -191,6 +191,7 @@ test_unit(void)
         s3 = SCK_AcceptConnection(s1, &sa2);
         TEST_CHECK(UTI_CompareIPs(&sa1.ip_addr, &sa2.ip_addr, NULL) == 0);
 
+        fcntl(s3, F_SETFL, fcntl(s3, F_GETFL) & ~O_NONBLOCK);
         send_and_recv(SCK_ADDR_IP, 1, 1, s3, s2);
 
         SCK_ShutdownConnection(s2);
@@ -227,6 +228,7 @@ test_unit(void)
     s3 = SCK_AcceptConnection(s1, &sa2);
     TEST_CHECK(sa2.ip_addr.family == IPADDR_UNSPEC);
 
+    fcntl(s3, F_SETFL, fcntl(s3, F_GETFL) & ~O_NONBLOCK);
     send_and_recv(SCK_ADDR_UNIX, 1, i % 2, s3, s2);
 
     if (i % 4)
