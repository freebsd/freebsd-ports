--- import/src/impkimmo.l.orig	Tue Jul 14 01:23:53 1998
+++ import/src/impkimmo.l	Thu Oct 30 18:23:07 2003
@@ -123,8 +123,8 @@
 " "vform:" "*EN	return VFORM_EN;
 " "vform:" "*ING	return VFORM_ING;
 " "vform:" "*BASE  return VFORM_BASE;
-" "finite:" "*\+	return FINITE_PLUS;
-" "finite:" "*-	return FINITE_MINUS;
+" "my_finite:" "*\+	return FINITE_PLUS;
+" "my_finite:" "*-	return FINITE_MINUS;
 " "aform:" "*ABS	return AFORM_ABS;
 " "aform:" "*COMP	return AFORM_COMP;
 " "aform:" "*SUPER	return AFORM_SUPER;
@@ -158,7 +158,7 @@
 MTCstring proper;
 MTCstring tense; 
 MTCstring vform;
-MTCstring finite;
+MTCstring my_finite;
 MTCstring aform;
 MTCstring verbal; 
 MTCstring Case;
@@ -318,11 +318,11 @@
 			break;
 		case FINITE_PLUS:
 			defined=TRUE;
-			finite="Fin+";
+			my_finite="Fin+";
 			break;
 		case FINITE_MINUS:
 			defined=TRUE;
-			finite="Fin-";
+			my_finite="Fin-";
 			break;
 		case AFORM_ABS:
 			defined=TRUE;
@@ -430,7 +430,7 @@
 	proper=NULL;
 	tense=NULL;
 	vform=NULL;
-	finite=NULL;
+	my_finite=NULL;
 	aform=NULL;
 	verbal=NULL;
 	Case=NULL;
@@ -459,7 +459,7 @@
 		temp+=proper;
 		temp+=tense;
 		temp+=vform;
-		temp+=finite;
+		temp+=my_finite;
 		temp+=aform;
 		temp+=verbal;
 		temp+=Case;
