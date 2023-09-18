--- src/fw-pf.c.orig	2019-03-19 17:55:02 UTC
+++ src/fw-pf.c
@@ -15,6 +15,7 @@
 #include <net/if.h>
 #include <netinet/in.h>
 #include <net/pfvar.h>
+#include <libpfctl.h>
 
 #include <assert.h>
 #include <errno.h>
@@ -115,7 +116,7 @@ static int
 }
 
 static int
-pr_to_fr(const struct pf_rule *pr, struct fw_rule *fr)
+pr_to_fr(const struct pfctl_rule *pr, struct fw_rule *fr)
 {
 	memset(fr, 0, sizeof(*fr));
 	
@@ -205,12 +206,14 @@ fw_add(fw_t *fw, const struct fw_rule *rule)
 #ifdef HAVE_PF_CHANGE_GET_TICKET
 	{
 		struct fw_rule fr;
+		struct pfctl_rule pfrule;
 		
 		if (ioctl(fw->fd, DIOCGETRULES, &pcr) < 0)
 			return (-1);
 		while ((int)--pcr.nr >= 0) {
-			if (ioctl(fw->fd, DIOCGETRULE, &pcr) == 0 &&
-			    pr_to_fr(&pcr.rule, &fr) == 0) {
+			if (pfctl_get_rule(fw->fd, pcr.nr, pcr.ticket, pcr.anchor,
+			    pcr.action, &pfrule, pcr.anchor_call) == 0 &&
+			    pr_to_fr(&pfrule, &fr) == 0) {
 				if (_fw_cmp(rule, &fr) == 0) {
 					errno = EEXIST;
 					return (-1);
@@ -244,13 +247,15 @@ fw_delete(fw_t *fw, const struct fw_rule *rule)
 #ifdef HAVE_PF_CHANGE_GET_TICKET
 	{
 		struct fw_rule fr;
+		struct pfctl_rule pfrule;
 		int found = 0;
 		
 		if (ioctl(fw->fd, DIOCGETRULES, &pcr) < 0)
 			return (-1);
 		while ((int)--pcr.nr >= 0) {
-			if (ioctl(fw->fd, DIOCGETRULE, &pcr) == 0 &&
-			    pr_to_fr(&pcr.rule, &fr) == 0) {
+			if (pfctl_get_rule(fw->fd, pcr.nr, pcr.ticket, pcr.anchor, 
+			    pcr.action, &pfrule, pcr.anchor_call) == 0 &&
+			    pr_to_fr(&pfrule, &fr) == 0) {
 				if (_fw_cmp(rule, &fr) == 0) {
 					found = 1;
 					break;
@@ -282,6 +287,7 @@ fw_loop(fw_t *fw, fw_handler callback, void *arg)
 fw_loop(fw_t *fw, fw_handler callback, void *arg)
 {
 	struct pfioc_rule pr;
+	struct pfctl_rule pfrule;
 	struct fw_rule fr;
 	uint32_t n, max;
 	int ret = 0;
@@ -292,8 +298,9 @@ fw_loop(fw_t *fw, fw_handler callback, void *arg)
 	
 	for (n = 0, max = pr.nr; n < max; n++) {
 		pr.nr = n;
-		
-		if ((ret = ioctl(fw->fd, DIOCGETRULE, &pr)) < 0)
+
+		if ((ret = pfctl_get_rule(fw->fd, pr.nr, pr.ticket, pr.anchor,
+		    pr.action, &pfrule, pr.anchor_call)) < 0)
 			break;
 #ifdef PF_TABLE_NAME_SIZE
 		/* XXX - actually in r1.125, not 1.126 */
@@ -301,7 +308,7 @@ fw_loop(fw_t *fw, fw_handler callback, void *arg)
 		    pr.rule.dst.addr.type == PF_ADDR_TABLE)
 			continue;
 #endif
-		if (pr_to_fr(&pr.rule, &fr) < 0)
+		if (pr_to_fr(&pfrule, &fr) < 0)
 			continue;
 		if ((ret = callback(&fr, arg)) != 0)
 			break;
