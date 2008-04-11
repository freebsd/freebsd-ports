--- snmp++/classes/include/snmp++/notifyqueue.h.orig	2008-04-08 21:30:13.000000000 +0200
+++ snmp++/classes/include/snmp++/notifyqueue.h	2008-04-08 21:30:29.000000000 +0200
@@ -94,8 +94,8 @@
 	       const TargetCollection &notify_targets, 
 	       const AddressCollection &notify_addresses);
   ~CNotifyEvent();
-  Snmp * CNotifyEvent::GetId();
-  int CNotifyEvent::notify_filter(const Oid &trapid, 
+  Snmp * GetId();
+  int notify_filter(const Oid &trapid, 
 				  const SnmpTarget &target) const;
   int Callback(SnmpTarget & target, Pdu & pdu, int status);
 
