--- src/anet-sockets-packet.adb.orig	2013-12-04 09:55:07.000000000 +0000
+++ src/anet-sockets-packet.adb
@@ -129,7 +129,8 @@ package body Anet.Sockets.Packet is
       To     : Hardware_Addr_Type;
       Iface  : Types.Iface_Name_Type)
    is
-      Res     : C.int;
+      use Interfaces.C;
+      Res     : C.long;
       Ll_Dest : Thin.Sockaddr_Ll_Type;
    begin
       Ll_Dest.Sa_Ifindex  := C.int (Net_Ifaces.Get_Iface_Index
