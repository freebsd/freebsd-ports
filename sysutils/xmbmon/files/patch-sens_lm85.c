$FreeBSD$

--- sens_lm85.c	Mon Oct 13 10:12:58 2003
+++ sens_lm85.c	Wed Dec 21 15:37:56 2005
@@ -53,7 +53,6 @@
 #define ADM_24FAN(nr)	(0x28 + (nr))
 #define ADM_24FANDIV	0x47
 #define ADM_24MODE		0x16
-#define ADM_TEMPOFF(nr)	(0x70 + (nr))
 #define ADM_EXTRES1		0x76
 #define ADM_EXTRES2		0x77
 #define ADM_FANPPR		0x7B
@@ -213,7 +212,7 @@
 static	float	lm85_temp( LM_METHODS *method, int no )
 {
 	int n, ne;
-	float ext = 0.0, offset = 0.0;
+	float ext = 0.0;
 
 	if (no < 0 || 2 < no)
 		return 0xFFFF;
@@ -226,18 +225,20 @@
 	} else if (lm85chipid >= ADM1027) {
 		ne = method->Read(ADM_EXTRES2);	
 		ext = 0.25 * ((ne >> ((no + 1) * 2)) & 0x03);
-		n = method->Read(ADM_TEMPOFF(no));
-		if (n > 0x80)
-			n -= 0xFF;
-		offset = (float) n;
+		/* Unlock temperature registers. */
+		if (no != 0) method->Read(LM85_TEMP(0));
+		if (no != 1) method->Read(LM85_TEMP(1));
+		if (no != 2) method->Read(LM85_TEMP(2));
+		/* Unlock voltage register. */
+		method->Read(LM85_VOLT(4));
 	}
 	n = method->Read(LM85_TEMP(no));
 	if (n == 0x80)
 		return 0xFFFF;
 	else if (n > 0x80)
-		return (float) (n - 0xFF) + ext - offset;
+		return (float) (n - 0xFF) + ext;
 	else
-		return (float) n + ext - offset;
+		return (float) n + ext;
 }
 
 
@@ -262,10 +263,20 @@
 		return 0xFFFF;
 
 	if (lm85chipid >= ADM1027) {
-		if (no == 4)
+		if (no == 4) {
 			ne = method->Read(ADM_EXTRES2) & 0x03;
-		else
+			/* Unlock temperature registers. */
+			method->Read(LM85_TEMP(0));
+			method->Read(LM85_TEMP(1));
+			method->Read(LM85_TEMP(2));
+		} else {
 			ne = (method->Read(ADM_EXTRES1) >> (no * 2)) & 0x03;
+			/* Unlock voltage registers. */
+			if (no != 0) method->Read(LM85_VOLT(0));
+			if (no != 1) method->Read(LM85_VOLT(1));
+			if (no != 2) method->Read(LM85_VOLT(2));
+			if (no != 3) method->Read(LM85_VOLT(3));
+		}
 	}
 	n = method->Read(LM85_VOLT(no));
 	if (lm85chipid >= ADM1027)
