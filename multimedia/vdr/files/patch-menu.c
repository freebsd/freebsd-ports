--- menu.c.orig
+++ menu.c
@@ -2938,6 +2938,8 @@ void cMenuSetupLNB::Setup(void)
      for (int i = 0; i < cDevice::NumDevices(); i++) {
          if (cDevice::GetDevice(i)->ProvidesSource(cSource::stSat))
             Add(new cMenuEditIntItem(cString::sprintf(tr("Setup.LNB$Device %d connected to sat cable"), i + 1), &satCableNumbers.Array()[i], 0, NumSatDevices, tr("Setup.LNB$own")));
+         else
+            satCableNumbers.Array()[i] = 0;
          }
      }
 
