--- src/anet-sockets-netlink.adb.orig	2013-12-04 09:55:07.000000000 +0000
+++ src/anet-sockets-netlink.adb
@@ -128,7 +128,8 @@ package body Anet.Sockets.Netlink is
       Item   : Ada.Streams.Stream_Element_Array;
       To     : Netlink_Addr_Type)
    is
-      Res : C.int;
+      use Interfaces.C;
+      Res : C.long;
       Dst : Thin.Sockaddr_Nl_Type
         := (Nl_Pid => Interfaces.Unsigned_32 (To),
             others => <>);
