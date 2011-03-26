--- a/infosatepg.cpp
+++ b/infosatepg.cpp
@@ -403,7 +403,7 @@ cString cPluginInfosatepg::SVDRPCommand(
         cString head2;
         head2="\n" \
               "      |        | missed  |            |            | unlocated\n" \
-              " Day  | Date   | Packets | Received %% | Processed  | Events\n" \
+              " Day  | Date   | Packets | Received % | Processed  | Events\n" \
               "------+--------+---------+------------+------------+----------\n";
 
         cString mstr;
