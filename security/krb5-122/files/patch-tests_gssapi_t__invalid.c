--- tests/gssapi/t_invalid.c.orig	2025-08-05 14:15:15 UTC
+++ tests/gssapi/t_invalid.c
@@ -397,6 +397,34 @@ test_iov_large_asn1_wrapper(gss_ctx_id_t ctx)
     free(iov[0].buffer.value);
 }
 
+static void
+test_cfx_verify_mic(gss_ctx_id_t ctx)
+{
+    OM_uint32 major, minor;
+    gss_buffer_desc message, token;
+    uint8_t msg[] = "message";
+    uint8_t mic[] = "\x04\x04\x00\xFF\xFF\xFF\xFF\xFF"
+        "\x00\x00\x00\x00\x00\x00\x00\x00\x97\xE9\x63\x3F\x9D\x82\x2B\x74"
+        "\x67\x94\x8A\xD0";
+    size_t i;
+
+    message.value = msg;
+    message.length = sizeof(msg) - 1;
+    token.value = mic;
+    token.length = sizeof(mic) - 1;
+
+    major = gss_verify_mic(&minor, ctx, &message, &token, NULL);
+    check_gsserr("gss_verify_mic", major, minor);
+
+    for (i = 0; i < token.length; i++) {
+        mic[i]++;
+        major = gss_verify_mic(&minor, ctx, &message, &token, NULL);
+        if (major != GSS_S_DEFECTIVE_TOKEN && major != GSS_S_BAD_SIG)
+            abort();
+        mic[i]--;
+    }
+}
+
 /* Process wrap and MIC tokens with incomplete headers. */
 static void
 test_short_header(gss_ctx_id_t ctx)
@@ -598,6 +626,7 @@ main(int argc, char **argv)
     test_cfx_short_plaintext(ctx, cfx_subkey);
     test_cfx_large_ec(ctx, cfx_subkey);
     test_iov_large_asn1_wrapper(ctx);
+    test_cfx_verify_mic(ctx);
     free_fake_context(ctx);
 
     for (i = 0; i < sizeof(tests) / sizeof(*tests); i++) {
