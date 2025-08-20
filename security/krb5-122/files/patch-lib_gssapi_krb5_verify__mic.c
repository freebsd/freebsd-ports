--- lib/gssapi/krb5/verify_mic.c.orig	2025-08-05 14:15:15 UTC
+++ lib/gssapi/krb5/verify_mic.c
@@ -90,7 +90,6 @@ verify_mic_v3(krb5_context context, OM_uint32 *minor_s
               krb5_gss_ctx_id_rec *ctx, struct k5input *in,
               gss_buffer_t message)
 {
-    OM_uint32 status;
     krb5_keyusage usage;
     krb5_key key;
     krb5_cksumtype cksumtype;
@@ -124,12 +123,10 @@ verify_mic_v3(krb5_context context, OM_uint32 *minor_s
     }
     assert(key != NULL);
 
-    status = kg_verify_checksum_v3(context, key, usage, cksumtype,
-                                   KG2_TOK_MIC_MSG, flags, seqnum,
-                                   message->value, message->length,
-                                   in->ptr, in->len);
-    if (status != GSS_S_COMPLETE)
-        return status;
+    if (!kg_verify_checksum_v3(context, key, usage, cksumtype, KG2_TOK_MIC_MSG,
+                               flags, seqnum, message->value, message->length,
+                               in->ptr, in->len))
+        return GSS_S_BAD_SIG;
 
     return g_seqstate_check(ctx->seqstate, seqnum);
 }
