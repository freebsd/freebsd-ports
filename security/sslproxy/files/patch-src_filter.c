--- src/filter.c.orig	2025-11-14 18:16:45 UTC
+++ src/filter.c
@@ -1150,12 +1150,12 @@ filter_ip_btree_str(kbtree_t(ip) *btree)
 	i->ip = *p; \
 	append_list(&ip, i, filter_ip_list_t); \
 } while (0)
-	
+
 	filter_ip_list_t *ip = NULL;
 	__kb_traverse(filter_ip_p_t, btree, build_ip_list);
 
 	char *s = filter_ip_list_str(ip);
-	
+
 	free_list(ip, filter_ip_list_t);
 	return s;
 }
@@ -1363,7 +1363,7 @@ filter_desc_acm_str(ACMachine(char) *acm)
 	ACM_foreach_keyword(acm, build_desc_list_acm);
 
 	char *s = filter_desc_list_str(desc_list_acm);
-	
+
 	free_list(desc_list_acm, filter_desc_list_t);
 	desc_list_acm = NULL;
 	return s;
@@ -1701,10 +1701,12 @@ err:
 			free(rule->sni);
 		if (rule->cn)
 			free(rule->cn);
+#ifndef WITHOUT_USERAUTH
 		if (rule->user)
 			free(rule->user);
 		if (rule->desc)
 			free(rule->desc);
+#endif /* !WITHOUT_USERAUTH */
 		if (rule->ip)
 			free(rule->ip);
 		free(rule);
