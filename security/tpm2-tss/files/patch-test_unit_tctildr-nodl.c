--- test/unit/tctildr-nodl.c.orig	2024-05-17 08:04:10 UTC
+++ test/unit/tctildr-nodl.c
@@ -68,9 +68,11 @@ test_tctildr_get_default_all_fail (void **state)
     /* device:/dev/tpm0 */
     will_return (__wrap_tcti_from_init, tcti_ctx);
     will_return (__wrap_tcti_from_init, TEST_RC);
+#if !defined (__FreeBSD__)
     /* device:/dev/tpmrm0 */
     will_return (__wrap_tcti_from_init, tcti_ctx);
     will_return (__wrap_tcti_from_init, TEST_RC);
+#endif
     /* swtpm */
     will_return (__wrap_tcti_from_init, tcti_ctx);
     will_return (__wrap_tcti_from_init, TEST_RC);
