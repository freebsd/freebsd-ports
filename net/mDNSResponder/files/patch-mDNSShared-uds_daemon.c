--- mDNSShared/uds_daemon.c.orig	2026-04-17 00:41:56 UTC
+++ mDNSShared/uds_daemon.c
@@ -3626,7 +3626,11 @@ mDNSlocal void resolve_result_callback(mDNS *const m, 
     request_state *const req = question->QuestionContext;
     const mDNSu32 name_hash = mDNS_DomainNameFNV1aHash(&question->qname);
     const mDNSBool isMDNSQuestion = mDNSOpaque16IsZero(question->TargetQID);
+#if MDNS_OS(macOS)
     const mDNSBool is_split_awdl_query = (req->resolve_awdl && question->InterfaceID == AWDLInterfaceID);
+#else
+    const mDNSBool is_split_awdl_query = mDNSfalse;
+#endif
     UDS_LOG_ANSWER_EVENT(isMDNSQuestion ? MDNS_LOG_CATEGORY_MDNS : MDNS_LOG_CATEGORY_DEFAULT, MDNS_LOG_DEFAULT,
         req, question, answer, mDNSfalse, "DNSServiceResolve result", AddRecord);
 
