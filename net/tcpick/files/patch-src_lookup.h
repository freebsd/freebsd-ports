--- src/lookup.h.orig	2004-12-31 13:53:30 UTC
+++ src/lookup.h
@@ -40,3 +40,16 @@ struct _l_node /* the node/leaf of the t
 	char * name;
 	struct in_addr ip;
 };
+
+char *
+lookup(struct in_addr ia);
+
+char *
+getportname(u_int16_t port);
+
+struct _l_node *
+_l_alloc(struct in_addr, char *);
+
+char *
+_l_get(struct in_addr);
+
