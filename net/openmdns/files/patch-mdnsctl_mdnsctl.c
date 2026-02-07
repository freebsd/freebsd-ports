--- mdnsctl/mdnsctl.c.orig	2017-03-10 09:24:12 UTC
+++ mdnsctl/mdnsctl.c
@@ -67,8 +67,10 @@ main(int argc, char *argv[])
 	struct mdns		mdns;
 	struct mdns_service	ms;
 
+#ifdef __OpenBSD__
 	if (pledge("stdio unix", NULL) == -1)
 		err(1, NULL);
+#endif
 
 	/* parse options */
 	if ((res = parse(argc - 1, argv + 1)) == NULL)
@@ -77,8 +79,10 @@ main(int argc, char *argv[])
 	if ((sockfd = mdns_open(&mdns)) == -1)
 		err(1, "mdns_open");
 
+#ifdef __OpenBSD__
 	if (pledge("stdio", NULL) == -1)
 		err(1, NULL);
+#endif
 
 	mdns_set_lookup_A_hook(&mdns, my_lookup_A_hook);
 	mdns_set_lookup_PTR_hook(&mdns, my_lookup_PTR_hook);
