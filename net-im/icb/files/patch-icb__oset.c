--- icb/oset.c.orig	2000-12-15 12:21:03.000000000 +0900
+++ icb/oset.c	2012-10-25 18:15:16.000000000 +0900
@@ -61,7 +61,7 @@
 
 
 void
-restrict(void)
+icb_restrict(void)
 {
 	gv.restricted = 1;
 	tclrestrict();
@@ -91,7 +91,7 @@
 		if (gv.restricted)
 			TRETURNERR("oset: restricted mode can't be reset")
 		else {
-			restrict();
+			icb_restrict();
 			return(TCL_OK);
 		}
 	}
@@ -109,7 +109,7 @@
 	}
 
 	if (vars[x].name == NULL) {
-		sprintf(TRET, "oset: no such variable \"%s\"", argv[1]);
+		sprintf(Tcl_GetStringResult(interp), "oset: no such variable \"%s\"", argv[1]);
 		return(TCL_ERROR);
 	}
 
@@ -278,7 +278,7 @@
 	}
 
 	if (vars[x].name == NULL) {
-		sprintf(TRET, "ounset: no such variable \"%s\"", argv[1]);
+		sprintf(Tcl_GetStringResult(interp), "ounset: no such variable \"%s\"", argv[1]);
 		return(TCL_ERROR);
 	}
 
@@ -310,7 +310,7 @@
 	case V_NONNEG:
 		tmp = atoi(s);
 		if (tmp < 0) {
-			strcpy(TRET, "oset: only non-negative values allowed");
+			strcpy(Tcl_GetStringResult(interp), "oset: only non-negative values allowed");
 			return(-1);
 		}
 		memcpy (address, &tmp, sizeof(int));
@@ -331,14 +331,14 @@
 			*i_addr = (int)0;
 			}
 		else {
-			strcpy(TRET, "oset: only boolean values allowed");
+			strcpy(Tcl_GetStringResult(interp), "oset: only boolean values allowed");
 			return(-1);
 		}
 		break;
 	case V_STRING:
 		tmp = strlen(s) + 1;
 		if ((p = malloc(tmp)) == NULL) {
-			strcpy(TRET, "oset: not enough memory to set string");
+			strcpy(Tcl_GetStringResult(interp), "oset: not enough memory to set string");
 			return(-1);
 		}
 		memcpy (p, s, tmp);
