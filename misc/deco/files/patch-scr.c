Index: scr.c
@@ -167,7 +167,7 @@
 
 static char *CL, *CM, *SE, *SO, *TE, *TI, *VE, *VS,
 	*AL, *DL, *IS, *IF, *FS, *MD, *MH, *ME, *MR,
-	*CF, *CB, *AF, *AB, *Sf, *Sb, *MF, *MB;
+	*CF, *CB, *AF, *AB, *Sf, *Sb, *MF, *MB, *OP;
 static NF, NB;
 static char MS, C2;
 
@@ -231,6 +231,7 @@
 	{ "Cs", CAPSTR, 0, 0, 0, &Cs, },
 	{ "Ce", CAPSTR, 0, 0, 0, &Ce, },
 	{ "Ct", CAPSTR, 0, 0, 0, &Ct, },
+	{ "op", CAPSTR, 0, 0, 0, &OP, },
 	{ { 0, 0, }, 0, 0, 0, 0, 0, },
 };
 
@@ -413,6 +414,8 @@
 		tputs (TE);
 	if (KE)
 		tputs (KE);
+	if (OP)
+		tputs (OP);
 	VFlush ();
 	TtyReset ();
 }
@@ -425,6 +428,8 @@
 		tputs (VE);
 	if (KE)
 		tputs (KE);
+	if (OP)
+		tputs (OP);
 	VFlush ();
 	TtyReset ();
 }
