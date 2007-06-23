--- charts1.c.bak	1998-12-23 23:29:26.000000000 +0300
+++ charts1.c	2007-06-23 16:28:33.000000000 +0400
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
 
