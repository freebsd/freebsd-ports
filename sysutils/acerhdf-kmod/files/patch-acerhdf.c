--- acerhdf.c.orig	2022-05-17 23:02:21 UTC
+++ acerhdf.c
@@ -246,8 +246,6 @@ struct acerhdf_softc {
     struct sysctl_oid *sysctl_tree;
 };
 
-static devclass_t acerhdf_devclass;
-
 ACPI_SERIAL_DECL(acerhdf, "Acer Aspire One fan control");
 
 static const struct bios_settings *bios_cfg = NULL;
@@ -740,5 +738,11 @@ static driver_t acerhdf_driver = {
     sizeof(struct acerhdf_softc),
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(acerhdf, acpi, acerhdf_driver, 0, 0);
+#else
+static devclass_t acerhdf_devclass;
+
 DRIVER_MODULE(acerhdf, acpi, acerhdf_driver, acerhdf_devclass, 0, 0);
+#endif
 MODULE_DEPEND(acerhdf, acpi, 1, 1, 1);
