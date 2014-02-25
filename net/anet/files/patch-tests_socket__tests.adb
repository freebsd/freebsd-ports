--- tests/socket_tests.adb.orig	2013-12-04 09:55:07.000000000 +0000
+++ tests/socket_tests.adb
@@ -203,15 +203,15 @@ package body Socket_Tests is
       T.Add_Test_Routine
         (Routine => Send_Unix_Datagram'Access,
          Name    => "Send data (Unix, datagram)");
-      T.Add_Test_Routine
-        (Routine => Send_Netlink_Raw'Access,
-         Name    => "Send data (Netlink, raw)");
-      T.Add_Test_Routine
-        (Routine => Send_Packet_Datagram'Access,
-         Name    => "Send data (Packet, datagram)");
-      T.Add_Test_Routine
-        (Routine => Send_Packet_Raw'Access,
-         Name    => "Send data (Packet, raw)");
+      --  T.Add_Test_Routine
+      --    (Routine => Send_Netlink_Raw'Access,
+      --     Name    => "Send data (Netlink, raw)");
+      --  T.Add_Test_Routine
+      --    (Routine => Send_Packet_Datagram'Access,
+      --    Name    => "Send data (Packet, datagram)");
+      --  T.Add_Test_Routine
+      --    (Routine => Send_Packet_Raw'Access,
+      --    Name    => "Send data (Packet, raw)");
       T.Add_Test_Routine
         (Routine => Send_Various_Buffers'Access,
          Name    => "Send data (various buffer ranges)");
@@ -333,8 +333,9 @@ package body Socket_Tests is
    begin
       Sock.Init;
       Sock.Bind (Address => Grp,
+                 Iface   => "em0",
                  Port    => Test_Utils.Listen_Port);
-      Sock.Join_Multicast_Group (Group => Grp);
+      Sock.Join_Multicast_Group (Group => Grp, Iface => "em0");
 
       Rcvr.Listen (Callback => Test_Utils.Dump'Access);
 
