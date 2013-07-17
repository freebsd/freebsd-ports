--- src/capmt.c.orig	2013-06-02 11:30:50.000000000 +0200
+++ src/capmt.c	2013-06-02 11:35:53.395592208 +0200
@@ -33,10 +33,10 @@
 #include <sys/un.h>
 #include <netdb.h>
 #include <netinet/in.h>
-#include <linux/ioctl.h>
 #include <linux/dvb/ca.h>
 #include <fcntl.h>
 
+#include "config.h"
 #include "tvheadend.h"
 #include "dvb/dvb.h"
 #include "tcp.h"
@@ -53,6 +53,12 @@
 #include "ffdecsa/FFdecsa.h"
 #endif
 
+#if defined(PLATFORM_LINUX)
+#include <linux/ioctl.h>
+#elif defined(PLATFORM_FREEBSD)
+#include <sys/ioccom.h>
+#endif
+
 // ca_pmt_list_management values:
 #define CAPMT_LIST_MORE   0x00    // append a 'MORE' CAPMT object the list and start receiving the next object
 #define CAPMT_LIST_FIRST  0x01    // clear the list when a 'FIRST' CAPMT object is received, and start receiving the next object
@@ -75,8 +81,10 @@
 #define CW_DUMP(buf, len, format, ...) \
   printf(format, __VA_ARGS__); int j; for (j = 0; j < len; ++j) printf("%02X ", buf[j]); printf("\n");
 
+#ifdef PLATFORM_LINUX
 #ifdef __GNUC__
 #include <features.h>
+#endif
 #if __GNUC_PREREQ(4, 3)
 #pragma GCC diagnostic ignored "-Warray-bounds"
 #endif
@@ -405,7 +413,7 @@
   capmt_service_t *ct;
   service_t *t;
   int ret, bufsize;
-  int *request;
+  long *request;
   ca_descr_t *ca;
   ca_pid_t *cpd;
   int process_key, process_next, cai;
@@ -476,10 +484,10 @@
     // parsing data
     if (capmt->capmt_oscam) {
       cai = i;
-      request = (int *) &buffer;
+      request = (long *) &buffer;
       if (*request == CA_SET_PID) {
         cpd = (ca_pid_t *)&buffer[sizeof(int)];
-        tvhlog(LOG_DEBUG, "capmt", "CA_SET_PID cai %d req %d (%d %04x)", cai, *request, cpd->index, cpd->pid);
+        tvhlog(LOG_DEBUG, "capmt", "CA_SET_PID cai %d req %ld (%d %04x)", cai, *request, cpd->index, cpd->pid);
 
         if (cpd->index >=0 && cpd->index < MAX_INDEX) {
           ca_info[cai][cpd->index][0] = (cpd->pid >> 0) & 0xff;
@@ -490,7 +498,7 @@
           tvhlog(LOG_ERR, "capmt", "Invalid index %d in CA_SET_PID (%d) for ca id %d", cpd->index, MAX_INDEX, cai);
       } else if (*request == CA_SET_DESCR) {
         ca = (ca_descr_t *)&buffer[sizeof(int)];
-        tvhlog(LOG_DEBUG, "capmt", "CA_SET_DESCR cai %d req %d par %d idx %d %02x%02x%02x%02x%02x%02x%02x%02x", cai, *request, ca->parity, ca->index, ca->cw[0], ca->cw[1], ca->cw[2], ca->cw[3], ca->cw[4], ca->cw[5], ca->cw[6], ca->cw[7]);
+        tvhlog(LOG_DEBUG, "capmt", "CA_SET_DESCR cai %d req %ld par %d idx %d %02x%02x%02x%02x%02x%02x%02x%02x", cai, *request, ca->parity, ca->index, ca->cw[0], ca->cw[1], ca->cw[2], ca->cw[3], ca->cw[4], ca->cw[5], ca->cw[6], ca->cw[7]);
         if (ca->index == -1)   // skipping removal request
           continue;
 
