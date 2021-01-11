--- tg_owt/src/media/sctp/sctp_transport.cc.orig	2020-10-07 14:11:02 UTC
+++ tg_owt/src/media/sctp/sctp_transport.cc
@@ -43,7 +43,7 @@
 #include "rtc_base/thread_annotations.h"
 #include "rtc_base/thread_checker.h"
 #include "rtc_base/trace_event.h"
-#include "usrsctplib/usrsctp.h"
+#include "usrsctp.h"
 
 namespace {
 
@@ -470,7 +470,7 @@
     return transport;
   }
 
-  static int SendThresholdCallback(struct socket* sock, uint32_t sb_free) {
+  static int SendThresholdCallback(struct socket* sock, uint32_t sb_free, void *ulp_info) {
     // Fired on our I/O thread. SctpTransport::OnPacketReceived() gets
     // a packet containing acknowledgments, which goes into usrsctp_conninput,
     // and then back here.
