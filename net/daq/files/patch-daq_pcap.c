--- os-daq-modules/daq_pcap.c.orig	2011-01-30 15:28:19.000000000 -0500
+++ os-daq-modules/daq_pcap.c	2011-01-30 15:27:19.000000000 -0500
@@ -216,7 +216,7 @@ static int pcap_daq_initialize(const DAQ
     for (entry = config->values; entry; entry = entry->next)
     {
         if (!strcmp(entry->key, "buffer_size"))
-            context->buffer_size = strtol(entry->key, NULL, 10);
+            context->buffer_size = strtol(entry->value, NULL, 10);
     }
     /* Try to account for legacy PCAP_FRAMES environment variable if we weren't passed a buffer size. */
     if (context->buffer_size == 0)
