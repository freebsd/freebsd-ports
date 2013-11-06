--- generic/mpexpr.c.orig	2013-11-06 15:23:00.000000000 +0100
+++ generic/mpexpr.c	2013-11-06 15:29:26.000000000 +0100
@@ -1242,7 +1242,7 @@
 	     */
 
 	    default:
-		interp->result = "unknown operator in expression";
+		Tcl_SetObjResult(interp, Tcl_NewStringObj("unknown operator in expression", -1));
 		result = TCL_ERROR;
 		goto done;
 	}
@@ -1272,9 +1272,8 @@
 
 		    if (ziszero(value2.intValue)) {
 			divideByZero:
-			interp->result = "divide by zero";
-			Tcl_SetErrorCode(interp, "ARITH", "DIVZERO",
-				interp->result, (char *) NULL);
+			Tcl_SetObjResult(interp, Tcl_NewStringObj("divide by zero", -1));
+			Tcl_SetErrorCode(interp, "ARITH", "DIVZERO", "divide by zero", (char *) NULL);
 			result = TCL_ERROR;
 			goto done;
 		    }
@@ -1637,7 +1636,7 @@
 		break;
 
 	    case COLON:
-		interp->result = "can't have : operator without ? first";
+		Tcl_SetObjResult(interp, Tcl_NewStringObj("can't have : operator without ? first", -1));
 		result = TCL_ERROR;
 		goto done;
 	}
@@ -1930,8 +1929,7 @@
 	    ckfree(math_io);
 	} else {
 	    if (value.pv.buffer != value.staticSpace) {
-		interp->result = value.pv.buffer;
-		interp->freeProc = TCL_DYNAMIC;
+		Tcl_SetResult(interp, value.pv.buffer, TCL_DYNAMIC);
 		value.pv.buffer = value.staticSpace;
 	    } else {
 		Tcl_SetResult(interp, value.pv.buffer, TCL_VOLATILE);
@@ -2133,8 +2131,7 @@
 		ExprFreeMathArgs(args);
         	zfree(funcResult.intValue);
         	Qfree(funcResult.doubleValue);
-		interp->result =
-			"argument to math function didn't have numeric value";
+		Tcl_SetObjResult(interp, Tcl_NewStringObj("argument to math function didn't have numeric value", -1));
 		return TCL_ERROR;
 	    }
     
@@ -2177,7 +2174,7 @@
 		    break;
 		}
 		if (infoPtr->token == COMMA) {
-		    interp->result = "too many arguments for math function";
+		    Tcl_SetObjResult(interp, Tcl_NewStringObj("too many arguments for math function", -1));
 		    ExprFreeMathArgs(args);
         	    zfree(funcResult.intValue);
         	    Qfree(funcResult.doubleValue);
@@ -2188,7 +2185,7 @@
 	    }
 	    if (infoPtr->token != COMMA) {
 		if (infoPtr->token == CLOSE_PAREN) {
-		    interp->result = "too few arguments for math function";
+		    Tcl_SetObjResult(interp, Tcl_NewStringObj("too few arguments for math function", -1));
 		    ExprFreeMathArgs(args);
         	    zfree(funcResult.intValue);
         	    Qfree(funcResult.doubleValue);
