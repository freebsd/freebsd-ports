--- kstars/kstars/indi/indidrivermain.c	2004/03/29 17:55:49	1.2.2.3
+++ kstars/kstars/indi/indidrivermain.c	2004/04/10 12:38:18	1.2.2.4
@@ -546,7 +546,7 @@ IUResetSwitches(const ISwitchVectorPrope
 
 /* Update property switches in accord with states and names. */
 int 
-IUUpdateSwitches(const ISwitchVectorProperty *svp, ISState *states, char *names[], int n)
+IUUpdateSwitches(ISwitchVectorProperty *svp, ISState *states, char *names[], int n)
 {
  int i=0;
  
@@ -571,7 +571,7 @@ IUUpdateSwitches(const ISwitchVectorProp
 }
 
 /* Update property numbers in accord with values and names */
-int IUUpdateNumbers(const INumberVectorProperty *nvp, double values[], char *names[], int n)
+int IUUpdateNumbers(INumberVectorProperty *nvp, double values[], char *names[], int n)
 {
   int i=0;
   
@@ -926,4 +926,4 @@ timestamp()
 }
 
 /* For RCS Only -- Do Not Edit */
-static char *rcsid[2] = {(char *)rcsid, "@(#) $RCSfile: indidrivermain.c,v $ $Date: 2004/03/29 17:55:49 $ $Revision: 1.2.2.3 $ $Name:  $"};
+static char *rcsid[2] = {(char *)rcsid, "@(#) $RCSfile: indidrivermain.c,v $ $Date: 2004/04/10 12:38:18 $ $Revision: 1.2.2.4 $ $Name:  $"};
