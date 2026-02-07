--- hash.c.orig	2007-05-10 21:18:39 UTC
+++ hash.c
@@ -141,7 +141,7 @@ hash_lookup(const char *target, unsigned int h)
         bp = bucket_arr[h];
 
         while (bp != NULL) {
-                if (! strncmp(bp->subject, target, sizeof(target)))
+                if (! strncmp(bp->subject, target, sizeof(bp->subject)))
                         return bp;
                 bp = bp->next;
         }
@@ -156,7 +156,7 @@ hash_lookup_IP(const char *target, unsigned int h)
         ip = IP_bucket_arr[h];
 
         while (ip != NULL) {
-                if (! strncmp(ip->IP, target, sizeof(target)))
+                if (! strncmp(ip->IP, target, sizeof(ip->IP)))
                         return 1;
                 ip = ip->next;
         }
