Fix USB testscase for platforms without HAVE_UDEV

This uses the same FWUPD_SELF_TEST guard that to skip enumeration
as the other self tests do.
--- src/fu-usb-backend-test.c.orig	2026-10-23 13:27:58 UTC
+++ src/fu-usb-backend-test.c
@@ -243,6 +243,7 @@ main(int argc, char **argv)
 main(int argc, char **argv)
 {
 	(void)g_setenv("G_TEST_SRCDIR", SRCDIR, FALSE);
+	(void)g_setenv("FWUPD_SELF_TEST", "1", TRUE);
 	g_test_init(&argc, &argv, NULL);
 	g_test_add_func("/fwupd/usb-backend", fu_usb_backend_func);
 	g_test_add_func("/fwupd/usb-backend/invalid", fu_usb_backend_invalid_func);
