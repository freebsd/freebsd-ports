--- crypto/bio/bss_dgram.c.orig	2015-03-19 13:37:10 UTC
+++ crypto/bio/bss_dgram.c
@@ -1293,7 +1293,7 @@ static int dgram_sctp_read(BIO *b, char 
                 (socklen_t) (sizeof(sctp_assoc_t) + 256 * sizeof(uint8_t));
             authchunks = OPENSSL_malloc(optlen);
             if (!authchunks) {
-                BIOerr(BIO_F_DGRAM_SCTP_READ, ERR_R_MALLOC_ERROR);
+                BIOerr(BIO_F_DGRAM_SCTP_READ, ERR_R_MALLOC_FAILURE);
                 return -1;
             }
             memset(authchunks, 0, sizeof(optlen));
@@ -1365,7 +1365,7 @@ static int dgram_sctp_write(BIO *b, cons
         char *tmp;
         data->saved_message.bio = b;
         if(!(tmp = OPENSSL_malloc(inl))) {
-            BIOerr(BIO_F_DGRAM_SCTP_WRITE, ERR_R_MALLOC_ERROR);
+            BIOerr(BIO_F_DGRAM_SCTP_WRITE, ERR_R_MALLOC_FAILURE);
             return -1;
         }
         if (data->saved_message.data)
