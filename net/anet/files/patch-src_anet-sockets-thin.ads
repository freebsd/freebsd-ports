--- src/anet-sockets-thin.ads.orig	2013-12-04 09:55:07.000000000 +0000
+++ src/anet-sockets-thin.ads
@@ -22,11 +22,14 @@
 --
 
 with System;
+with Interfaces.C.Strings;
 
 package Anet.Sockets.Thin is
 
    type Sockaddr_Type is record
-      Sa_Family : Interfaces.C.unsigned_short;
+      Sa_Len    : Interfaces.C.unsigned_char := 16;
+      --  Record Size (BSD)
+      Sa_Family : Interfaces.C.unsigned_char;
       --  Address family
       Sa_Data   : Interfaces.C.char_array (1 .. 14)
         := (others => Interfaces.C.nul);
@@ -39,7 +42,9 @@ package Anet.Sockets.Thin is
    --  Internet protocol address families.
 
    type Sockaddr_In_Type (Family : Family_Inet_Type := Family_Inet) is record
-      Sin_Family : Interfaces.C.unsigned_short;
+      Sin_Len    : Interfaces.C.unsigned_char;
+      --  Record length (BSD)
+      Sin_Family : Interfaces.C.unsigned_char;
       --  Address family
       Sin_Port   : Interfaces.C.unsigned_short;
       --  Port in network byte order
@@ -64,10 +69,14 @@ package Anet.Sockets.Thin is
    --  Low-level Internet socket address type (struct sockaddr_in, struct
    --  sockaddr_in6).
 
+   type Sockaddr_In_Type_Access is access all Sockaddr_In_Type;
+
    type Sockaddr_Un_Type is record
-      Sin_Family : Interfaces.C.unsigned_short := Constants.AF_UNIX;
+      Sun_Len    : Interfaces.C.unsigned_char;
+      --  Record Length (BSD)
+      Sun_Family : Interfaces.C.unsigned_char := Constants.AF_UNIX;
       --  Address family
-      Pathname   : Interfaces.C.char_array (1 .. Constants.UNIX_PATH_MAX)
+      Pathname   : Interfaces.C.char_array (1 .. 104)
         := (others => Interfaces.C.nul);
       --  Pathname
    end record;
@@ -108,7 +117,7 @@ package Anet.Sockets.Thin is
 
    type IPv4_Mreq_Type is record
       Imr_Multiaddr : IPv4_Addr_Type;
-      Imr_Interface : Interfaces.C.unsigned;
+      Imr_Interface : IPv4_Addr_Type;
    end record;
    pragma Convention (C, IPv4_Mreq_Type);
    --  struct ip_mreq (netinet/in.h).
@@ -120,6 +129,21 @@ package Anet.Sockets.Thin is
    pragma Convention (C, IPv6_Mreq_Type);
    --  struct ipv6_mreq (netinet/in.h).
 
+   type Ifaddrs_Type;
+   type Ifaddrs_Type_Access is access all Ifaddrs_Type;
+
+   type Ifaddrs_Type is record
+      ifa_next         : Ifaddrs_Type_Access;
+      ifa_name         : Interfaces.C.Strings.chars_ptr;
+      ifa_flags        : Interfaces.C.unsigned;
+      ifa_addr         : Sockaddr_In_Type_Access;
+      ifa_netmask      : Sockaddr_In_Type_Access;
+      ifa_dstaddr      : Sockaddr_In_Type_Access;
+      ifa_data         : System.Address;
+   end record;
+   pragma Convention (C, Ifaddrs_Type);
+   --  struct ipv6_mreq (ifaddrs.h).
+
    type Netdev_Request_Name is
      (If_Addr,
       If_Flags,
@@ -146,16 +170,18 @@ package Anet.Sockets.Thin is
    pragma Convention (C, If_Req_Type);
    --  Interface request structure (struct ifreq).
 
-   Get_Requests : constant array (Netdev_Request_Name) of Interfaces.C.int
+   Get_Requests : constant array (Netdev_Request_Name) of
+      Interfaces.C.unsigned_long
      := (If_Addr   => Constants.SIOCGIFADDR,
          If_Flags  => Constants.SIOCGIFFLAGS,
          If_Hwaddr => Constants.SIOCGIFHWADDR,
          If_Index  => Constants.SIOCGIFINDEX);
    --  Currently supported netdevice ioctl get requests.
 
-   Set_Requests : constant array (Netdev_Request_Name) of Interfaces.C.int
+   Set_Requests : constant array (Netdev_Request_Name) of
+      Interfaces.C.unsigned_long
      := (If_Flags => Constants.SIOCSIFFLAGS,
-         others   => Interfaces.C.int (-1));
+         others   => Interfaces.C.unsigned_long (16#FFFFFFFF#));
    --  Currently supported netdevice ioctl set requests.
 
    -------------
@@ -179,7 +205,7 @@ package Anet.Sockets.Thin is
    function C_Connect
      (S       : Interfaces.C.int;
       Name    : System.Address;
-      Namelen : Interfaces.C.int)
+      Namelen : Interfaces.C.unsigned)
       return Interfaces.C.int;
    pragma Import (C, C_Connect, "connect");
 
@@ -204,19 +230,19 @@ package Anet.Sockets.Thin is
    function C_Send
      (S     : Interfaces.C.int;
       Buf   : System.Address;
-      Len   : Interfaces.C.int;
+      Len   : Interfaces.C.unsigned;
       Flags : Interfaces.C.int)
-      return Interfaces.C.int;
+      return Interfaces.C.long;
    pragma Import (C, C_Send, "send");
 
    function C_Sendto
      (S     : Interfaces.C.int;
       Buf   : System.Address;
-      Len   : Interfaces.C.int;
+      Len   : Interfaces.C.unsigned;
       Flags : Interfaces.C.int;
       To    : System.Address;
-      Tolen : Interfaces.C.int)
-      return Interfaces.C.int;
+      Tolen : Interfaces.C.unsigned)
+      return Interfaces.C.long;
    pragma Import (C, C_Sendto, "sendto");
 
    function C_Setsockopt
@@ -243,7 +269,7 @@ package Anet.Sockets.Thin is
 
    function C_Ioctl
      (S   : Interfaces.C.int;
-      Req : Interfaces.C.int;
+      Req : Interfaces.C.unsigned_long;
       Arg : access If_Req_Type)
       return Interfaces.C.int;
    pragma Import (C, C_Ioctl, "ioctl");
@@ -251,4 +277,13 @@ package Anet.Sockets.Thin is
    function C_Close (Fd : Interfaces.C.int) return Interfaces.C.int;
    pragma Import (C, C_Close, "close");
 
+   function C_GetIfAddrs
+     (ptr_ifaddrs : not null access Ifaddrs_Type_Access)
+      return Interfaces.C.int;
+   pragma Import (C, C_GetIfAddrs, "getifaddrs");
+
+   procedure C_FreeIfAddrs
+     (ptr_ifaddrs : not null Ifaddrs_Type_Access);
+   pragma Import (C, C_FreeIfAddrs, "freeifaddrs");
+
 end Anet.Sockets.Thin;
