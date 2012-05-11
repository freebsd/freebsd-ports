--- dvbdevice.c.orig
+++ dvbdevice.c
@@ -7,6 +7,7 @@
  * $Id: dvbdevice.c 2.38 2010/05/01 09:47:13 kls Exp $
  */
 
+#include <stdint.h>
 #include "dvbdevice.h"
 #include <ctype.h>
 #include <errno.h>
@@ -592,7 +598,7 @@ int cDvbTuner::GetSignalQuality(void) co
      while (1) {
            if (ioctl(fd_frontend, FE_READ_SNR, &Snr) != -1)
               break;
-           if (errno == EOPNOTSUPP) {
+           if (errno == EOPNOTSUPP || errno == ENXIO) {
               Snr = 0xFFFF;
               HasSnr = false;
               break;
@@ -605,7 +611,7 @@ int cDvbTuner::GetSignalQuality(void) co
      while (1) {
            if (ioctl(fd_frontend, FE_READ_BER, &Ber) != -1)
               break;
-           if (errno == EOPNOTSUPP) {
+           if (errno == EOPNOTSUPP || errno == ENXIO) {
               Ber = 0;
               HasBer = false;
               break;
@@ -618,7 +624,7 @@ int cDvbTuner::GetSignalQuality(void) co
      while (1) {
            if (ioctl(fd_frontend, FE_READ_UNCORRECTED_BLOCKS, &Unc) != -1)
               break;
-           if (errno == EOPNOTSUPP) {
+           if (errno == EOPNOTSUPP || errno == ENXIO) {
               Unc = 0;
               HasUnc = false;
               break;
