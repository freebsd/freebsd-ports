--- src/lookup.h.orig   2011-06-04 14:06:21.000000000 +0900
+++ src/lookup.h        2011-06-04 14:20:51.000000000 +0900
@@ -40,3 +40,16 @@
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
