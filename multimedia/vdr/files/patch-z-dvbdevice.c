--- dvbdevice.c.orig
+++ dvbdevice.c
@@ -823,7 +823,11 @@ bool cDvbTuner::SetFrontend(void)
      SETCMD(DTV_HIERARCHY, dtp.Hierarchy());
      if (frontendType == SYS_DVBT2) {
         // DVB-T2
+#ifndef DTV_DVBT2_PLP_ID
+        SETCMD(DTV_DVBT2_PLP_ID_LEGACY, dtp.PlpId());
+#else
         SETCMD(DTV_DVBT2_PLP_ID, dtp.PlpId());
+#endif
         }
 
      tuneTimeout = DVBT_TUNE_TIMEOUT;
