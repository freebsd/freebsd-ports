--- common/md5.h.orig	2017-07-05 07:48:49 UTC
+++ common/md5.h
@@ -98,21 +98,21 @@ struct md5_ctx
 
 /* Initialize structure containing state of computation.
    (RFC 1321, 3.3: Step 3)  */
-extern void __md5_init_ctx (struct md5_ctx *ctx) __THROW;
+extern void __md5_init_ctx (struct md5_ctx *ctx) ;
 
 /* Starting with the result of former calls of this function (or the
    initialization function update the context for the next LEN bytes
    starting at BUFFER.
    It is necessary that LEN is a multiple of 64!!! */
 extern void __md5_process_block (const void *buffer, size_t len,
-                 struct md5_ctx *ctx) __THROW;
+                 struct md5_ctx *ctx) ;
 
 /* Starting with the result of former calls of this function (or the
    initialization function update the context for the next LEN bytes
    starting at BUFFER.
    It is NOT required that LEN is a multiple of 64.  */
 extern void __md5_process_bytes (const void *buffer, size_t len,
-                 struct md5_ctx *ctx) __THROW;
+                 struct md5_ctx *ctx) ;
 
 /* Process the remaining bytes in the buffer and put result from CTX
    in first 16 bytes following RESBUF.  The result is always in little
@@ -121,7 +121,7 @@ extern void __md5_process_bytes (const void *buffer, s
 
    IMPORTANT: On some systems it is required that RESBUF is correctly
    aligned for a 32 bits value.  */
-extern void *__md5_finish_ctx (struct md5_ctx *ctx, void *resbuf) __THROW;
+extern void *__md5_finish_ctx (struct md5_ctx *ctx, void *resbuf) ;
 
 
 /* Put result from CTX in first 16 bytes following RESBUF.  The result is
@@ -130,19 +130,19 @@ extern void *__md5_finish_ctx (struct md5_ctx *ctx, vo
 
    IMPORTANT: On some systems it is required that RESBUF is correctly
    aligned for a 32 bits value.  */
-extern void *__md5_read_ctx (const struct md5_ctx *ctx, void *resbuf) __THROW;
+extern void *__md5_read_ctx (const struct md5_ctx *ctx, void *resbuf) ;
 
 
 /* Compute MD5 message digest for bytes read from STREAM.  The
    resulting message digest number will be written into the 16 bytes
    beginning at RESBLOCK.  */
-extern int __md5_stream (FILE *stream, void *resblock) __THROW;
+extern int __md5_stream (FILE *stream, void *resblock) ;
 
 /* Compute MD5 message digest for LEN bytes beginning at BUFFER.  The
    result is always in little endian byte order, so that a byte-wise
    output yields to the wanted ASCII representation of the message
    digest.  */
 extern void *__md5_buffer (const char *buffer, size_t len,
-               void *resblock) __THROW;
+               void *resblock) ;
 
 #endif /* md5.h */
