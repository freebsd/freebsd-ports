--- scr.c.orig	1998-12-29 16:57:11 UTC
+++ scr.c
@@ -148,7 +148,7 @@ WINDOW VScreen;
 int BlackWhite = 0;
 int ColorMode = 1;
 int GraphMode = 1;
-int TtyUpperCase = 0;
+extern int TtyUpperCase;
 
 static WINDOW curscr;
 static scrool, rscrool;
@@ -167,7 +167,7 @@ static char *KS, *KE;
 
 static char *CL, *CM, *SE, *SO, *TE, *TI, *VE, *VS,
 	*AL, *DL, *IS, *IF, *FS, *MD, *MH, *ME, *MR,
-	*CF, *CB, *AF, *AB, *Sf, *Sb, *MF, *MB;
+	*CF, *CB, *AF, *AB, *Sf, *Sb, *MF, *MB, *OP;
 static NF, NB;
 static char MS, C2;
 
@@ -231,6 +231,7 @@ struct CapTab outtab [] = {
 	{ "Cs", CAPSTR, 0, 0, 0, &Cs, },
 	{ "Ce", CAPSTR, 0, 0, 0, &Ce, },
 	{ "Ct", CAPSTR, 0, 0, 0, &Ct, },
+	{ "op", CAPSTR, 0, 0, 0, &OP, },
 	{ { 0, 0, }, 0, 0, 0, 0, 0, },
 };
 
@@ -413,6 +414,8 @@ void VClose ()
 		tputs (TE);
 	if (KE)
 		tputs (KE);
+	if (OP)
+		tputs (OP);
 	VFlush ();
 	TtyReset ();
 }
@@ -425,6 +428,8 @@ void VRestore ()
 		tputs (VE);
 	if (KE)
 		tputs (KE);
+	if (OP)
+		tputs (OP);
 	VFlush ();
 	TtyReset ();
 }
