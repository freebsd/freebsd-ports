--- src/test/org/apache/commons/net/telnet/TelnetClientTest.java.orig	Sat Sep 30 23:40:24 2006
+++ src/test/org/apache/commons/net/telnet/TelnetClientTest.java	Sat Sep 30 23:40:36 2006
@@ -784,7 +784,7 @@
         os1.flush();
         os1.write("A".getBytes());
         os1.flush();
-        Thread.sleep(1000);
+//        Thread.sleep(1000);
         InputStream instr = NOREAD.client.getInputStream();
         byte[] buff = new byte[4];
         int ret_read = 0;
@@ -879,4 +879,4 @@
         }
     }
 
-}
\ No newline at end of file
+}
