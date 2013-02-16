--- infosatepg.cpp.orig
+++ infosatepg.cpp
@@ -190,10 +190,14 @@ void cPluginInfosatepg::MainThreadHook(v
         if (dev)
         {
             if (!dev->ProvidesTransponder(chan)) continue; // device cannot provide transponder -> skip
+#if VDRVERSNUM >= 10726
+            if (statusMonitor->m_LiveView) continue; // EITScanner is updating EPG -> skip
+#else
             if (EITScanner.UsesDevice(dev)) continue; // EITScanner is updating EPG -> skip
+#endif
             if (dev->Receiving()) continue; // device is recording -> skip
             if (dev->IsPrimaryDevice()) continue; // device is primary -> skip
-            if (cDevice::ActualDevice()->CardIndex()==i) continue; // device is live viewing -> skip
+            if (cDevice::ActualDevice()->CardIndex()==dev->CardIndex()) continue; // device is live viewing -> skip
             if (dev->IsTunedToTransponder(chan))
             {
                 // we already have a device which is tuned (maybe switched manually?)
@@ -202,6 +206,8 @@ void cPluginInfosatepg::MainThreadHook(v
                 return;
             }
 
+            if (!dev->MaySwitchTransponder(chan)) continue; // bonded?
+
             // ok -> use this device
             dsyslog("infosatepg: found free device %i",dev->DeviceNumber()+1);
             dev->SwitchChannel(chan,false);
@@ -403,7 +409,7 @@ cString cPluginInfosatepg::SVDRPCommand(
         cString head2;
         head2="\n" \
               "      |        | missed  |            |            | unlocated\n" \
-              " Day  | Date   | Packets | Received %% | Processed  | Events\n" \
+              " Day  | Date   | Packets | Received % | Processed  | Events\n" \
               "------+--------+---------+------------+------------+----------\n";
 
         cString mstr;
