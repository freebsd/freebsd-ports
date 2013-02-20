--- dvbdevice.c.orig
+++ dvbdevice.c
@@ -7,6 +7,7 @@
  * $Id: dvbdevice.c 2.71 2012/05/09 08:33:59 kls Exp $
  */
 
+#include <stdint.h>
 #include "dvbdevice.h"
 #include <ctype.h>
 #include <errno.h>
@@ -579,7 +580,7 @@ int cDvbTuner::GetSignalQuality(void) co
      while (1) {
            if (ioctl(fd_frontend, FE_READ_SNR, &Snr) != -1)
               break;
-           if (errno == EOPNOTSUPP) {
+           if (errno == EOPNOTSUPP || errno == ENXIO) {
               Snr = 0xFFFF;
               HasSnr = false;
               break;
@@ -592,7 +593,7 @@ int cDvbTuner::GetSignalQuality(void) co
      while (1) {
            if (ioctl(fd_frontend, FE_READ_BER, &Ber) != -1)
               break;
-           if (errno == EOPNOTSUPP) {
+           if (errno == EOPNOTSUPP || errno == ENXIO) {
               Ber = 0;
               HasBer = false;
               break;
@@ -605,7 +606,7 @@ int cDvbTuner::GetSignalQuality(void) co
      while (1) {
            if (ioctl(fd_frontend, FE_READ_UNCORRECTED_BLOCKS, &Unc) != -1)
               break;
-           if (errno == EOPNOTSUPP) {
+           if (errno == EOPNOTSUPP || errno == ENXIO) {
               Unc = 0;
               HasUnc = false;
               break;
@@ -732,7 +733,7 @@ bool cDvbTuner::SetFrontend(void)
         if (const cDiseqc *diseqc = Diseqcs.Get(device->CardIndex() + 1, channel.Source(), frequency, dtp.Polarization(), &scr)) {
            frequency -= diseqc->Lof();
            if (diseqc != lastDiseqc || diseqc->IsScr()) {
-              if (GetBondedMaster() == this) {
+              if (!bondedTuner || bondedMaster) {
                  ExecuteDiseqc(diseqc, &frequency);
                  if (frequency == 0)
                     return false;
@@ -758,7 +759,7 @@ bool cDvbTuner::SetFrontend(void)
            tone = SEC_TONE_ON;
            }
         int volt = (dtp.Polarization() == 'V' || dtp.Polarization() == 'R') ? SEC_VOLTAGE_13 : SEC_VOLTAGE_18;
-        if (GetBondedMaster() != this) {
+        if (bondedTuner && !bondedMaster) {
            tone = SEC_TONE_OFF;
            volt = SEC_VOLTAGE_13;
            }
