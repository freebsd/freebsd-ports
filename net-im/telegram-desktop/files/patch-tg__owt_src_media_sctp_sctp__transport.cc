--- tg_owt/src/media/sctp/sctp_transport.cc.orig	2020-08-30 09:41:57 UTC
+++ tg_owt/src/media/sctp/sctp_transport.cc
@@ -43,7 +43,7 @@ enum PreservedErrno {
 #include "rtc_base/thread_annotations.h"
 #include "rtc_base/thread_checker.h"
 #include "rtc_base/trace_event.h"
-#include "usrsctplib/usrsctp.h"
+#include "usrsctp.h"
 
 namespace {
 
