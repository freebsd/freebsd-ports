--- src/dns.c.orig	2008-09-05 15:26:02.000000000 +0000
+++ src/dns.c	2008-09-05 15:25:55.000000000 +0000
@@ -210,6 +210,15 @@
 		pthread_sigmask (SIG_SETMASK, &sigmask, NULL);
 	}
 
+	/* Check for pcap_device, if needed */
+#ifdef __sparc64__
+	if (pcap_device == NULL)
+	{
+	    ERROR ("dns plugin: Interface required");
+	    return (NULL);
+	}
+#endif
+
 	/* Passing `pcap_device == NULL' is okay and the same as passign "any" */
 	DEBUG ("Creating PCAP object..");
 	pcap_obj = pcap_open_live (pcap_device,
