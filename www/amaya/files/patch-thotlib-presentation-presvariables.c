--- ../thotlib/presentation/presvariables.c.orig	2008-01-26 12:35:12.000000000 +0100
+++ ../thotlib/presentation/presvariables.c	2008-01-26 12:35:37.000000000 +0100
@@ -1278,7 +1278,7 @@
           /* date en anglais */
           pt = &tod;
           *pt = time (NULL);
-          ptm = localtime (pt);
+          ptm = localtime ((const time_t *)pt);
           GetCounterValue (ptm->tm_year, CntDecimal, number, &l);
           CopyStringToBuffer ((unsigned char *)number, pAb->AbText, &l);
           pAb->AbVolume += l;
@@ -1298,7 +1298,7 @@
           /* date en francais */
           pt = &tod;
           *pt = time (NULL);
-          ptm = localtime (pt);
+          ptm = localtime ((const time_t *)pt);
           GetCounterValue (ptm->tm_mday, CntDecimal, number, &l);
           CopyStringToBuffer ((unsigned char *)number, pAb->AbText, &l);
           pAb->AbVolume += l;
