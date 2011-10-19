--- BatteryModel.m.orig	2011-07-15 11:05:22.000000000 +0200
+++ BatteryModel.m	2011-10-19 20:45:35.000000000 +0200
@@ -246,7 +246,11 @@
     if( battio.bst.state & ACPI_BATT_STAT_CRITICAL )
       batteryType = @"CRITICAL ";		// could be complementary!
     
+#ifdef ACPI_BATT_STAT_BST_MASK
+    if( battio.bst.state & ACPI_BATT_STAT_BST_MASK )
+#else
     if( battio.bst.state & ACPI_BATT_STAT_MAX )
+#endif
       status = @"Charged";
     if( battio.bst.state & ACPI_BATT_STAT_CHARGING )
       status = @"Charging";
