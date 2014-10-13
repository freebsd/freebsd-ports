--- test/wacom-tests.c~
+++ test/wacom-tests.c
@@ -184,7 +184,7 @@ test_normalize_pressure(void)
 
 	priv.common = &common;
 	priv.pInfo = &pInfo;
-	pInfo.name = strdupa("Wacom test device");
+	pInfo.name = strdup("Wacom test device");
 	common.wcmPressureRecalibration = 1;
 
 	priv.minPressure = 0;
@@ -229,6 +229,7 @@ test_normalize_pressure(void)
 		/* we count up, so assume normalised pressure goes up too */
 		assert(prev_pressure == pressure);
 	}
+	free(pInfo.name);
 }
 
 /**
