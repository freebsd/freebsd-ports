--- parse.c.orig	2019-04-17 18:31:23 UTC
+++ parse.c
@@ -553,7 +553,7 @@ xml_attrkey(struct parse *p, const char *name)
 	const char	*value;
 	enum attrkey	 key;
 
-	if (p->del > 0 || p->ncur == NODE_IGNORE || *name == '\0')
+	if (p->del > 0 || p->ncur == NODE_UNKNOWN || *name == '\0')
 		return;
 
 	if ((p->ncur == NODE_DOCTYPE || p->ncur == NODE_ENTITY) &&
@@ -590,7 +590,7 @@ xml_attrval(struct parse *p, const char *name)
 {
 	struct pattr	*a;
 
-	if (p->del > 0 || p->ncur == NODE_IGNORE ||
+	if (p->del > 0 || p->ncur == NODE_UNKNOWN ||
 	    (p->flags & PFLAG_ATTR) == 0)
 		return;
 	if ((a = TAILQ_LAST(&p->cur->attrq, pattrq)) == NULL)
