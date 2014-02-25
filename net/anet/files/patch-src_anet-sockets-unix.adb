--- src/anet-sockets-unix.adb.orig	2013-12-04 09:55:07.000000000 +0000
+++ src/anet-sockets-unix.adb
@@ -68,6 +68,7 @@ package body Anet.Sockets.Unix is
    begin
       OS.Delete_File (Filename => String (Path));
 
+      Value.Sun_Len := C_Path'Length;
       Value.Pathname (1 .. C_Path'Length) := C_Path;
 
       Res := Thin.C_Bind (S       => Socket.Sock_FD,
@@ -101,15 +102,18 @@ package body Anet.Sockets.Unix is
      (Socket : in out Unix_Socket_Type;
       Path   :        Path_Type)
    is
+      use Interfaces.C;
       Res    : C.int;
       C_Path : constant C.char_array := C.To_C (String (Path));
       Value  : Thin.Sockaddr_Un_Type;
+      ValLen : C.unsigned;
    begin
       Value.Pathname (1 .. C_Path'Length) := C_Path;
+      ValLen := Value'Size / 8;
 
       Res := Thin.C_Connect (S       => Socket.Sock_FD,
                              Name    => Value'Address,
-                             Namelen => Value'Size / 8);
+                             Namelen => ValLen);
 
       if Res = C_Failure then
          raise Socket_Error with "Unable to connect unix socket to path "
