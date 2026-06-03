--- mdnsd/mdnsd.c.orig	2026-03-19 21:46:02 UTC
+++ mdnsd/mdnsd.c
@@ -51,8 +51,12 @@
 void			 fetchhinfo(struct hinfo *);
 struct reflect_rule	*parse_reflect_rule(char *);
 
+ctl_conns_t	ctl_conns;
+
 struct mdnsd_conf	*conf = NULL;
+#ifdef __OpenBSD__
 extern char		*malloc_options;
+#endif
 
 __dead void
 usage(void)
@@ -307,7 +311,9 @@
 		switch (ch) {
 		case 'd':
 			debug = 1;
+#ifdef __OpenBSD__
 			malloc_options = "CFGJ";
+#endif
 			break;
 		default:
 			break;
