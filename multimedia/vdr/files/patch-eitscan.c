--- eitscan.c.orig
+++ eitscan.c
@@ -148,7 +148,7 @@ void cEITScanner::Process(void)
                       if (Channel) {
                          if (!Channel->Ca() || Channel->Ca() == Device->DeviceNumber() + 1 || Channel->Ca() >= CA_ENCRYPTED_MIN) {
                             if (Device->ProvidesTransponder(Channel)) {
-                               if (!Device->Receiving()) {
+                               if (Device->Priority() < 0) {
                                   bool MaySwitchTransponder = Device->MaySwitchTransponder(Channel);
                                   if (MaySwitchTransponder || Device->ProvidesTransponderExclusively(Channel) && now - lastActivity > Setup.EPGScanTimeout * 3600) {
                                      if (!MaySwitchTransponder) {
