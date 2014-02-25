--- src/anet-sockets-inet.ads.orig	2013-12-04 09:55:07.000000000 +0000
+++ src/anet-sockets-inet.ads
@@ -174,6 +174,12 @@ package Anet.Sockets.Inet is
       Port    :        Port_Type);
    --  Connect TCPv6 socket to specified IPv6 address and port.
 
+   procedure Get_IPv6_Interface_Data
+     (Iface_Name   : Types.Iface_Name_Type;
+      Iface_Index  : out Natural;
+      IPv6_Address : out IPv6_Addr_Type);
+   --  Get IPv6 address and index from an interface name
+
 private
 
    type Inet_Socket_Type is abstract new Socket_Type with null record;
