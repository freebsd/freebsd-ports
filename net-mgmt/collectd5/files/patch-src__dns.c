--- src/dns.c.orig	2016-12-12 03:03:36.708279115 -0500
+++ src/dns.c	2017-01-03 08:10:33.137711000 -0500
@@ -198,6 +198,15 @@
     pthread_sigmask(SIG_SETMASK, &sigmask, NULL);
   }
 
+	/* Check for pcap_device, if needed */
+#ifdef __sparc64__
+  if (pcap_device == NULL)
+  {
+    ERROR ("dns plugin: Interface required");
+    return (NULL);
+  }
+#endif
+
   /* Passing `pcap_device == NULL' is okay and the same as passign "any" */
   DEBUG("dns plugin: Creating PCAP object..");
   pcap_obj = pcap_open_live((pcap_device != NULL) ? pcap_device : "any",
