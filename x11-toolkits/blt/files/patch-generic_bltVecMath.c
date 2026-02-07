--- generic/bltVecMath.c.orig	2013-10-30 11:53:29.000000000 +0100
+++ generic/bltVecMath.c	2013-10-30 11:54:56.000000000 +0100
@@ -834,20 +834,20 @@
     if ((errno == EDOM) || (value != value)) {
 	Tcl_AppendResult(interp, "domain error: argument not in valid range",
 	    (char *)NULL);
-	Tcl_SetErrorCode(interp, "ARITH", "DOMAIN", interp->result,
+	Tcl_SetErrorCode(interp, "ARITH", "DOMAIN", Tcl_GetStringResult(interp),
 	    (char *)NULL);
     } else if ((errno == ERANGE) || IS_INF(value)) {
 	if (value == 0.0) {
 	    Tcl_AppendResult(interp, 
 			     "floating-point value too small to represent",
 		(char *)NULL);
-	    Tcl_SetErrorCode(interp, "ARITH", "UNDERFLOW", interp->result,
+	    Tcl_SetErrorCode(interp, "ARITH", "UNDERFLOW", Tcl_GetStringResult(interp),
 		(char *)NULL);
 	} else {
 	    Tcl_AppendResult(interp, 
 			     "floating-point value too large to represent",
 		(char *)NULL);
-	    Tcl_SetErrorCode(interp, "ARITH", "OVERFLOW", interp->result,
+	    Tcl_SetErrorCode(interp, "ARITH", "OVERFLOW", Tcl_GetStringResult(interp),
 		(char *)NULL);
 	}
     } else {
@@ -856,7 +856,7 @@
 	sprintf(buf, "%d", errno);
 	Tcl_AppendResult(interp, "unknown floating-point error, ",
 	    "errno = ", buf, (char *)NULL);
-	Tcl_SetErrorCode(interp, "ARITH", "UNKNOWN", interp->result,
+	Tcl_SetErrorCode(interp, "ARITH", "UNKNOWN", Tcl_GetStringResult(interp),
 	    (char *)NULL);
     }
 }
