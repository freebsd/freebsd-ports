--- hash.h.orig	2007-05-10 21:18:39 UTC
+++ hash.h
@@ -18,7 +18,7 @@ struct IP_bucket {
         char IP[RECVFROM];
         IP_bucket *next;
 };
-IP_bucket* IP_bucket_arr[NUM_HASH];
+extern IP_bucket* IP_bucket_arr[NUM_HASH];
 
 
 typedef struct bucket bucket;
@@ -30,7 +30,7 @@ struct bucket {
 	int is_spammer;
 	bucket *next;
 };
-bucket* bucket_arr[NUM_HASH];
+extern bucket* bucket_arr[NUM_HASH];
 
 extern unsigned int
 cdbhash(char *buf, unsigned int len);
