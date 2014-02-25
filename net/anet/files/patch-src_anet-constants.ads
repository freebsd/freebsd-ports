--- src/anet-constants.ads.orig	2013-12-04 09:55:07.000000000 +0000
+++ src/anet-constants.ads
@@ -70,17 +70,19 @@ package Anet.Constants is
 
    SO_BINDTODEVICE     : constant := 25;       --  Bind to interface device
    SO_ATTACH_FILTER    : constant := 26;       --  Socket filtering
-   IPV6_ADD_MEMBERSHIP : constant := 20;       --  Join multicast group (IPv6)
+   IPV6_ADD_MEMBERSHIP : constant := 12;       --  Join multicast group (IPv6)
+   IPV6_MULTICAST_IF   : constant := 9;        --  Multicast sending (IPv6)
+   IP_MULTICAST_IF     : constant := 9;        --  Multicast sending on IF
 
    -----------------------------------
    -- Socket configuration controls --
    -----------------------------------
 
-   SIOCGIFADDR         : constant := 16#8915#; --  Get address
-   SIOCGIFFLAGS        : constant := 16#8913#; --  Get flags
-   SIOCSIFFLAGS        : constant := 16#8914#; --  Set flags
-   SIOCGIFHWADDR       : constant := 16#8927#; --  Get hardware address
-   SIOCGIFINDEX        : constant := 16#8933#; --  Name -> if_index mapping
+   SIOCGIFADDR         : constant := 16#C0206921#; --  Get address
+   SIOCGIFFLAGS        : constant := 16#C0206911#; --  Get flags
+   SIOCSIFFLAGS        : constant := 16#80206910#; --  Set flags
+   SIOCGIFHWADDR       : constant := 16#FFFFFFFF#; --  Get hardware address
+   SIOCGIFINDEX        : constant := 16#C0206920#; --  Name -> if_index mapping
 
    ---------------------
    -- Interface flags --
