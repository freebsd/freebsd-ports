--- sens_winbond.c.orig	Sat Jul  5 07:56:47 2003
+++ sens_winbond.c	Sun Oct 12 20:17:01 2003
@@ -86,6 +86,7 @@
 #define	WINBD_FANDIV	0x47
 #define	WINBD_REGPIN	0x4B
 #define	ASUSM_FANDIV	0xA1
+#define	ANADM_TEMPCFG	0x4B
 
 #define WINBD_DIOSEL	0x59
 #define WINBD_VMCTRL	0x5D
@@ -299,6 +300,12 @@
 		goto ret1;
 	}
 
+	if (wbdchipid == ADM9240) {
+		temp1_flag = temp2_flag = 1;	/* disable! */
+		method->Write(WINBD_CONFIG, 0x01);	/* init. chip */
+		goto ret1;
+	}
+
 	if (method == &method_isa && wbdchipid >= LM78) {
 		temp1_flag = temp2_flag = 1;	/* disable! */
 		goto ret1;
@@ -364,9 +371,15 @@
 		(wbdchipid == W83783S || wbdchipid == W83697HF || wbdchipid == ASM58))
 		return 0xFFFF;
 
-	if (no == 0)
-		return (float) method->Read(WINBD_TEMP0);
-	else if (no == 1) {
+	if (no == 0) {
+		f = (float) method->Read(WINBD_TEMP0);
+		if (wbdchipid == ADM9240) {
+			n = method->Read(ANADM_TEMPCFG);
+			if (n & 0x80)
+				f += 0.5;
+		}
+		return f;
+	} else if (no == 1) {
 		if (wbdchipid == ASB100) 
 			return (float) method->Read(ASUSB_TEMP4);
 		if (wbdchipid == ASM58) 
@@ -518,5 +531,5 @@
 		return 0xFFFF;
 	}
 
-	return 1350000 / (r * (1 << div[no]));
+	return 22500 * 60 / (r * (1 << div[no]));
 }
