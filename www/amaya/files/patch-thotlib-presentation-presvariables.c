--- ../thotlib/presentation/presvariables.c.orig	Tue Jun  7 10:37:13 2005
+++ ../thotlib/presentation/presvariables.c	Sat Aug 13 10:24:34 2005
@@ -1263,7 +1263,7 @@
 	    /* date en anglais */
 	    pt = &tod;
 	    *pt = time (NULL);
-	    ptm = localtime (pt);
+	    ptm = localtime ((const time_t *)pt);
 	    GetCounterValue (ptm->tm_year, CntDecimal, number, &l);
 	    CopyStringToBuffer ((unsigned char *)number, pAb->AbText, &l);
 	    pAb->AbVolume += l;
@@ -1283,7 +1283,7 @@
 	    /* date en francais */
 	    pt = &tod;
 	    *pt = time (NULL);
-	    ptm = localtime (pt);
+	    ptm = localtime ((const time_t *)pt);
 	    GetCounterValue (ptm->tm_mday, CntDecimal, number, &l);
 	    CopyStringToBuffer ((unsigned char *)number, pAb->AbText, &l);
 	    pAb->AbVolume += l;
