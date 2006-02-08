--- plugins/fn-financial/functions.c-	Mon Feb  6 13:36:33 2006
+++ plugins/fn-financial/functions.c	Mon Feb  6 13:38:17 2006
@@ -1736,13 +1736,14 @@
 	gnm_float pmt  = value_get_as_float (argv[2]);
 	gnm_float fv   = argv[3] ? value_get_as_float (argv[3]) : 0;
 	int type       = value_get_paytype (argv[4]);
+	gnm_float pvif, fvifa;
 
 	if (!is_valid_paytype (type))
 		return value_new_error_VALUE (ei->pos);
 
 	/* Calculate the PVIF and FVIFA */
-	gnm_float pvif  = calculate_pvif (rate, nper);
-	gnm_float fvifa = calculate_fvifa (rate, nper);
+	pvif  = calculate_pvif (rate, nper);
+	fvifa = calculate_fvifa (rate, nper);
 
 	if (pvif == 0)
 	        return value_new_error_DIV0 (ei->pos);
@@ -2007,12 +2008,13 @@
 	gnm_float pmt  = value_get_as_float (argv[2]);
 	gnm_float pv   = argv[3] ? value_get_as_float (argv[3]) : 0.;
 	int type       = value_get_paytype (argv[4]);
+	gnm_float pvif, fvifa;
 
 	if (!is_valid_paytype (type))
 		return value_new_error_VALUE (ei->pos);
 
-	gnm_float pvif  = calculate_pvif (rate, nper);
-	gnm_float fvifa = calculate_fvifa (rate, nper);
+	pvif  = calculate_pvif (rate, nper);
+	fvifa = calculate_fvifa (rate, nper);
 
         return value_new_float (-((pv * pvif) + pmt *
 				  (1.0 + rate * type) * fvifa));
