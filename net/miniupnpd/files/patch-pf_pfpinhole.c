--- pf/pfpinhole.c.orig	2024-03-19 23:41:25 UTC
+++ pf/pfpinhole.c
@@ -28,6 +28,7 @@
 #include <syslog.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <libpfctl.h>
 
 #include "config.h"
 #include "pfpinhole.h"
@@ -171,6 +172,7 @@ int find_pinhole(const char * ifname,
 	unsigned int ts, tnum;
 	int i, n;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 	struct in6_addr saddr;
 	struct in6_addr daddr;
 	UNUSED(ifname);
@@ -191,7 +193,7 @@ int find_pinhole(const char * ifname,
 	pr.rule.action = PF_PASS;
 #endif
 	if(ioctl(dev, DIOCGETRULES, &pr) < 0) {
-		syslog(LOG_ERR, "ioctl(dev, DIOCGETRULES, ...): %m");
+		syslog(LOG_ERR, "ioctl(dev, DIOCGETRULES, ...) (%s:%d): %m", __func__, __LINE__);
 		return -1;
 	}
 	n = pr.nr;
@@ -200,22 +202,22 @@ int find_pinhole(const char * ifname,
 #endif /* PF_RELEASETICKETS */
 	for(i=0; i<n; i++) {
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0) {
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, PF_PASS, &rule, pr.anchor_call) < 0) {
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			release_ticket(dev, tnum);
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
@@ -234,6 +236,7 @@ int delete_pinhole(unsigned short uid)
 	int i, n;
 	unsigned int tnum;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 	char label_start[PF_RULE_LABEL_SIZE];
 	char tmp_label[PF_RULE_LABEL_SIZE];
 
@@ -249,7 +252,7 @@ int delete_pinhole(unsigned short uid)
 	pr.rule.action = PF_PASS;
 #endif
 	if(ioctl(dev, DIOCGETRULES, &pr) < 0) {
-		syslog(LOG_ERR, "ioctl(dev, DIOCGETRULES, ...): %m");
+		syslog(LOG_ERR, "ioctl(dev, DIOCGETRULES, ...) (%s:%d): %m", __func__, __LINE__);
 		return -1;
 	}
 	n = pr.nr;
@@ -258,11 +261,11 @@ int delete_pinhole(unsigned short uid)
 #endif
 	for(i=0; i<n; i++) {
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0) {
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, PF_PASS, &rule, pr.anchor_call) < 0) {
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			return -1;
 		}
-		strlcpy(tmp_label, pr.rule.label, sizeof(tmp_label));
+		strlcpy(tmp_label, rule.label[0], sizeof(tmp_label));
 		strtok(tmp_label, " ");
 		if(0 == strcmp(tmp_label, label_start)) {
 			pr.action = PF_CHANGE_GET_TICKET;
@@ -298,6 +301,7 @@ get_pinhole_info(unsigned short uid,
 	int i, n;
 	unsigned int tnum;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 	char label_start[PF_RULE_LABEL_SIZE];
 	char tmp_label[PF_RULE_LABEL_SIZE];
 	char * p;
@@ -314,7 +318,7 @@ get_pinhole_info(unsigned short uid,
 	pr.rule.action = PF_PASS;
 #endif
 	if(ioctl(dev, DIOCGETRULES, &pr) < 0) {
-		syslog(LOG_ERR, "ioctl(dev, DIOCGETRULES, ...): %m");
+		syslog(LOG_ERR, "ioctl(dev, DIOCGETRULES, ...) (%s:%d): %m", __func__, __LINE__);
 		return -1;
 	}
 	n = pr.nr;
@@ -323,29 +327,29 @@ get_pinhole_info(unsigned short uid,
 #endif
 	for(i=0; i<n; i++) {
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0) {
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, PF_PASS, &rule, pr.anchor_call) < 0) {
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			release_ticket(dev, tnum);
 			return -1;
 		}
-		strlcpy(tmp_label, pr.rule.label, sizeof(tmp_label));
+		strlcpy(tmp_label, rule.label[0], sizeof(tmp_label));
 		p = tmp_label;
 		strsep(&p, " ");
 		if(0 == strcmp(tmp_label, label_start)) {
-			if(rem_host && (inet_ntop(AF_INET6, &pr.rule.src.addr.v.a.addr.v6, rem_host, rem_hostlen) == NULL)) {
+			if(rem_host && (inet_ntop(AF_INET6, &rule.src.addr.v.a.addr.v6, rem_host, rem_hostlen) == NULL)) {
 				release_ticket(dev, tnum);
 				return -1;
 			}
 			if(rem_port)
-				*rem_port = ntohs(pr.rule.src.port[0]);
-			if(int_client && (inet_ntop(AF_INET6, &pr.rule.dst.addr.v.a.addr.v6, int_client, int_clientlen) == NULL)) {
+				*rem_port = ntohs(rule.src.port[0]);
+			if(int_client && (inet_ntop(AF_INET6, &rule.dst.addr.v.a.addr.v6, int_client, int_clientlen) == NULL)) {
 				release_ticket(dev, tnum);
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
@@ -358,14 +362,14 @@ get_pinhole_info(unsigned short uid,
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
 			release_ticket(dev, tnum);
 			return 0;
@@ -393,6 +397,7 @@ int clean_pinhole_list(unsigned int * next_timestamp)
 {
 	int i;
 	struct pfioc_rule pr;
+	struct pfctl_rule rule;
 	time_t current_time;
 	unsigned int ts, tnum;
 	int uid;
@@ -411,7 +416,7 @@ int clean_pinhole_list(unsigned int * next_timestamp)
 	pr.rule.action = PF_PASS;
 #endif
 	if(ioctl(dev, DIOCGETRULES, &pr) < 0) {
-		syslog(LOG_ERR, "ioctl(dev, DIOCGETRULES, ...): %m");
+		syslog(LOG_ERR, "ioctl(dev, DIOCGETRULES, ...) (%s:%d): %m", __func__, __LINE__);
 		return -1;
 	}
 #ifdef PF_RELEASETICKETS
@@ -419,17 +424,17 @@ int clean_pinhole_list(unsigned int * next_timestamp)
 #endif
 	for(i = pr.nr - 1; i >= 0; i--) {
 		pr.nr = i;
-		if(ioctl(dev, DIOCGETRULE, &pr) < 0) {
+		if (pfctl_get_rule(dev, i, pr.ticket, pr.anchor, PF_PASS, &rule, pr.anchor_call) < 0) {
 			syslog(LOG_ERR, "ioctl(dev, DIOCGETRULE): %m");
 			release_ticket(dev, tnum);
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
@@ -449,7 +454,7 @@ int clean_pinhole_list(unsigned int * next_timestamp)
 #endif
 			release_ticket(dev, tnum);
 			if(ioctl(dev, DIOCGETRULES, &pr) < 0) {
-				syslog(LOG_ERR, "ioctl(dev, DIOCGETRULES, ...): %m");
+				syslog(LOG_ERR, "ioctl(dev, DIOCGETRULES, ...) (%s:%d): %m", __func__, __LINE__);
 				return -1;
 			}
 #ifdef PF_RELEASETICKETS
