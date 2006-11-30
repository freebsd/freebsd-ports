--- FlowTree.cpp.old	Wed Nov 29 16:01:51 2006
+++ FlowTree.cpp	Wed Nov 29 16:02:15 2006
@@ -97,7 +97,7 @@
 						   "FLOOD: %d.%d.%d.%d - %.2f %s packets/s from %d.%d.%d.%d [DSCP %02X]",
 						   ((unsigned char*)&pTemp->m_flow.records.daddr)[0],
 						   ((unsigned char*)&pTemp->m_flow.records.daddr)[1],
-						   (unsigned char*)&pTemp->m_flow.records.daddr)[2],
+						   ((unsigned char*)&pTemp->m_flow.records.daddr)[2],
 						   ((unsigned char*)&pTemp->m_flow.records.daddr)[3],
 						   pps,
 						   proto->p_name,
