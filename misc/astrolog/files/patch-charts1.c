--- charts1.c.orig	1998-12-23 23:29:14.000000000 +0300
+++ charts1.c	2012-02-25 19:40:41.000000000 +0400
@@ -53,7 +53,7 @@
   char sz[cchSzDef];
   int day, fNam, fLoc;
 
-  fNam = *ciMain.nam > chNull; fLoc = *ciMain.loc > chNull;
+  fNam = *ciMain.nam != chNull; fLoc = *ciMain.loc != chNull;
   AnsiColor(kWhite);
   sprintf(sz, "%s %s chart ", szAppName, szVersionCore); PrintSz(sz);
   if (fNoTimeOrSpace)
@@ -83,7 +83,7 @@
   real rT;
 
   CreateElemTable(&et);
-  fNam = *ciMain.nam > chNull; fLoc = *ciMain.loc > chNull;
+  fNam = *ciMain.nam != chNull; fLoc = *ciMain.loc != chNull;
 
   PrintHeader();    /* Show time and date of the chart being displayed. */
 
@@ -493,7 +493,7 @@
   case 5:
     nT = us.fEuroTime; us.fEuroTime = fTrue;
     sprintf(szT, "%s", SzTim(DegToDec(DFromR(is.RA)*(24.0/rDegMax))));
-    sprintf(sz, "UT: %s, Sid.T: %s", SzTim(Tim+Zon-Dst), szT);
+    sprintf(sz, "UT: %s, Sid.T: %s", SzTim(DegToDec(DecToDeg(Tim)+DecToDeg(Zon-Dst))), szT);
     us.fEuroTime = nT;
     break;
   case 6:
