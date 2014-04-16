--- src/core/aws-net.adb.orig	2014-04-03 07:44:04.691630539 +0200
+++ src/core/aws-net.adb	2014-04-03 15:48:00.868957657 +0200
@@ -439,7 +439,7 @@
 
          --  to be shure that it is S1 and S2 connected together
 
-         exit when Peer_Addr (STC (S2)) = Local_Host
+         exit when Peer_Addr (STC (S2)) = Get_Addr (STC (S1))
            and then Peer_Port (STC (S2)) = Get_Port (STC (S1))
            and then Peer_Port (STC (S1)) = Get_Port (STC (S2));
