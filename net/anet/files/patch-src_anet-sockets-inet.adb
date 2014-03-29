--- src/anet-sockets-inet.adb.orig	2013-12-04 09:55:07.000000000 +0000
+++ src/anet-sockets-inet.adb
@@ -25,6 +25,7 @@ with Anet.Constants;
 with Anet.Sockets.Thin;
 with Anet.Byte_Swapping;
 with Anet.Net_Ifaces;
+with Interfaces.C.Strings;
 
 package body Anet.Sockets.Inet is
 
@@ -61,7 +62,7 @@ package body Anet.Sockets.Inet is
    is
       Res  : C.int;
       Sock : Thin.Sockaddr_In_Type (Family => Family_Inet);
-      Len  : aliased C.int := Sock'Size / 8;
+      Len  : aliased C.int := 16;
    begin
       New_Socket.Sock_FD := -1;
 
@@ -88,7 +89,7 @@ package body Anet.Sockets.Inet is
    is
       Res  : C.int;
       Sock : Thin.Sockaddr_In_Type (Family => Family_Inet6);
-      Len  : aliased C.int := Sock'Size / 8;
+      Len  : aliased C.int := 28;
    begin
       New_Socket.Sock_FD := -1;
 
@@ -126,17 +127,16 @@ package body Anet.Sockets.Inet is
 
       Res := Thin.C_Bind (S       => Socket.Sock_FD,
                           Name    => Sockaddr'Address,
-                          Namelen => Sockaddr'Size / 8);
+                          Namelen => 16);
       if Res = C_Failure then
          raise Socket_Error with "Unable to bind IPv4 socket to "
            & To_String (Address => Address) & "," & Port'Img & " - "
            & Get_Errno_String;
       end if;
 
+      --  No BSD supports SO_BINDTODEVICE unfortunately....
       if Iface'Length /= 0 then
-         Socket.Set_Socket_Option
-           (Option => Bind_To_Device,
-            Value  => String (Iface));
+         Socket.Set_Multicast_Interface (IPAddr => Address);
       end if;
    end Bind;
 
@@ -148,29 +148,35 @@ package body Anet.Sockets.Inet is
       Port    :        Port_Type;
       Iface   :        Types.Iface_Name_Type := "")
    is
-      Res      : C.int;
-      Sockaddr : constant Thin.Sockaddr_In_Type
-        := Create_Inet6 (Address => Address,
-                         Port    => Port);
+      Res       : C.int;
+      Sockaddr  : Thin.Sockaddr_In_Type;
+      Iface_Idx : Natural;
+      IfAddr6   : IPv6_Addr_Type;
    begin
       Socket.Set_Socket_Option
         (Option => Reuse_Address,
          Value  => True);
 
+      if Iface'Length > 0 then
+         Get_IPv6_Interface_Data
+           (Iface_Name   => Iface,
+            Iface_Index  => Iface_Idx,
+            IPv6_Address => IfAddr6);
+         Socket.Set_Multicast_Interface (Idx => Iface_Idx);
+         Sockaddr := Create_Inet6 (Address => IfAddr6, Port => 0);
+      else
+         Sockaddr := Create_Inet6 (Address => Address, Port => Port);
+      end if;
+
       Res := Thin.C_Bind (S       => Socket.Sock_FD,
                           Name    => Sockaddr'Address,
-                          Namelen => Sockaddr'Size / 8);
+                          Namelen => 28);
       if Res = C_Failure then
          raise Socket_Error with "Unable to bind IPv6 socket to "
            & To_String (Address => Address) & "," & Port'Img & " - "
            & Get_Errno_String;
       end if;
 
-      if Iface'Length /= 0 then
-         Socket.Set_Socket_Option
-           (Option => Bind_To_Device,
-            Value  => String (Iface));
-      end if;
    end Bind;
 
    -------------------------------------------------------------------------
@@ -187,7 +193,7 @@ package body Anet.Sockets.Inet is
    begin
       Res := Thin.C_Connect (S       => Socket.Sock_FD,
                              Name    => Dst'Address,
-                             Namelen => Dst'Size / 8);
+                             Namelen => 16);
 
       if Res = C_Failure then
          raise Socket_Error with "Unable to connect socket to address "
@@ -210,7 +216,7 @@ package body Anet.Sockets.Inet is
    begin
       Res := Thin.C_Connect (S       => Socket.Sock_FD,
                              Name    => Dst'Address,
-                             Namelen => Dst'Size / 8);
+                             Namelen => 28);
 
       if Res = C_Failure then
          raise Socket_Error with "Unable to connect socket to address "
