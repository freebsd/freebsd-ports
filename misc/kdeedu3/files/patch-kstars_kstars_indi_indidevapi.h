--- kstars/kstars/indi/indidevapi.h	2004/03/29 17:55:49	1.1.2.2
+++ kstars/kstars/indi/indidevapi.h	2004/04/10 12:38:18	1.1.2.3
@@ -155,9 +155,9 @@ extern ISwitch *IUFindOnSwitch (const IS
 /* function to set all property switches off */
 extern void IUResetSwitches(const ISwitchVectorProperty *svp);
 
-extern int IUUpdateSwitches(const ISwitchVectorProperty *svp, ISState *states, char *names[], int n);
+extern int IUUpdateSwitches(ISwitchVectorProperty *svp, ISState *states, char *names[], int n);
 
-extern int IUUpdateNumbers(const INumberVectorProperty *nvp, double values[], char *names[], int n);
+extern int IUUpdateNumbers(INumberVectorProperty *nvp, double values[], char *names[], int n);
 
 /* function to reliably save new text in a IText */
 extern void IUSaveText (IText *tp, const char *newtext);
@@ -202,5 +202,5 @@ extern void ISNewSwitch (const char *dev
 #endif
 
 /* For RCS Only -- Do Not Edit
- * @(#) $RCSfile: indidevapi.h,v $ $Date: 2004/03/29 17:55:49 $ $Revision: 1.1.2.2 $ $Name:  $
+ * @(#) $RCSfile: indidevapi.h,v $ $Date: 2004/04/10 12:38:18 $ $Revision: 1.1.2.3 $ $Name:  $
  */
