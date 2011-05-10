--- a/infosatepg.cpp
+++ b/infosatepg.cpp
@@ -193,7 +193,7 @@ void cPluginInfosatepg::MainThreadHook(v
             if (EITScanner.UsesDevice(dev)) continue; // EITScanner is updating EPG -> skip
             if (dev->Receiving()) continue; // device is recording -> skip
             if (dev->IsPrimaryDevice()) continue; // device is primary -> skip
-            if (cDevice::ActualDevice()->CardIndex()==i) continue; // device is live viewing -> skip
+            if (cDevice::ActualDevice()->CardIndex()==dev->CardIndex()) continue; // device is live viewing -> skip
             if (dev->IsTunedToTransponder(chan))
             {
                 // we already have a device which is tuned (maybe switched manually?)
@@ -403,7 +403,7 @@ cString cPluginInfosatepg::SVDRPCommand(
         cString head2;
         head2="\n" \
               "      |        | missed  |            |            | unlocated\n" \
-              " Day  | Date   | Packets | Received %% | Processed  | Events\n" \
+              " Day  | Date   | Packets | Received % | Processed  | Events\n" \
               "------+--------+---------+------------+------------+----------\n";
 
         cString mstr;
