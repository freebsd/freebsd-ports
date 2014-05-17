--- src/core/aws-net.adb.orig	2014-05-15 19:48:07.000000000 +0000
+++ src/core/aws-net.adb
@@ -552,7 +552,7 @@ package body AWS.Net is
 
          --  to be shure that it is S1 and S2 connected together
 
-         exit when Peer_Addr (STC (S2)) = Local_Host
+         exit when Peer_Addr (STC (S2)) = Get_Addr (STC (S1))
            and then Peer_Port (STC (S2)) = Get_Port (STC (S1))
            and then Peer_Port (STC (S1)) = Get_Port (STC (S2));
 
