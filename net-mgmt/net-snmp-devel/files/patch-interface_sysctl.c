Index: agent/mibgroup/if-mib/data_access/interface_sysctl.c
===================================================================
--- agent/mibgroup/if-mib/data_access/interface_sysctl.c	(revision 17324)
+++ agent/mibgroup/if-mib/data_access/interface_sysctl.c	(working copy)
@@ -451,22 +451,22 @@
             NETSNMP_INTERFACE_FLAGS_HAS_V6_REASMMAX;
 
         /* get counters */
-        entry->stats.ibytes.low = ifp->ifm_data.ifi_ibytes;
-        entry->stats.ibytes.high = 0;
-        entry->stats.iucast.low = ifp->ifm_data.ifi_ipackets;
-        entry->stats.iucast.high = 0;
-        entry->stats.imcast.low = ifp->ifm_data.ifi_imcasts;
-        entry->stats.imcast.high = 0;
+        entry->stats.ibytes.low = ifp->ifm_data.ifi_ibytes & 0xffffffff;
+        entry->stats.ibytes.high = ifp->ifm_data.ifi_ibytes >> 32;
+        entry->stats.iucast.low = ifp->ifm_data.ifi_ipackets & 0xffffffff;
+        entry->stats.iucast.high = ifp->ifm_data.ifi_ipackets >> 32;
+        entry->stats.imcast.low = ifp->ifm_data.ifi_imcasts & 0xffffffff;
+        entry->stats.imcast.high = ifp->ifm_data.ifi_imcasts >> 32;
         entry->stats.ierrors = ifp->ifm_data.ifi_ierrors;
         entry->stats.idiscards = ifp->ifm_data.ifi_iqdrops;
         entry->stats.iunknown_protos = ifp->ifm_data.ifi_noproto;
 
-        entry->stats.obytes.low = ifp->ifm_data.ifi_obytes;
-        entry->stats.obytes.high = 0;
-        entry->stats.oucast.low = ifp->ifm_data.ifi_opackets;
-        entry->stats.oucast.high = 0;
-        entry->stats.omcast.low = ifp->ifm_data.ifi_omcasts;
-        entry->stats.omcast.high = 0;
+        entry->stats.obytes.low = ifp->ifm_data.ifi_obytes & 0xffffffff;
+        entry->stats.obytes.high = ifp->ifm_data.ifi_obytes >> 32;
+        entry->stats.oucast.low = ifp->ifm_data.ifi_opackets & 0xffffffff;
+        entry->stats.oucast.high = ifp->ifm_data.ifi_opackets >> 32;
+        entry->stats.omcast.low = ifp->ifm_data.ifi_omcasts & 0xffffffff;
+        entry->stats.omcast.high = ifp->ifm_data.ifi_omcasts >> 32;
         entry->stats.oerrors = ifp->ifm_data.ifi_oerrors;
         entry->ns_flags |=  NETSNMP_INTERFACE_FLAGS_HAS_BYTES |
                             NETSNMP_INTERFACE_FLAGS_HAS_DROPS |

 	  	 
