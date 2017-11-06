# Use fabs for doubles
# Cast away a couple type warnings as done elsewhere
#
--- src/mga_dacG.c.orig	2017-01-17 22:40:29 UTC
+++ src/mga_dacG.c
@@ -940,8 +940,8 @@ MGAGCalcClock ( ScrnInfoPtr pScrn, long 
 			/*
 			 * Pick the closest frequency.
 			 */
-			if ( abs(calc_f - f_vco) < m_err ) {
-				m_err = abs(calc_f - f_vco);
+			if ( fabs(calc_f - f_vco) < m_err ) {
+				m_err = fabs(calc_f - f_vco);
 				*best_m = m;
 				*best_n = n;
 			}
@@ -2124,12 +2124,12 @@ mgag_create_i2c_bus(const char *name, un
     I2CBusPtr I2CPtr = xf86CreateI2CBusRec();
 
     if (I2CPtr != NULL) {
-	I2CPtr->BusName = name;
+	I2CPtr->BusName = (char *)name;
 	I2CPtr->scrnIndex = scrn_index;
 	I2CPtr->I2CPutBits = MGAG_I2CPutBits;
 	I2CPtr->I2CGetBits = MGAG_I2CGetBits;
 	I2CPtr->AcknTimeout = 5;
-	I2CPtr->DriverPrivate.ptr = & i2c_priv[bus_index];
+	I2CPtr->DriverPrivate.ptr = (void *)&i2c_priv[bus_index];
 
 	if (!xf86I2CBusInit(I2CPtr)) {
 	    xf86DestroyI2CBusRec(I2CPtr, TRUE, TRUE);
