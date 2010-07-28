--- ./lib/ipmi_sdr.c.orig	2009-02-25 15:38:52.000000000 -0500
+++ ./lib/ipmi_sdr.c	2010-07-23 14:46:07.000000000 -0400
@@ -775,7 +775,7 @@
 /* helper macro for printing sensor thresholds */
 #define SENSOR_PRINT_THRESH(NAME, READ, FLAG)			\
 	if (sensor->sensor.init.thresholds &&			\
-	    sensor->mask.type.threshold.read.FLAG != 0) {	\
+	    sensor->mask.type.threshold.type.read.FLAG != 0) {	\
 		printf(" %-21s : ", NAME);			\
 		printf("%.3f\n", sdr_convert_sensor_reading(	\
 			     sensor, sensor->threshold.READ));	\
@@ -1247,17 +1247,17 @@
 					 sensor->normal_min);
 			SENSOR_PRINT_CSV(sensor->analog_flag.normal_max,
 					 sensor->normal_max);
-			SENSOR_PRINT_CSV(sensor->mask.type.threshold.read.unr,
+			SENSOR_PRINT_CSV(sensor->mask.type.threshold.type.read.unr,
 					 sensor->threshold.upper.non_recover);
-			SENSOR_PRINT_CSV(sensor->mask.type.threshold.read.ucr,
+			SENSOR_PRINT_CSV(sensor->mask.type.threshold.type.read.ucr,
 					 sensor->threshold.upper.critical);
-			SENSOR_PRINT_CSV(sensor->mask.type.threshold.read.unc,
+			SENSOR_PRINT_CSV(sensor->mask.type.threshold.type.read.unc,
 					 sensor->threshold.upper.non_critical);
-			SENSOR_PRINT_CSV(sensor->mask.type.threshold.read.lnr,
+			SENSOR_PRINT_CSV(sensor->mask.type.threshold.type.read.lnr,
 					 sensor->threshold.lower.non_recover);
-			SENSOR_PRINT_CSV(sensor->mask.type.threshold.read.lcr,
+			SENSOR_PRINT_CSV(sensor->mask.type.threshold.type.read.lcr,
 					 sensor->threshold.lower.critical);
-			SENSOR_PRINT_CSV(sensor->mask.type.threshold.read.lnc,
+			SENSOR_PRINT_CSV(sensor->mask.type.threshold.type.read.lnc,
 					 sensor->threshold.lower.non_critical);
 
 			printf("%.3f,%.3f",
@@ -1485,17 +1485,17 @@
 		break;
 	case 1:		/* readable according to mask */
 	case 2:		/* readable and settable according to mask */
-		if (sensor->mask.type.threshold.read.lnr)
+		if (sensor->mask.type.threshold.type.read.lnr)
 			printf("lnr ");
-		if (sensor->mask.type.threshold.read.lcr)
+		if (sensor->mask.type.threshold.type.read.lcr)
 			printf("lcr ");
-		if (sensor->mask.type.threshold.read.lnc)
+		if (sensor->mask.type.threshold.type.read.lnc)
 			printf("lnc ");
-		if (sensor->mask.type.threshold.read.unc)
+		if (sensor->mask.type.threshold.type.read.unc)
 			printf("unc ");
-		if (sensor->mask.type.threshold.read.ucr)
+		if (sensor->mask.type.threshold.type.read.ucr)
 			printf("ucr ");
-		if (sensor->mask.type.threshold.read.unr)
+		if (sensor->mask.type.threshold.type.read.unr)
 			printf("unr ");
 		printf("\n");
 		break;
@@ -1511,17 +1511,17 @@
 		break;
 	case 1:		/* readable according to mask */
 	case 2:		/* readable and settable according to mask */
-		if (sensor->mask.type.threshold.set.lnr)
+		if (sensor->mask.type.threshold.type.set.lnr)
 			printf("lnr ");
-		if (sensor->mask.type.threshold.set.lcr)
+		if (sensor->mask.type.threshold.type.set.lcr)
 			printf("lcr ");
-		if (sensor->mask.type.threshold.set.lnc)
+		if (sensor->mask.type.threshold.type.set.lnc)
 			printf("lnc ");
-		if (sensor->mask.type.threshold.set.unc)
+		if (sensor->mask.type.threshold.type.set.unc)
 			printf("unc ");
-		if (sensor->mask.type.threshold.set.ucr)
+		if (sensor->mask.type.threshold.type.set.ucr)
 			printf("ucr ");
-		if (sensor->mask.type.threshold.set.unr)
+		if (sensor->mask.type.threshold.type.set.unr)
 			printf("unr ");
 		printf("\n");
 		break;
