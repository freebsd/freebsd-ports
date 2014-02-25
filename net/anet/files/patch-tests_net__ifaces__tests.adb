--- tests/net_ifaces_tests.adb.orig	2013-12-04 09:55:07.000000000 +0000
+++ tests/net_ifaces_tests.adb
@@ -45,8 +45,9 @@ package body Net_Ifaces_Tests is
          when Sockets.Socket_Error => null;
       end;
 
-      Assert (Condition => Net_Ifaces.Get_Iface_Index (Name => "lo") = 1,
-              Message   => "Loopback index not 1");
+      --  Loopback interface is not expected to be first on BSD, bad assertion
+      --  Assert (Condition => Net_Ifaces.Get_Iface_Index (Name => "lo") = 1,
+      --          Message   => "Loopback index not 1");
    end Get_Loopback_Interface_Index;
 
    -------------------------------------------------------------------------
@@ -89,9 +90,10 @@ package body Net_Ifaces_Tests is
       T.Add_Test_Routine
         (Routine => Get_Loopback_Interface_Index'Access,
          Name    => "Get iface index for loopback");
-      T.Add_Test_Routine
-        (Routine => Get_Loopback_Interface_Mac'Access,
-         Name    => "Get iface hw addr for loopback");
+      --  hw addr is not supported on BSD
+      --  T.Add_Test_Routine
+      --    (Routine => Get_Loopback_Interface_Mac'Access,
+      --     Name    => "Get iface hw addr for loopback");
       T.Add_Test_Routine
         (Routine => Get_Loopback_Interface_IP'Access,
          Name    => "Get iface IP addr for loopback");
