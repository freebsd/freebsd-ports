--- src/anet-sockets.ads.orig	2013-12-04 09:55:07.000000000 +0000
+++ src/anet-sockets.ads
@@ -120,6 +120,16 @@ package Anet.Sockets is
       Value  : String);
    --  Set socket option of given socket to specified string value.
 
+   procedure Set_Multicast_Interface
+     (Socket : Socket_Type;
+      IPAddr : IPv4_Addr_Type);
+   --  Set multicast interface socket option for IPv4
+
+   procedure Set_Multicast_Interface
+     (Socket : Socket_Type;
+      Idx    : Natural);
+   --  Set multicast interface socket option for IPv6
+
    Socket_Error : exception;
 
 private
@@ -171,7 +181,7 @@ private
 
    procedure Check_Complete_Send
      (Item      : Ada.Streams.Stream_Element_Array;
-      Result    : Interfaces.C.int;
+      Result    : Interfaces.C.long;
       Error_Msg : String);
    --  Verify that a Send operation was able to transmit all bytes of given
    --  buffer by calculating the actual number of bytes sent from the buffer
