--- charts1.c.orig	2002-04-27 22:32:58.000000000 +0400
+++ charts1.c	2012-02-26 10:14:28.000000000 +0400
@@ -66,7 +66,7 @@
     ciMain = ciCore;
   }
 
-  fNam = *ciMain.nam > chNull; fLoc = *ciMain.loc > chNull;
+  fNam = *ciMain.nam != chNull; fLoc = *ciMain.loc != chNull;
   AnsiColor(kWhite);
   if (us.nRel == rcDual) {
     sprintf(sz, "%s %s  dual chart ", szAppName, szVersionCore); PrintSz(sz);
@@ -92,8 +92,12 @@
     if (us.nRel == rcMidpoint) {
     sprintf(sz, " %s\n", SzLocation(Lon, Lat)); PrintSz(sz);
     } else {
-      sprintf(sz, "%c%s%s%s\n", fLoc && !fNam ? '\n' : ' ', ciMain.loc,
-        fLoc ? " " : "", SzLocation(Lon, Lat)); PrintSz(sz);
+      if (fLoc)
+	sprintf(sz, "\n%s %s\n", ciMain.loc, SzLocation(Lon, Lat));
+      else
+	sprintf(sz, "%c%s%s%s\n", fLoc && !fNam ? '\n' : ' ', ciMain.loc,
+	  fLoc ? " " : "", SzLocation(Lon, Lat));
+      PrintSz(sz);
     }
   }
   if (us.fHorizon) {
@@ -157,8 +161,12 @@
     sprintf(sz, "%c%c%c %s %s (%cT %s GMT)", chDay3(day),
       SzDate(Mon, Day, Yea, 3), SzTim(Tim), ChDst(Dst),
       SzZone(Zon)); PrintSz(sz);
-    sprintf(sz, "%c%s%s%s\n", fLoc && !fNam ? '\n' : ' ', ciMain.loc,
-      fLoc ? " " : "", SzLocation(Lon, Lat)); PrintSz(sz);
+    if (fLoc)
+      sprintf(sz, "\n%s %s\n", ciMain.loc, SzLocation(Lon, Lat));
+    else
+      sprintf(sz, "%c%s%s%s\n", fLoc && !fNam ? '\n' : ' ', ciMain.loc,
+	fLoc ? " " : "", SzLocation(Lon, Lat));
+    PrintSz(sz);
     ciMain = ciT;
   }
 }
@@ -464,7 +472,7 @@
   sprintf(sz, "%c%c%c: ", chObj3(i3)); PrintSz(sz);
   PrintZodiac(planet[i3]);
   if (ac == acGC || ac == acC || ac == acMR || ac == acK) {
-    PrintSz(" to ");
+    sprintf(sz, "\n%-11s to ", " "); PrintSz(sz);
     AnsiColor(kObjA[i4]);
     sprintf(sz, "%c%c%c: ", chObj3(i4)); PrintSz(sz);
     PrintZodiac(planet[i4]);
@@ -610,7 +618,7 @@
 void PrintWheelCenter(irow)
 int irow;
 {
-  byte sz[cchSzDef], szT[8];
+  byte sz[cchSzDef], szT[9];
   int cch, nT;
 
   if (*ciMain.nam == chNull && *ciMain.loc == chNull)    /* Try to center */
@@ -635,25 +643,26 @@
     sprintf(sz, "%s", ciMain.loc);
     break;
   case 4:
-    nT = (int)(RFract(RAbs(Zon))*100.0+rRound);
-    sprintf(sz, "%cT %c%02d:%02d, %s", ChDst(Dst),
-      Zon > 0.0 ? '-' : '+', (int)RAbs(Zon), nT, SzLocation(Lon, Lat));
+    sprintf(sz, "%cT %s GMT", ChDst(Dst), SzZone(Zon));
     break;
   case 5:
+    sprintf(sz, "%s", SzLocation(Lon, Lat));
+    break;
+  case 6:
     nT = us.fEuroTime; us.fEuroTime = fTrue;
     sprintf(szT, "%s", SzTim(DegToDec(DFromR(is.RA)*(24.0/rDegMax))));
-    sprintf(sz, "UT: %s, Sid.T: %s", SzTim(Tim+Zon-Dst), szT);
+    sprintf(sz, "UT: %s, Sid.T: %s", SzTim(DegToDec(DecToDeg(Tim)+DecToDeg(Zon-Dst))), szT);
     us.fEuroTime = nT;
     break;
-  case 6:
+  case 7:
     sprintf(sz, "%s Houses", szSystem[us.nHouseSystem]);
     break;
-  case 7:
+  case 8:
     sprintf(sz, "%s / %s", us.fSidereal ? "Sidereal" : "Tropical",
       us.objCenter == oSun ? "Heliocentric" :
       (us.objCenter == oEar ? "Geocentric" : szObjName[us.objCenter]));
     break;
-  case 8:
+  case 9:
     sprintf(sz, "Julian Day = %12.4f", JulianDayFromTime(is.T));
     break;
   default:
@@ -849,6 +858,7 @@
     sprintf(sz, "%c%c%c:%3d", chObj3(i), co[i]); PrintSz(sz);
     j++;
   }
+  AnsiColor(kDefault);
   PrintL();
 }
 
