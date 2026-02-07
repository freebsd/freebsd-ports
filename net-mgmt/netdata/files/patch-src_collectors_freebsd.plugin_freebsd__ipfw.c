--- src/collectors/freebsd.plugin/freebsd_ipfw.c.orig	2025-02-20 22:40:27 UTC
+++ src/collectors/freebsd.plugin/freebsd_ipfw.c
@@ -272,7 +272,11 @@ int do_ipfw(int update_every, usec_t dt) {
                     break;
 
                 dyn_rule = (ipfw_dyn_rule *) (tlv + 1);
+#if __FreeBSD_version < 1500034
                 bcopy(&dyn_rule->rule, &rulenum, sizeof(rulenum));
+#else
+                bcopy(&dyn_rule->rulenum, &rulenum, sizeof(rulenum));
+#endif
 
                 for (srn = 0; srn < (static_rules_num - 1); srn++) {
                     if (dyn_rule->expire > 0)
