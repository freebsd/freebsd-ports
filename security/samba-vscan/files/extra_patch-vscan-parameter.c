--- global/vscan-parameter.c.orig	Mon Dec 12 01:36:54 2005
+++ global/vscan-parameter.c	Mon Dec 12 01:36:54 2005
@@ -162,6 +162,7 @@
                 */
 		/* FIXME: changed atoi to atoll, but atoll might not be available
 		   on all platforms! */
+		#define atoll(a) strtoll((a), (char **)NULL, 10)   
                 vscan_config->common.max_size = atoll(value);
                 DEBUG(3, ("max file size is: %lld\n", (long long)vscan_config->common.max_size));
    