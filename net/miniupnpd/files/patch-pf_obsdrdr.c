--- pf/obsdrdr.c.orig	2026-09-30 17:32:31 UTC
+++ pf/obsdrdr.c
@@ -448,6 +448,7 @@ int add_nat_rule(const char * ifname,
 		TAILQ_INSERT_TAIL(&pcr.rule.rpool.list, a, entries);
 
 		memcpy(&pp.addr, a, sizeof(struct pf_pooladdr));
+		pp.af = pcr.rule.af;
 		if(ioctl(dev, DIOCADDADDR, &pp) < 0)
 		{
 			syslog(LOG_ERR, "ioctl(dev, DIOCADDADDR, ...): %m");
@@ -743,6 +744,7 @@ add_redirect_rule2(const char * ifname,
 		TAILQ_INSERT_TAIL(&pcr.rule.rpool.list, a, entries);
 
 		memcpy(&pp.addr, a, sizeof(struct pf_pooladdr));
+		pp.af = pcr.rule.af;
 		if(ioctl(dev, DIOCADDADDR, &pp) < 0)
 		{
 			syslog(LOG_ERR, "ioctl(dev, DIOCADDADDR, ...): %m");
