--- agent/mibgroup/sctp-mib/sctpScalars_freebsd.c.orig	1970-01-01 09:00:00.000000000 +0900
+++ agent/mibgroup/sctp-mib/sctpScalars_freebsd.c	2009-01-23 23:49:22.000000000 +0900
@@ -0,0 +1,103 @@
+#include <net-snmp/net-snmp-config.h>
+#include <net-snmp/net-snmp-includes.h>
+#include <net-snmp/agent/net-snmp-agent-includes.h>
+
+#include "sctpScalars_common.h"
+
+#include <stdio.h>
+#include <errno.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <stdint.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <netinet/sctp.h>
+#include <netinet/sctp_constants.h>
+
+#define PROC_PREFIX          "/proc"
+#define PROC_RTO_MIN         PROC_PREFIX "/sys/net/sctp/rto_min"
+#define PROC_RTO_MAX         PROC_PREFIX "/sys/net/sctp/rto_max"
+#define PROC_RTO_INITIAL     PROC_PREFIX "/sys/net/sctp/rto_initial"
+#define PROC_VAL_COOKIE_LIFE PROC_PREFIX "/sys/net/sctp/valid_cookie_life"
+#define PROC_MAX_INIT_RETR   PROC_PREFIX "/sys/net/sctp/max_init_retransmits"
+#define PROC_STATS           PROC_PREFIX "/net/sctp/snmp"
+
+void
+netsnmp_access_sctp_stats_arch_init()
+{
+}
+
+int
+netsnmp_access_sctp_stats_arch_load(netsnmp_sctp_stats * sctp_stats)
+{
+  struct sctpstat stat;
+  size_t len = sizeof(struct sctpstat);
+
+  if (sysctlbyname("net.inet.sctp.stats", &stat, &len, NULL, 0) < 0) {
+	return(-1);
+  }
+  memset(sctp_stats, 0, sizeof(netsnmp_sctp_stats));
+  sctp_stats->curr_estab = stat.sctps_currestab;
+  sctp_stats->active_estabs = stat.sctps_activeestab;
+  sctp_stats->passive_estabs = stat.sctps_passiveestab;
+  sctp_stats->aborteds = stat.sctps_aborted;
+  sctp_stats->shutdowns = stat.sctps_shutdown;
+  sctp_stats->out_of_blues = stat.sctps_outoftheblue;
+  sctp_stats->checksum_errors = stat.sctps_checksumerrors;
+  sctp_stats->out_ctrl_chunks.low = stat.sctps_outcontrolchunks;
+  sctp_stats->out_order_chunks.low = stat.sctps_outorderchunks;
+  sctp_stats->out_unorder_chunks.low = stat.sctps_outunorderchunks;
+  sctp_stats->in_ctrl_chunks.low = stat.sctps_incontrolchunks;
+  sctp_stats->in_order_chunks.low = stat.sctps_inorderchunks;
+  sctp_stats->in_unorder_chunks.low = stat.sctps_inunorderchunks;
+  sctp_stats->frag_usr_msgs.low = stat.sctps_fragusrmsgs;
+  sctp_stats->reasm_usr_msgs.low = stat.sctps_reasmusrmsgs;
+  sctp_stats->out_sctp_packs.low = stat.sctps_outpackets;
+  sctp_stats->in_sctp_packs.low = stat.sctps_inpackets;
+  sctp_stats->discontinuity_time = 0;
+  return 0;
+}
+
+void
+netsnmp_access_sctp_params_arch_init()
+{
+}
+
+int
+netsnmp_access_sctp_params_arch_load(netsnmp_sctp_params * sctp_params)
+{
+    int             ret;
+	size_t len = sizeof(uint32_t);
+	unsigned int cnt = 0;
+
+    sctp_params->rto_algorithm = NETSNMP_SCTP_ALGORITHM_VANJ;
+    sctp_params->max_assocs =  SCTP_MAX_NUM_OF_ASOC; 
+	if (sysctlbyname("net.inet.sctp.rto_max",
+					 &sctp_params->rto_max,
+					 &len, NULL, 0) < 0) {
+	  return(-1);
+	}
+	if (sysctlbyname("net.inet.sctp.rto_min",
+					 &sctp_params->rto_min,
+					 &len, NULL, 0) < 0) {
+	  return(-1);
+	}
+	if (sysctlbyname("net.inet.sctp.rto_initial",
+					 &sctp_params->rto_initial,
+					 &len, NULL, 0) < 0) {
+	  return(-1);
+	}
+	if (sysctlbyname("net.inet.sctp.valid_cookie_life",
+					 &sctp_params->val_cookie_life,
+					 &len, NULL, 0) < 0) {
+	  return(-1);
+	}
+	if (sysctlbyname("net.inet.sctp.init_rtx_max",
+					 &sctp_params->max_init_retr,
+					 &len, NULL, 0) < 0) {
+	  return(-1);
+	}
+    return 0;
+}
