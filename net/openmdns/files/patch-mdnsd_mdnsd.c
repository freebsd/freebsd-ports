--- mdnsd/mdnsd.c.orig	2017-03-10 09:24:12 UTC
+++ mdnsd/mdnsd.c
@@ -45,8 +45,12 @@ int		mdns_sock(void);
 void		fetchmyname(char [MAXHOSTNAMELEN]);
 void		fetchhinfo(struct hinfo *);
 
+ctl_conns_t	ctl_conns;
+
 struct mdnsd_conf	*conf = NULL;
+#ifdef __OpenBSD__
 extern char		*malloc_options;
+#endif
 
 __dead void
 usage(void)
@@ -230,7 +234,9 @@ main(int argc, char *argv[])
 		switch (ch) {
 		case 'd':
 			debug = 1;
+#ifdef __OpenBSD__
 			malloc_options = "AFGJPX";
+#endif
 			break;
 		case 'v':
 			display_version();