@@ -228,6 +234,7 @@ package body Anet.Sockets.Inet is
    is
    begin
       return (Family     => Family_Inet,
+              Sin_Len    => 16,
               Sin_Family => Constants.Sys.AF_INET,
               Sin_Port   => C.unsigned_short
                 (Byte_Swapping.Host_To_Network (Input => Port)),
@@ -244,6 +251,7 @@ package body Anet.Sockets.Inet is
    is
    begin
       return (Family     => Family_Inet6,
+              Sin_Len    => 28,
               Sin_Family => Constants.Sys.AF_INET6,
               Sin_Port   => C.unsigned_short
                 (Byte_Swapping.Host_To_Network (Input => Port)),
@@ -253,6 +261,52 @@ package body Anet.Sockets.Inet is
 
    -------------------------------------------------------------------------
 
+   procedure Get_IPv6_Interface_Data
+     (Iface_Name   : Types.Iface_Name_Type;
+      Iface_Index  : out Natural;
+      IPv6_Address : out IPv6_Addr_Type)
+   is
+      use Interfaces.C;
+      use Anet.Sockets.Thin;
+      Res : C.int;
+
+      ifaddrs : aliased Thin.Ifaddrs_Type_Access;
+      frame   : Thin.Ifaddrs_Type_Access;
+      found   : Boolean := False;
+   begin
+      Res := Thin.C_GetIfAddrs (ptr_ifaddrs => ifaddrs'Access);
+      if Res = C_Failure then
+         raise Socket_Error with "Unable to get interface addresses: "
+           & Get_Errno_String;
+      end if;
+      frame := ifaddrs;
+      Iface_Index := 1;
+      loop
+         declare
+            testname : constant String :=
+               Interfaces.C.Strings.Value (frame.all.ifa_name);
+         begin
+            if testname = String (Iface_Name) and then
+              frame.all.ifa_addr.all.Sin_Family = Constants.Sys.AF_INET6
+            then
+               found := True;
+               IPv6_Address := frame.all.ifa_addr.all.Sin6_Addr;
+            end if;
+         end;
+         exit when found;
+         exit when frame.all.ifa_next = null;
+         frame := frame.all.ifa_next;
+         Iface_Index := Iface_Index + 1;
+      end loop;
+      Thin.C_FreeIfAddrs (ptr_ifaddrs => ifaddrs);
+      if not found then
+         raise Socket_Error with "Cannot find interface "
+            & String (Iface_Name);
+      end if;
+   end Get_IPv6_Interface_Data;
+
+   -------------------------------------------------------------------------
+
    procedure Init (Socket : in out UDPv4_Socket_Type)
    is
    begin
@@ -301,15 +355,15 @@ package body Anet.Sockets.Inet is
       use type C.unsigned_short;
 
       Mreq      : Thin.IPv4_Mreq_Type;
-      Iface_Idx : Natural := 0;
+      ImrIface  : IPv4_Addr_Type := (0, 0, 0, 0);   -- INADDR_ANY
       Res       : C.int;
    begin
       if Iface'Length > 0 then
-         Iface_Idx := Net_Ifaces.Get_Iface_Index (Name => Iface);
+         ImrIface := Net_Ifaces.Get_Iface_IP (Name => Iface);
       end if;
 
       Mreq.Imr_Multiaddr := Group;
-      Mreq.Imr_Interface := C.unsigned (Iface_Idx);
+      Mreq.Imr_Interface := ImrIface;
 
       Res := Thin.C_Setsockopt
         (S       => Socket.Sock_FD,
@@ -335,10 +389,14 @@ package body Anet.Sockets.Inet is
 
       Mreq6     : Thin.IPv6_Mreq_Type;
       Iface_Idx : Natural := 0;
+      dummy     : IPv6_Addr_Type;
       Res       : C.int;
    begin
       if Iface'Length > 0 then
-         Iface_Idx := Net_Ifaces.Get_Iface_Index (Name => Iface);
+         Get_IPv6_Interface_Data
+           (Iface_Name  => Iface,
+           Iface_Index  => Iface_Idx,
+           IPv6_Address => dummy);
       end if;
 
       Mreq6.IPv6mr_Multiaddr := Group;
@@ -349,7 +407,7 @@ package body Anet.Sockets.Inet is
          Level   => Constants.IPPROTO_IPV6,
          Optname => Constants.IPV6_ADD_MEMBERSHIP,
          Optval  => Mreq6'Address,
-         Optlen  => Mreq6'Size / 8);
+         Optlen  => 20);
 
       if Res = C_Failure then
          raise Socket_Error with "Unable to join multicast group "
@@ -440,7 +498,8 @@ package body Anet.Sockets.Inet is
       Dst_Addr : IPv4_Addr_Type;
       Dst_Port : Port_Type)
    is
-      Res : C.int;
+      use Interfaces.C;
+      Res : C.long;
       Dst : constant Thin.Sockaddr_In_Type := Create_Inet4
         (Address => Dst_Addr,
          Port    => Dst_Port);
@@ -450,7 +509,7 @@ package body Anet.Sockets.Inet is
                             Len   => Item'Length,
                             Flags => 0,
                             To    => Dst'Address,
-                            Tolen => Dst'Size / 8);
+                            Tolen => 16);
 
       if Res = C_Failure then
          raise Socket_Error with "Error sending data to "
@@ -473,7 +532,8 @@ package body Anet.Sockets.Inet is
       Dst_Addr : IPv6_Addr_Type;
       Dst_Port : Port_Type)
    is
-      Res : C.int;
+      use Interfaces.C;
+      Res : C.long;
       Dst : constant Thin.Sockaddr_In_Type := Create_Inet6
         (Address => Dst_Addr,
          Port    => Dst_Port);
@@ -483,7 +543,7 @@ package body Anet.Sockets.Inet is
                             Len   => Item'Length,
                             Flags => 0,
                             To    => Dst'Address,
-                            Tolen => Dst'Size / 8);
+                            Tolen => 28);
 
       if Res = C_Failure then
          raise Socket_Error with "Error sending data to "
