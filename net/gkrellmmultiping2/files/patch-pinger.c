--- pinger.c.orig	Mon Sep  1 06:40:12 2003
+++ pinger.c	Mon Sep  8 00:23:55 2003
@@ -25,7 +25,9 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/signal.h>
+#include <sys/types.h>
 
+#include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/ip_icmp.h>
@@ -34,6 +36,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <string.h>
 #include <fcntl.h>
 #include <unistd.h>
@@ -237,54 +240,54 @@
 	g_string_assign(s, "Echo Reply");
 	/* XXX ID + Seq + Data */
 	break;
-    case ICMP_DEST_UNREACH:
+    case ICMP_UNREACH:
 	switch (icp->icmp_code) {
-	case ICMP_NET_UNREACH:
+	case ICMP_UNREACH_NET:
 	    g_string_assign(s, "Destination Net Unreachable");
 	    break;
-	case ICMP_HOST_UNREACH:
+	case ICMP_UNREACH_HOST:
 	    g_string_assign(s, "Destination Host Unreachable");
 	    break;
-	case ICMP_PROT_UNREACH:
+	case ICMP_UNREACH_PROTOCOL:
 	    g_string_assign(s, "Destination Protocol Unreachable");
 	    break;
-	case ICMP_PORT_UNREACH:
+	case ICMP_UNREACH_PORT:
 	    g_string_assign(s, "Destination Port Unreachable");
 	    break;
-	case ICMP_FRAG_NEEDED:
+	case ICMP_UNREACH_NEEDFRAG:
 	    g_string_assign(s, "Frag needed and DF set");
 	    break;
-	case ICMP_SR_FAILED:
+	case ICMP_UNREACH_SRCFAIL:
 	    g_string_assign(s, "Source Route Failed");
 	    break;
-	case ICMP_NET_UNKNOWN:
+	case ICMP_UNREACH_NET_UNKNOWN:
 	    g_string_assign(s, "Network Unknown");
 	    break;
-	case ICMP_HOST_UNKNOWN:
+	case ICMP_UNREACH_HOST_UNKNOWN:
 	    g_string_assign(s, "Host Unknown");
 	    break;
-	case ICMP_HOST_ISOLATED:
+	case ICMP_UNREACH_ISOLATED:
 	    g_string_assign(s, "Host Isolated");
 	    break;
-	case ICMP_NET_UNR_TOS:
+	case ICMP_UNREACH_TOSNET:
 	    g_string_assign(s,
 			    "Destination Network Unreachable At This TOS");
 	    break;
-	case ICMP_HOST_UNR_TOS:
+	case ICMP_UNREACH_TOSHOST:
 	    g_string_assign(s, "Destination Host Unreachable At This TOS");
 	    break;
-#ifdef ICMP_PKT_FILTERED
-	case ICMP_PKT_FILTERED:
+#ifdef ICMP_UNREACH_FILTER_PROHIB
+	case ICMP_UNREACH_FILTER_PROHIB:
 	    g_string_assign(s, "Packet Filtered");
 	    break;
 #endif
-#ifdef ICMP_PREC_VIOLATION
-	case ICMP_PREC_VIOLATION:
+#ifdef ICMP_HOST_PRECEDENCE
+	case ICMP_HOST_PRECEDENCE:
 	    g_string_assign(s, "Precedence Violation");
 	    break;
 #endif
-#ifdef ICMP_PREC_CUTOFF
-	case ICMP_PREC_CUTOFF:
+#ifdef ICMP_PRECEDENCE_CUTOFF
+	case ICMP_PRECEDENCE_CUTOFF:
 	    g_string_assign(s, "Precedence Cutoff");
 	    break;
 #endif
@@ -294,21 +297,21 @@
 	    break;
 	}
 	break;
-    case ICMP_SOURCE_QUENCH:
+    case ICMP_SOURCEQUENCH:
 	g_string_assign(s, "Source Quench");
 	break;
     case ICMP_REDIRECT:
 	switch (icp->icmp_code) {
-	case ICMP_REDIR_NET:
+	case ICMP_REDIRECT_NET:
 	    g_string_assign(s, "Redirect Network");
 	    break;
-	case ICMP_REDIR_HOST:
+	case ICMP_REDIRECT_HOST:
 	    g_string_assign(s, "Redirect Host");
 	    break;
-	case ICMP_REDIR_NETTOS:
+	case ICMP_REDIRECT_TOSNET:
 	    g_string_assign(s, "Redirect Type of Service and Network");
 	    break;
-	case ICMP_REDIR_HOSTTOS:
+	case ICMP_REDIRECT_TOSHOST:
 	    g_string_assign(s, "Redirect Type of Service and Host");
 	    break;
 	default:
@@ -322,12 +325,12 @@
 	g_string_assign(s, "Echo Request");
 	/* XXX ID + Seq + Data */
 	break;
-    case ICMP_TIME_EXCEEDED:
+    case ICMP_TIMXCEED:
 	switch (icp->icmp_code) {
-	case ICMP_EXC_TTL:
+	case ICMP_TIMXCEED_INTRANS:
 	    g_string_assign(s, "Time to live exceeded");
 	    break;
-	case ICMP_EXC_FRAGTIME:
+	case ICMP_TIMXCEED_REASS:
 	    g_string_assign(s, "Frag reassembly time exceeded");
 	    break;
 	default:
@@ -336,23 +339,23 @@
 	    break;
 	}
 	break;
-    case ICMP_PARAMETERPROB:
+    case ICMP_PARAMPROB:
 	g_string_sprintf(s, "Parameter problem: IP address = %s",
 			 inet_ntoa(icp->icmp_gwaddr));
 	break;
-    case ICMP_TIMESTAMP:
+    case ICMP_TSTAMP:
 	g_string_assign(s, "Timestamp");
 	/* XXX ID + Seq + 3 timestamps */
 	break;
-    case ICMP_TIMESTAMPREPLY:
+    case ICMP_TSTAMPREPLY:
 	g_string_assign(s, "Timestamp Reply");
 	/* XXX ID + Seq + 3 timestamps */
 	break;
-    case ICMP_INFO_REQUEST:
+    case ICMP_IREQ:
 	g_string_assign(s, "Information Request");
 	/* XXX ID + Seq */
 	break;
-    case ICMP_INFO_REPLY:
+    case ICMP_IREQREPLY:
 	g_string_assign(s, "Information Reply");
 	/* XXX ID + Seq */
 	break;
@@ -447,11 +450,11 @@
 	switch (icp->icmp_type) {
 	case ICMP_ECHO:
 	    return;
-	case ICMP_SOURCE_QUENCH:
+	case ICMP_SOURCEQUENCH:
 	case ICMP_REDIRECT:
-	case ICMP_DEST_UNREACH:
-	case ICMP_TIME_EXCEEDED:
-	case ICMP_PARAMETERPROB:
+	case ICMP_UNREACH:
+	case ICMP_TIMXCEED:
+	case ICMP_PARAMPROB:
 	    {
 		struct ip *iph = (struct ip *) (&icp->icmp_data);
 		struct icmp *icp1 =
@@ -464,7 +467,7 @@
 		    icp1->icmp_id != ident)
 		    return;
 		error_pkt = (icp->icmp_type != ICMP_REDIRECT &&
-			     icp->icmp_type != ICMP_SOURCE_QUENCH);
+			     icp->icmp_type != ICMP_SOURCEQUENCH);
 
 		h = (host_data *) g_list_find_custom(hosts,
 						     (int *) &icp1->
