--- targets.cc.orig	Thu Jun 17 13:33:04 2004
+++ targets.cc	Thu Jun 17 13:34:44 2004
@@ -259,16 +259,16 @@
 	/* We figure out the source IP/device IFF
 	   1) We are r00t AND
 	   2) We are doing tcp or udp pingscan OR
-	   3) We are doing a raw-mode portscan or osscan OR 
+	   3) We are doing a raw-mode portscan or osscan OR
 	   4) We are on windows and doing ICMP ping */
 	if (o.isr00t && o.af() == AF_INET && 
 	    ((*pingtype & (PINGTYPE_TCP|PINGTYPE_UDP)) || 
 	     o.synscan || o.finscan || o.xmasscan || o.nullscan || 
 	     o.ipprotscan || o.maimonscan || o.idlescan || o.ackscan || 
-	     o.udpscan || o.osscan || o.windowscan
-#ifdef WIN32
-         || (*pingtype & (PINGTYPE_ICMP_PING|PINGTYPE_ICMP_MASK|PINGTYPE_ICMP_TS))
-#endif // WIN32
+	     o.udpscan || o.osscan || o.windowscan
+#ifdef WIN32
+         || (*pingtype & (PINGTYPE_ICMP_PING|PINGTYPE_ICMP_MASK|PINGTYPE_ICMP_TS))
+#endif // WIN32
 		 )) {
 	  struct sockaddr_in *sin = (struct sockaddr_in *) &ss;
 	  sslen = sizeof(*sin);
@@ -279,14 +279,13 @@
 	  device = routethrough(hs->hostbatch[hidx]->v4hostip(), 
 				&(sin->sin_addr));
 	  hs->hostbatch[hidx]->setSourceSockAddr(&ss, sslen);
-      o.decoys[o.decoyturn] = hs->hostbatch[hidx]->v4source();
 	  if (!device) {
 	    if (*pingtype == PINGTYPE_NONE) {
 	      fatal("Could not determine what interface to route packets through, run again with -e <device>");
 	    } else {
-#if WIN32
+#if WIN32
           fatal("Unable to determine what interface to route packets through to %s", hs->hostbatch[hidx]->targetipstr());
-#endif
+#endif
 	      error("WARNING:  Could not determine what interface to route packets through to %s, changing ping scantype to ICMP ping only", hs->hostbatch[hidx]->targetipstr());
 	      *pingtype = PINGTYPE_ICMP_PING;
 	    }
@@ -305,6 +304,7 @@
 	delete hs->hostbatch[hidx];
 	goto batchfull;
       }
+      o.decoys[o.decoyturn] = hs->hostbatch[hidx]->v4source();
       hs->current_batch_sz++;
     }
 
