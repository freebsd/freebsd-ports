diff --git src/dns.c src/dns.c
index fe3b672..0c43985 100644
--- src/dns.c
+++ src/dns.c
@@ -223,6 +223,15 @@ static void *dns_child_loop (__attribute__((unused)) void *dummy)
 		pthread_sigmask (SIG_SETMASK, &sigmask, NULL);
 	}
 
+	/* Check for pcap_device, if needed */
+#ifdef __sparc64__
+	if (pcap_device == NULL)
+	{
+		ERROR ("dns plugin: Interface required");
+		return (NULL);
+	}
+#endif
+
 	/* Passing `pcap_device == NULL' is okay and the same as passign "any" */
 	DEBUG ("dns plugin: Creating PCAP object..");
 	pcap_obj = pcap_open_live ((pcap_device != NULL) ? pcap_device : "any",
