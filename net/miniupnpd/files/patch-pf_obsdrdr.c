--- pf/obsdrdr.c.orig	2023-02-17 03:09:33 UTC
+++ pf/obsdrdr.c
@@ -64,6 +64,8 @@
 #include <stdio.h>
 #include <stdlib.h>
 
+#include <libpfctl.h>
+
 #include "../macros.h"
 #include "config.h"
 #include "obsdrdr.h"
@@ -154,7 +156,7 @@ init_redirect(void)
 int
 init_redirect(void)
 {
-	struct pf_status status;
+	struct pfctl_status *status;
 	if(dev>=0)
 		shutdown_redirect();
 	dev = open("/dev/pf", O_RDWR);
@@ -162,14 +164,16 @@ init_redirect(void)
 		syslog(LOG_ERR, "open(\"/dev/pf\"): %m");
 		return -1;
 	}
-	if(ioctl(dev, DIOCGETSTATUS, &status)<0) {
+	if ((status = pfctl_get_status(dev)) == NULL) {
 		syslog(LOG_ERR, "DIOCGETSTATUS: %m");
 		return -1;
 	}
-	if(!status.running) {
+	if(!status->running) {
+		pfctl_free_status(status);
 		syslog(LOG_ERR, "pf is disabled");
 		return -1;
 	}
+	pfctl_free_status(status);
 	return 0;
 }
 
@@ -464,6 +468,7 @@ delete_nat_rule(const char * ifname, unsigned short ip
 {
 	int i, n;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 	UNUSED(ifname);
 	if(dev<0) {
 		syslog(LOG_ERR, "pf device is not open");
@@ -486,19 +491,19 @@ delete_nat_rule(const char * ifname, unsigned short ip
 	for(i=0; i<n; i++)
 	{
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0)
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, pr.action, &rule, pr.anchor_call) < 0)
 		{
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			goto error;
 		}
 #ifdef TEST
 		syslog(LOG_DEBUG, "%2d port=%hu proto=%d addr=%8x    %8x",
-		       i, ntohs(pr.rule.src.port[0]), pr.rule.proto,
-		       pr.rule.src.addr.v.a.addr.v4.s_addr, iaddr);
+		       i, ntohs(rule.src.port[0]), rule.proto,
+		       rule.src.addr.v.a.addr.v4.s_addr, iaddr);
 #endif /* TEST */
-		if(iport == ntohs(pr.rule.src.port[0])
-		 && pr.rule.proto == proto
-		 && iaddr == pr.rule.src.addr.v.a.addr.v4.s_addr)
+		if(iport == ntohs(rule.src.port[0])
+		 && rule.proto == proto
+		 && iaddr == rule.src.addr.v.a.addr.v4.s_addr)
 		{
 			pr.action = PF_CHANGE_GET_TICKET;
 			if(ioctl(dev, DIOCCHANGERULE, &pr) < 0)
@@ -843,6 +848,7 @@ get_redirect_rule(const char * ifname, unsigned short 
 {
 	int i, n;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 #ifndef PF_NEWSTYLE
 	struct pfioc_pooladdr pp;
 #endif
@@ -866,37 +872,37 @@ get_redirect_rule(const char * ifname, unsigned short 
 	for(i=0; i<n; i++)
 	{
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0)
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, pr.action, &rule, pr.anchor_call) < 0)
 		{
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			goto error;
 		}
 #ifdef __APPLE__
-		if( (eport == ntohs(pr.rule.dst.xport.range.port[0]))
-		  && (eport == ntohs(pr.rule.dst.xport.range.port[1]))
+		if( (eport == ntohs(rule.dst.xport.range.port[0]))
+		  && (eport == ntohs(rule.dst.xport.range.port[1]))
 #else
-		if( (eport == ntohs(pr.rule.dst.port[0]))
-		  && (eport == ntohs(pr.rule.dst.port[1]))
+		if( (eport == ntohs(rule.dst.port[0]))
+		  && (eport == ntohs(rule.dst.port[1]))
 #endif
-		  && (pr.rule.proto == proto) )
+		  && (rule.proto == proto) )
 		{
 #ifndef PF_NEWSTYLE
-			*iport = pr.rule.rpool.proxy_port[0];
+			*iport = rule.rpool.proxy_port[0];
 #else
-			*iport = pr.rule.rdr.proxy_port[0];
+			*iport = rule.rdr.proxy_port[0];
 #endif
 			if(desc)
-				strlcpy(desc, pr.rule.label, desclen);
+				strlcpy(desc, rule.label[0], desclen);
 #ifdef PFRULE_INOUT_COUNTS
 			if(packets)
-				*packets = pr.rule.packets[0] + pr.rule.packets[1];
+				*packets = rule.packets[0] + rule.packets[1];
 			if(bytes)
-				*bytes = pr.rule.bytes[0] + pr.rule.bytes[1];
+				*bytes = rule.bytes[0] + rule.bytes[1];
 #else
 			if(packets)
-				*packets = pr.rule.packets;
+				*packets = rule.packets;
 			if(bytes)
-				*bytes = pr.rule.bytes;
+				*bytes = rule.bytes;
 #endif
 #ifndef PF_NEWSTYLE
 			memset(&pp, 0, sizeof(pp));
@@ -928,15 +934,15 @@ get_redirect_rule(const char * ifname, unsigned short 
 			          iaddr, iaddrlen);
 #endif
 #else
-			inet_ntop(AF_INET, &pr.rule.rdr.addr.v.a.addr.v4.s_addr,
+			inet_ntop(AF_INET, &rule.rdr.addr.v.a.addr.v4.s_addr,
 			          iaddr, iaddrlen);
 #endif
 			if(rhost && rhostlen > 0)
 			{
 #ifdef PFVAR_NEW_STYLE
-				if (pr.rule.src.addr.v.a.addr.v4addr.s_addr == 0)
+				if (rule.src.addr.v.a.addr.v4addr.s_addr == 0)
 #else
-				if (pr.rule.src.addr.v.a.addr.v4.s_addr == 0)
+				if (rule.src.addr.v.a.addr.v4.s_addr == 0)
 #endif
 				{
 					rhost[0] = '\0'; /* empty string */
@@ -944,10 +950,10 @@ get_redirect_rule(const char * ifname, unsigned short 
 				else
 				{
 #ifdef PFVAR_NEW_STYLE
-					inet_ntop(AF_INET, &pr.rule.src.addr.v.a.addr.v4addr.s_addr,
+					inet_ntop(AF_INET, &rule.src.addr.v.a.addr.v4addr.s_addr,
 					          rhost, rhostlen);
 #else
-					inet_ntop(AF_INET, &pr.rule.src.addr.v.a.addr.v4.s_addr,
+					inet_ntop(AF_INET, &rule.src.addr.v.a.addr.v4.s_addr,
 					          rhost, rhostlen);
 #endif
 				}
@@ -978,6 +984,7 @@ priv_delete_redirect_rule_check_desc(const char * ifna
 {
 	int i, n;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 	UNUSED(ifname);
 
 	if(dev<0) {
@@ -998,23 +1005,23 @@ priv_delete_redirect_rule_check_desc(const char * ifna
 	for(i=0; i<n; i++)
 	{
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0)
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, pr.action, &rule, pr.anchor_call) < 0)
 		{
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			goto error;
 		}
 #ifdef __APPLE__
-		if( (eport == ntohs(pr.rule.dst.xport.range.port[0]))
-		  && (eport == ntohs(pr.rule.dst.xport.range.port[1]))
+		if( (eport == ntohs(rule.dst.xport.range.port[0]))
+		  && (eport == ntohs(rule.dst.xport.range.port[1]))
 #else
-		if( (eport == ntohs(pr.rule.dst.port[0]))
-		  && (eport == ntohs(pr.rule.dst.port[1]))
+		if( (eport == ntohs(rule.dst.port[0]))
+		  && (eport == ntohs(rule.dst.port[1]))
 #endif
-		  && (pr.rule.proto == proto) )
+		  && (rule.proto == proto) )
 		{
 			/* retrieve iport in order to remove filter rule */
 #ifndef PF_NEWSTYLE
-			if(iport) *iport = pr.rule.rpool.proxy_port[0];
+			if(iport) *iport = rule.rpool.proxy_port[0];
 			if(iaddr)
 			{
 				/* retrieve internal address */
@@ -1047,33 +1054,33 @@ priv_delete_redirect_rule_check_desc(const char * ifna
 #endif
 			}
 #else
-			if(iport) *iport = pr.rule.rdr.proxy_port[0];
+			if(iport) *iport = rule.rdr.proxy_port[0];
 			if(iaddr)
 			{
 				/* retrieve internal address */
-				*iaddr = pr.rule.rdr.addr.v.a.addr.v4.s_addr;
+				*iaddr = rule.rdr.addr.v.a.addr.v4.s_addr;
 			}
 #endif
 			if(rhost && rhostlen > 0)
 			{
 #ifdef PFVAR_NEW_STYLE
-				if (pr.rule.src.addr.v.a.addr.v4addr.s_addr == 0)
+				if (rule.src.addr.v.a.addr.v4addr.s_addr == 0)
 #else
-				if (pr.rule.src.addr.v.a.addr.v4.s_addr == 0)
+				if (rule.src.addr.v.a.addr.v4.s_addr == 0)
 #endif
 					rhost[0] = '\0'; /* empty string */
 				else
 #ifdef PFVAR_NEW_STYLE
-					inet_ntop(AF_INET, &pr.rule.src.addr.v.a.addr.v4addr.s_addr,
+					inet_ntop(AF_INET, &rule.src.addr.v.a.addr.v4addr.s_addr,
 					          rhost, rhostlen);
 #else
-					inet_ntop(AF_INET, &pr.rule.src.addr.v.a.addr.v4.s_addr,
+					inet_ntop(AF_INET, &rule.src.addr.v.a.addr.v4.s_addr,
 					          rhost, rhostlen);
 #endif
 			}
 			if(check_desc) {
-				if((desc == NULL && pr.rule.label[0] == '\0') ||
-				   (desc && 0 == strcmp(desc, pr.rule.label))) {
+				if((desc == NULL && rule.label[0][0] == '\0') ||
+				   (desc && 0 == strcmp(desc, rule.label[0]))) {
 					return 1;
 				}
 			}
@@ -1208,6 +1215,7 @@ get_redirect_rule_by_index(int index,
 {
 	int n;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 #ifndef PF_NEWSTYLE
 	struct pfioc_pooladdr pp;
 #endif
@@ -1231,36 +1239,36 @@ get_redirect_rule_by_index(int index,
 	if(index >= n)
 		goto error;
 	pr.nr = index;
-	if(ioctl(dev, DIOCGETRULE, &pr) < 0)
+	if (pfctl_get_rule(dev, index, pr.ticket, pr.anchor, pr.action, &rule, pr.anchor_call) < 0)
 	{
 		syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 		goto error;
 	}
-	*proto = pr.rule.proto;
+	*proto = rule.proto;
 #ifdef __APPLE__
-	*eport = ntohs(pr.rule.dst.xport.range.port[0]);
+	*eport = ntohs(rule.dst.xport.range.port[0]);
 #else
-	*eport = ntohs(pr.rule.dst.port[0]);
+	*eport = ntohs(rule.dst.port[0]);
 #endif
 #ifndef PF_NEWSTYLE
-	*iport = pr.rule.rpool.proxy_port[0];
+	*iport = rule.rpool.proxy_port[0];
 #else
-	*iport = pr.rule.rdr.proxy_port[0];
+	*iport = rule.rdr.proxy_port[0];
 #endif
 	if(ifname)
-		strlcpy(ifname, pr.rule.ifname, IFNAMSIZ);
+		strlcpy(ifname, rule.ifname, IFNAMSIZ);
 	if(desc)
-		strlcpy(desc, pr.rule.label, desclen);
+		strlcpy(desc, rule.label[0], desclen);
 #ifdef PFRULE_INOUT_COUNTS
 	if(packets)
-		*packets = pr.rule.packets[0] + pr.rule.packets[1];
+		*packets = rule.packets[0] + rule.packets[1];
 	if(bytes)
-		*bytes = pr.rule.bytes[0] + pr.rule.bytes[1];
+		*bytes = rule.bytes[0] + rule.bytes[1];
 #else
 	if(packets)
-		*packets = pr.rule.packets;
+		*packets = rule.packets;
 	if(bytes)
-		*bytes = pr.rule.bytes;
+		*bytes = rule.bytes;
 #endif
 #ifndef PF_NEWSTYLE
 	memset(&pp, 0, sizeof(pp));
@@ -1292,15 +1300,15 @@ get_redirect_rule_by_index(int index,
 	          iaddr, iaddrlen);
 #endif
 #else
-	inet_ntop(AF_INET, &pr.rule.rdr.addr.v.a.addr.v4.s_addr,
+	inet_ntop(AF_INET, &rule.rdr.addr.v.a.addr.v4.s_addr,
 	          iaddr, iaddrlen);
 #endif
 	if(rhost && rhostlen > 0)
 	{
 #ifdef PFVAR_NEW_STYLE
-		if (pr.rule.src.addr.v.a.addr.v4addr.s_addr == 0)
+		if (rule.src.addr.v.a.addr.v4addr.s_addr == 0)
 #else
-		if (pr.rule.src.addr.v.a.addr.v4.s_addr == 0)
+		if (rule.src.addr.v.a.addr.v4.s_addr == 0)
 #endif
 		{
 			rhost[0] = '\0'; /* empty string */
@@ -1308,10 +1316,10 @@ get_redirect_rule_by_index(int index,
 		else
 		{
 #ifdef PFVAR_NEW_STYLE
-			inet_ntop(AF_INET, &pr.rule.src.addr.v.a.addr.v4addr.s_addr,
+			inet_ntop(AF_INET, &rule.src.addr.v.a.addr.v4addr.s_addr,
 			          rhost, rhostlen);
 #else
-			inet_ntop(AF_INET, &pr.rule.src.addr.v.a.addr.v4.s_addr,
+			inet_ntop(AF_INET, &rule.src.addr.v.a.addr.v4.s_addr,
 			          rhost, rhostlen);
 #endif
 		}
@@ -1334,6 +1342,7 @@ get_portmappings_in_range(unsigned short startport, un
 	int i, n;
 	unsigned short eport;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 
 	*number = 0;
 	if(dev<0) {
@@ -1362,19 +1371,19 @@ get_portmappings_in_range(unsigned short startport, un
 	for(i=0; i<n; i++)
 	{
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0)
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, pr.action, &rule, pr.anchor_call) < 0)
 		{
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			continue;
 		}
 #ifdef __APPLE__
-		eport = ntohs(pr.rule.dst.xport.range.port[0]);
-		if( (eport == ntohs(pr.rule.dst.xport.range.port[1]))
+		eport = ntohs(rule.dst.xport.range.port[0]);
+		if( (eport == ntohs(rule.dst.xport.range.port[1]))
 #else
-		eport = ntohs(pr.rule.dst.port[0]);
-		if( (eport == ntohs(pr.rule.dst.port[1]))
+		eport = ntohs(rule.dst.port[0]);
+		if( (eport == ntohs(rule.dst.port[1]))
 #endif
-		  && (pr.rule.proto == proto)
+		  && (rule.proto == proto)
 		  && (startport <= eport) && (eport <= endport) )
 		{
 			if(*number >= capacity)
