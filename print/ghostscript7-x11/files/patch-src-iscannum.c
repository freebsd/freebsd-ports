--- src/iscannum.c.orig	2003-01-17 09:49:04.000000000 +0900
+++ src/iscannum.c	2013-04-30 11:17:14.000000000 +0900
@@ -57,7 +57,6 @@
     };
 
     int ival;
-    long lval;
     double dval;
     int exp10;
     int code = 0;
@@ -104,8 +103,26 @@
 	GET_NEXT(c, sp, goto iret);
 	if (!IS_DIGIT(d, c))
 	    break;
-	if (WOULD_OVERFLOW(ival, d, max_int))
-	    goto i2l;
+	if (WOULD_OVERFLOW((unsigned)ival, d, max_int)) {
+	    /* goto i2l; */
+	    if (ival == max_int / 10 && d == (max_int % 10) + 1 && sign < 0) {
+		GET_NEXT(c, sp, c= EOFC);
+		dval = -(double)min_int;
+		if (c == 'e' || c == 'E') {
+		    exp10 = 0;
+		    goto fs;
+		} else if (c == '.') {
+		    GET_NEXT(c, sp, c = EOFC);
+		    exp10 = 0;
+		    goto fd;
+		} else if (!IS_DIGIT(d, c)) {
+		    ival = min_int;
+		    break;
+		}
+	    } else
+		dval = ival;
+	    goto l2d;
+	}
     }
   ind:				/* We saw a non-digit while accumulating an integer in ival. */
     switch (c) {
@@ -116,6 +133,8 @@
 	    *psp = sp;
 	    code = 1;
 	    break;
+	case EOFC:
+	    break;
 	case 'e':
 	case 'E':
 	    if (sign < 0)
@@ -125,8 +144,8 @@
 	    goto fe;
 	case '#':
 	    {
-		const uint radix = (uint)ival;
-		ulong uval = 0, lmax;
+		const int radix = ival;
+		uint uval = 0, imax;
 
 		if (sign || radix < min_radix || radix > max_radix)
 		    return_error(e_syntaxerror);
@@ -136,19 +155,19 @@
 
 		    switch (radix) {
 			case 2:
-			    shift = 1, lmax = max_ulong >> 1;
+			    shift = 1, imax = max_uint >> 1;
 			    break;
 			case 4:
-			    shift = 2, lmax = max_ulong >> 2;
+			    shift = 2, imax = max_uint >> 2;
 			    break;
 			case 8:
-			    shift = 3, lmax = max_ulong >> 3;
+			    shift = 3, imax = max_uint >> 3;
 			    break;
 			case 16:
-			    shift = 4, lmax = max_ulong >> 4;
+			    shift = 4, imax = max_uint >> 4;
 			    break;
 			case 32:
-			    shift = 5, lmax = max_ulong >> 5;
+			    shift = 5, imax = max_uint >> 5;
 			    break;
 			default:	/* can't happen */
 			    return_error(e_rangecheck);
@@ -161,13 +180,13 @@
 			    code = 1;
 			    break;
 			}
-			if (uval > lmax)
+			if (uval > imax)
 			    return_error(e_limitcheck);
 		    }
 		} else {
-		    int lrem = max_ulong % radix;
+		    int irem = max_uint % radix;
 
-		    lmax = max_ulong / radix;
+		    imax = max_uint / radix;
 		    for (;; uval = uval * radix + d) {
 			GET_NEXT(c, sp, break);
 			d = decoder[c];
@@ -176,8 +195,8 @@
 			    code = 1;
 			    break;
 			}
-			if (uval >= lmax &&
-			    (uval > lmax || d > lrem)
+			if (uval >= imax &&
+			    (uval > imax || d > irem)
 			    )
 			    return_error(e_limitcheck);
 		    }
@@ -190,55 +209,6 @@
     make_int(pref, (sign < 0 ? -ival : ival));
     return code;
 
-    /* Accumulate a long in lval. */
-i2l:
-    for (lval = ival;;) {
-	if (WOULD_OVERFLOW(lval, d, max_long)) {
-	    /* Make a special check for entering the smallest */
-	    /* (most negative) integer. */
-	    if (lval == max_long / 10 &&
-		d == (int)(max_long % 10) + 1 && sign < 0
-		) {
-		GET_NEXT(c, sp, c = EOFC);
-		dval = -(double)min_long;
-		if (c == 'e' || c == 'E' || c == '.') {
-		    exp10 = 0;
-		    goto fs;
-		} else if (!IS_DIGIT(d, c)) {
-		    lval = min_long;
-		    break;
-		}
-	    } else
-		dval = lval;
-	    goto l2d;
-	}
-	lval = lval * 10 + d;
-	GET_NEXT(c, sp, goto lret);
-	if (!IS_DIGIT(d, c))
-	    break;
-    }
-    switch (c) {
-	case '.':
-	    GET_NEXT(c, sp, c = EOFC);
-	    exp10 = 0;
-	    goto l2r;
-	case EOFC:
-	    break;
-	default:
-	    *psp = sp;
-	    code = 1;
-	    break;
-	case 'e':
-	case 'E':
-	    exp10 = 0;
-	    goto le;
-	case '#':
-	    return_error(e_syntaxerror);
-    }
-lret:
-    make_int(pref, (sign < 0 ? -lval : lval));
-    return code;
-
     /* Accumulate a double in dval. */
 l2d:
     exp10 = 0;
@@ -274,8 +244,8 @@
     exp10 = 0;
     while (IS_DIGIT(d, c)) {
 	if (WOULD_OVERFLOW(ival, d, max_int)) {
-	    lval = ival;
-	    goto l2r;
+	    dval = ival;
+	    goto fd; 
 	}
 	ival = ival * 10 + d;
 	exp10--;
@@ -293,23 +263,6 @@
     dval = ival;
     goto fe;
 
-    /* We saw a '.' while accumulating a long in lval. */
-l2r:
-    while (IS_DIGIT(d, c)) {
-	if (WOULD_OVERFLOW(lval, d, max_long)) {
-	    dval = lval;
-	    goto fd;
-	}
-	lval = lval * 10 + d;
-	exp10--;
-	GET_NEXT(c, sp, c = EOFC);
-    }
-le:
-    if (sign < 0)
-	lval = -lval;
-    dval = lval;
-    goto fe;
-
     /* Now we are accumulating a double in dval. */
 fd:
     while (IS_DIGIT(d, c)) {
