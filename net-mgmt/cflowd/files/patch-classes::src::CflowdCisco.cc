--- classes/src/CflowdCisco.cc.orig	Fri Aug 29 21:02:38 2003
+++ classes/src/CflowdCisco.cc	Fri Aug 29 21:12:30 2003
@@ -699,22 +699,22 @@
        engineIter != this->FlowEngines().end(); engineIter++) {
     for (uint8_t aggMethod = 0; aggMethod <= k_CiscoV8FlowExportMaxAggType;
          aggMethod++) {
-      if ((*engineIter).second.MissedFlows(aggMethod) >
+      if ((*engineIter).second.MissedFlows((char)aggMethod) >
           this->_missedFlowsThreshold) {
         struct in_addr  addrIn;
         addrIn.s_addr = this->IpAddress();
-        uint64_t totalFlows = ((*engineIter).second.MissedFlows(aggMethod) +
-                               (*engineIter).second.FlowsReceived(aggMethod));
+        uint64_t totalFlows = ((*engineIter).second.MissedFlows((char)aggMethod) +
+                               (*engineIter).second.FlowsReceived((char)aggMethod));
         syslog(LOG_INFO,
                "[I] missed %u of %u flows from %s"
                " engine %d agg_method %d (%g%% loss)",
-               (*engineIter).second.MissedFlows(aggMethod),
+               (*engineIter).second.MissedFlows((char)aggMethod),
                totalFlows,
                inet_ntoa(addrIn),
                (*engineIter).first,
                aggMethod,
-               ((*engineIter).second.MissedFlows(aggMethod) * 100.0) /
-               totalFlows);
+               ((*engineIter).second.MissedFlows((char)(aggMethod) * 100.0) /
+               totalFlows));
       }
       (*engineIter).second.MissedFlows(0,aggMethod);
       (*engineIter).second.FlowsReceived(0,aggMethod);
