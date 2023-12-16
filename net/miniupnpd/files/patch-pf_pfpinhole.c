--- pf/pfpinhole.c.orig	2023-10-30 16:24:29 UTC
+++ pf/pfpinhole.c
@@ -28,6 +28,7 @@
 #include <syslog.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <libpfctl.h>
 
 #include "config.h"
 #include "pfpinhole.h"
@@ -170,6 +171,7 @@ int find_pinhole(const char * ifname,
 	unsigned int ts;
 	int i, n;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 	struct in6_addr saddr;
 	struct in6_addr daddr;
 	UNUSED(ifname);
@@ -196,21 +198,21 @@ int find_pinhole(const char * ifname,
 	n = pr.nr;
 	for(i=0; i<n; i++) {
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0) {
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, pr.action, &rule, pr.anchor_call) < 0) {
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			return -1;
 		}
-		if((proto == pr.rule.proto) && (rem_port == ntohs(pr.rule.src.port[0]))
-		   && (0 == memcmp(&saddr, &pr.rule.src.addr.v.a.addr.v6, sizeof(struct in6_addr)))
-		   && (int_port == ntohs(pr.rule.dst.port[0])) &&
-		   (0 == memcmp(&daddr, &pr.rule.dst.addr.v.a.addr.v6, sizeof(struct in6_addr)))) {
-			if(sscanf(pr.rule.label, PINEHOLE_LABEL_FORMAT_SKIPDESC, &uid, &ts) != 2) {
-				syslog(LOG_DEBUG, "rule with label '%s' is not a IGD pinhole", pr.rule.label);
+		if((proto == rule.proto) && (rem_port == ntohs(rule.src.port[0]))
+		   && (0 == memcmp(&saddr, &rule.src.addr.v.a.addr.v6, sizeof(struct in6_addr)))
+		   && (int_port == ntohs(rule.dst.port[0])) &&
+		   (0 == memcmp(&daddr, &rule.dst.addr.v.a.addr.v6, sizeof(struct in6_addr)))) {
+			if(sscanf(rule.label[0], PINEHOLE_LABEL_FORMAT_SKIPDESC, &uid, &ts) != 2) {
+				syslog(LOG_DEBUG, "rule with label '%s' is not a IGD pinhole", rule.label[0]);
 				continue;
 			}
 			if(timestamp) *timestamp = ts;
 			if(desc) {
-				char * p = strchr(pr.rule.label, ':');
+				char * p = strchr(rule.label[0], ':');
 				if(p) {
 					p += 2;
 					strlcpy(desc, p, desc_len);
@@ -226,6 +228,7 @@ int delete_pinhole(unsigned short uid)
 {
 	int i, n;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 	char label_start[PF_RULE_LABEL_SIZE];
 	char tmp_label[PF_RULE_LABEL_SIZE];
 
@@ -247,11 +250,11 @@ int delete_pinhole(unsigned short uid)
 	n = pr.nr;
 	for(i=0; i<n; i++) {
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0) {
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, pr.action, &rule, pr.anchor_call) < 0) {
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			return -1;
 		}
-		strlcpy(tmp_label, pr.rule.label, sizeof(tmp_label));
+		strlcpy(tmp_label, rule.label[0], sizeof(tmp_label));
 		strtok(tmp_label, " ");
 		if(0 == strcmp(tmp_label, label_start)) {
 			pr.action = PF_CHANGE_GET_TICKET;
@@ -282,6 +285,7 @@ get_pinhole_info(unsigned short uid,
 {
 	int i, n;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 	char label_start[PF_RULE_LABEL_SIZE];
 	char tmp_label[PF_RULE_LABEL_SIZE];
 	char * p;
@@ -304,26 +308,26 @@ get_pinhole_info(unsigned short uid,
 	n = pr.nr;
 	for(i=0; i<n; i++) {
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0) {
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, pr.action, &rule, pr.anchor_call) < 0) {
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			return -1;
 		}
-		strlcpy(tmp_label, pr.rule.label, sizeof(tmp_label));
+		strlcpy(tmp_label, rule.label[0], sizeof(tmp_label));
 		p = tmp_label;
 		strsep(&p, " ");
 		if(0 == strcmp(tmp_label, label_start)) {
-			if(rem_host && (inet_ntop(AF_INET6, &pr.rule.src.addr.v.a.addr.v6, rem_host, rem_hostlen) == NULL)) {
+			if(rem_host && (inet_ntop(AF_INET6, &rule.src.addr.v.a.addr.v6, rem_host, rem_hostlen) == NULL)) {
 				return -1;
 			}
 			if(rem_port)
-				*rem_port = ntohs(pr.rule.src.port[0]);
-			if(int_client && (inet_ntop(AF_INET6, &pr.rule.dst.addr.v.a.addr.v6, int_client, int_clientlen) == NULL)) {
+				*rem_port = ntohs(rule.src.port[0]);
+			if(int_client && (inet_ntop(AF_INET6, &rule.dst.addr.v.a.addr.v6, int_client, int_clientlen) == NULL)) {
 				return -1;
 			}
 			if(int_port)
-				*int_port = ntohs(pr.rule.dst.port[0]);
+				*int_port = ntohs(rule.dst.port[0]);
 			if(proto)
-				*proto = pr.rule.proto;
+				*proto = rule.proto;
 			if(timestamp)
 				sscanf(p, "ts-%u", timestamp);
 			if(desc) {
@@ -336,14 +340,14 @@ get_pinhole_info(unsigned short uid,
 			}
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
 			return 0;
 		}
@@ -369,6 +373,7 @@ int clean_pinhole_list(unsigned int * next_timestamp)
 {
 	int i;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 	time_t current_time;
 	unsigned int ts;
 	int uid;
@@ -392,16 +397,16 @@ int clean_pinhole_list(unsigned int * next_timestamp)
 	}
 	for(i = pr.nr - 1; i >= 0; i--) {
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0) {
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, pr.action, &rule, pr.anchor_call) < 0) {
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			return -1;
 		}
-		if(sscanf(pr.rule.label, PINEHOLE_LABEL_FORMAT_SKIPDESC, &uid, &ts) != 2) {
-			syslog(LOG_DEBUG, "rule with label '%s' is not a IGD pinhole", pr.rule.label);
+		if(sscanf(rule.label[0], PINEHOLE_LABEL_FORMAT_SKIPDESC, &uid, &ts) != 2) {
+			syslog(LOG_DEBUG, "rule with label '%s' is not a IGD pinhole", rule.label[0]);
 			continue;
 		}
 		if(ts <= (unsigned int)current_time) {
-			syslog(LOG_INFO, "removing expired pinhole '%s'", pr.rule.label);
+			syslog(LOG_INFO, "removing expired pinhole '%s'", rule.label[0]);
 			pr.action = PF_CHANGE_GET_TICKET;
 			if(ioctl(dev, DIOCCHANGERULE, &pr) < 0) {
 				syslog(LOG_ERR, "ioctl(dev, DIOCCHANGERULE, ...) PF_CHANGE_GET_TICKET: %m");
