--- src/anet-sockets.adb.orig	2013-12-04 09:55:07.000000000 +0000
+++ src/anet-sockets.adb
@@ -54,7 +54,7 @@ package body Anet.Sockets is
 
    procedure Check_Complete_Send
      (Item      : Ada.Streams.Stream_Element_Array;
-      Result    : Interfaces.C.int;
+      Result    : Interfaces.C.long;
       Error_Msg : String)
    is
       use Ada.Streams;
@@ -197,7 +197,8 @@ package body Anet.Sockets is
      (Socket : Socket_Type;
       Item   : Ada.Streams.Stream_Element_Array)
    is
-      Res : C.int;
+      use Interfaces.C;
+      Res : C.long;
    begin
       Res := Thin.C_Send (S     => Socket.Sock_FD,
                           Buf   => Item'Address,
@@ -217,6 +218,49 @@ package body Anet.Sockets is
 
    -------------------------------------------------------------------------
 
+   procedure Set_Multicast_Interface
+     (Socket : Socket_Type;
+      IPAddr : IPv4_Addr_Type)
+   is
+      Res : C.int;
+   begin
+      Res := Thin.C_Setsockopt
+        (S       => Socket.Sock_FD,
+         Level   => Constants.Sys.IPPROTO_IP,
+         Optname => Constants.Sys.IP_MULTICAST_IF,
+         Optval  => IPAddr'Address,
+         Optlen  => 4);
+
+      if Res = C_Failure then
+         raise Socket_Error with "Unable set IPv4 Multicast IF option "
+           & " on '" & To_String (IPAddr) & "': " & Get_Errno_String;
+      end if;
+   end Set_Multicast_Interface;
+
+   -------------------------------------------------------------------------
+
+   procedure Set_Multicast_Interface
+     (Socket : Socket_Type;
+      Idx    : Natural)
+   is
+      Res : C.int;
+      IF_Index : constant C.unsigned := C.unsigned (Idx);
+   begin
+      Res := Thin.C_Setsockopt
+        (S       => Socket.Sock_FD,
+         Level   => Constants.IPPROTO_IPV6,
+         Optname => Constants.IPV6_MULTICAST_IF,
+         Optval  => IF_Index'Address,
+         Optlen  => 4);
+
+      if Res = C_Failure then
+         raise Socket_Error with "Unable set IPv6 Multicast IF option"
+           & " on interface'" & Idx'Img & "': " & Get_Errno_String;
+      end if;
+   end Set_Multicast_Interface;
+
+   -------------------------------------------------------------------------
+
    procedure Set_Socket_Option
      (Socket : Socket_Type;
       Option : Option_Name_Bool;
