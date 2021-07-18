--- opensshlib/umac.c.orig	2019-08-24 22:25:32 UTC
+++ opensshlib/umac.c
@@ -1177,7 +1177,7 @@ static int uhash(uhash_ctx_t ahc, u_char *msg, long le
  * time. The all-at-once is more optimaized than the sequential version and
  * should be preferred when the sequential interface is not required. 
  */
-struct umac_ctx {
+extern struct umac_ctx {
     uhash_ctx hash;          /* Hash function for message compression    */
     pdf_ctx pdf;             /* PDF for hashed output                    */
     void *free_ptr;          /* Address to free this struct via          */
