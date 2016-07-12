--- drivers/power/axp818.c.orig	2016-04-12 02:22:25 UTC
+++ drivers/power/axp818.c
@@ -225,6 +225,21 @@ int axp_set_fldo(int fldo_num, unsigned 
 				AXP818_OUTPUT_CTRL3_FLDO1_EN << (fldo_num - 1));
 }
 
+int
+axp_set_dc1sw(int onoff)
+{
+	int ret;
+
+	if (onoff)
+		ret = pmic_bus_setbits(AXP818_OUTPUT_CTRL2,
+				       AXP818_OUTPUT_CTRL2_DC1SW_EN);
+	else
+		ret = pmic_bus_clrbits(AXP818_OUTPUT_CTRL2,
+				       AXP818_OUTPUT_CTRL2_DC1SW_EN);
+
+	return ret;
+}
+
 int axp_init(void)
 {
 	u8 axp_chip_id;
