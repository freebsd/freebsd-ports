--- src/anet-sockets-inet.adb.orig	2016-06-29 10:26:01 UTC
+++ src/anet-sockets-inet.adb
@@ -52,7 +52,7 @@ package body Anet.Sockets.Inet is
       Res  : C.int;
       Sock : Thin.Inet.Sockaddr_In_Type
         (Family => Socket_Families.Family_Inet);
-      Len  : aliased C.int := Sock'Size / 8;
+      Len  : aliased C.int := Thin.Inet.Sockaddr_In_Size;
    begin
       New_Socket.Sock_FD := -1;
 
@@ -80,7 +80,7 @@ package body Anet.Sockets.Inet is
       Res  : C.int;
       Sock : Thin.Inet.Sockaddr_In_Type
         (Family => Socket_Families.Family_Inet6);
-      Len  : aliased C.int := Sock'Size / 8;
+      Len  : aliased C.int := Thin.Inet.Sockaddr_In6_Size;
    begin
       New_Socket.Sock_FD := -1;
 
@@ -129,7 +129,7 @@ package body Anet.Sockets.Inet is
         (Result  => Thin.C_Bind
            (S       => Socket.Sock_FD,
             Name    => Sockaddr'Address,
-            Namelen => Sockaddr'Size / 8),
+            Namelen => Thin.Inet.Sockaddr_In_Size),
          Message => "Unable to bind IPv4 socket to " & To_String
            (Address => Address) & "," & Port'Img);
    end Bind;
@@ -153,7 +153,7 @@ package body Anet.Sockets.Inet is
         (Result  => Thin.C_Bind
            (S       => Socket.Sock_FD,
             Name    => Sockaddr'Address,
-            Namelen => Sockaddr'Size / 8),
+            Namelen => Thin.Inet.Sockaddr_In6_Size),
          Message => "Unable to bind IPv6 socket to " & To_String
            (Address => Address) & "," & Port'Img);
    end Bind;
@@ -173,7 +173,7 @@ package body Anet.Sockets.Inet is
         (Result  => Thin.C_Connect
            (S       => Socket.Sock_FD,
             Name    => Dst'Address,
-            Namelen => Dst'Size / 8),
+            Namelen => Thin.Inet.Sockaddr_In_Size),
          Message => "Unable to connect socket to address " & To_String
            (Address => Address) & " (" & Port'Img & " )");
    end Connect;
@@ -193,7 +193,7 @@ package body Anet.Sockets.Inet is
         (Result  => Thin.C_Connect
            (S       => Socket.Sock_FD,
             Name    => Dst'Address,
-            Namelen => Dst'Size / 8),
+            Namelen => Thin.Inet.Sockaddr_In6_Size),
          Message => "Unable to connect socket to address " & To_String
            (Address => Address) & " (" & Port'Img & " )");
    end Connect;
@@ -432,7 +432,7 @@ package body Anet.Sockets.Inet is
          Len   => Item'Length,
          Flags => 0,
          To    => Dst'Address,
-         Tolen => Dst'Size / 8);
+         Tolen => Thin.Inet.Sockaddr_In_Size);
 
       Errno.Check_Or_Raise
         (Result  => C.int (Res),
@@ -464,7 +464,7 @@ package body Anet.Sockets.Inet is
          Len   => Item'Length,
          Flags => 0,
          To    => Dst'Address,
-         Tolen => Dst'Size / 8);
+         Tolen => Thin.Inet.Sockaddr_In6_Size);
 
       Errno.Check_Or_Raise
         (Result  => C.int (Res),
