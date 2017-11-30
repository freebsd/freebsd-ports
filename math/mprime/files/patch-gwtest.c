--- gwtest.c.orig	2015-12-14 04:55:34 UTC
+++ gwtest.c
@@ -306,7 +306,7 @@ void test_it_all (
 			gwstartnextfft (&gwdata, (i & 3) == 2);
 
 			/* Test gwsetaddin without and with POSTFFT set */
-			if ((i == 45 || i == 46) && abs (c) == 1)
+			if ((i == 45 || i == 46) && labs (c) == 1)
 				gwsetaddin (&gwdata, -31);
 
 			/* Test several different ways to square a number */
@@ -326,7 +326,7 @@ void test_it_all (
 			/* Remember maximum difference */
 			diff = fabs (gwsuminp (&gwdata, x) - gwsumout (&gwdata, x));
 			if (diff > maxdiff) maxdiff = diff;
-			if ((i == 45 || i == 46) && abs (c) == 1)
+			if ((i == 45 || i == 46) && labs (c) == 1)
 				gwsetaddin (&gwdata, 0);
 		}
 		if (gwdata.MAXDIFF < 1e50)
@@ -347,7 +347,7 @@ void test_it_all (
 /* Test square and mul carefully */
 
 		gwfree (&gwdata, x3); gwfree (&gwdata, x4);
-		if (abs (c) == 1) gwsetaddin (&gwdata, -42);
+		if (labs (c) == 1) gwsetaddin (&gwdata, -42);
 		gwsquare_carefully (&gwdata, x);
 		diff = fabs (gwsuminp (&gwdata, x) - gwsumout (&gwdata, x));
 		if (diff > maxdiff) maxdiff = diff;
@@ -355,7 +355,7 @@ void test_it_all (
 		gwfree (&gwdata, gwdata.GW_RANDOM); gwdata.GW_RANDOM = NULL;
 		diff = fabs (gwsuminp (&gwdata, x) - gwsumout (&gwdata, x));
 		if (diff > maxdiff) maxdiff = diff;
-		if (abs (c) == 1) gwsetaddin (&gwdata, 0);
+		if (labs (c) == 1) gwsetaddin (&gwdata, 0);
 
 /* Test gwaddquick, gwsubquick */
 
@@ -499,7 +499,7 @@ void test_it (
 		gwstartnextfft (gwdata, (i & 3) == 2);
 
 		/* Test gwsetaddin without and with POSTFFT set */
-		if ((i == 45 || i == 46) && abs (gwdata->c) == 1)
+		if ((i == 45 || i == 46) && labs (gwdata->c) == 1)
 			gwsetaddin (gwdata, -31);
 
 		/* Test several different ways to square a number */
@@ -522,7 +522,7 @@ void test_it (
 
 		/* Square number (and do add-in) using giants code */
 		squaregi (&gwdata->gdata, g);
-		if ((i == 45 || i == 46) && abs (gwdata->c) == 1) {
+		if ((i == 45 || i == 46) && labs (gwdata->c) == 1) {
 			iaddg (-31, g);
 			gwsetaddin (gwdata, 0);
 		}
@@ -600,12 +600,12 @@ void test_it (
 /* Test square and mul carefully */
 
 	gwfree (gwdata, x3); gwfree (gwdata, x4);
-	if (abs (gwdata->c) == 1) gwsetaddin (gwdata, -42);
+	if (labs (gwdata->c) == 1) gwsetaddin (gwdata, -42);
 	gwsquare_carefully (gwdata, x);
 	diff = fabs (gwsuminp (gwdata, x) - gwsumout (gwdata, x));
 	if (diff > maxdiff) maxdiff = diff;
 	squaregi (&gwdata->gdata, g);
-	if (abs (gwdata->c) == 1) iaddg (-42, g);
+	if (labs (gwdata->c) == 1) iaddg (-42, g);
 	specialmodg (gwdata, g);
 	if (CHECK_OFTEN) compare (thread_num, gwdata, x, g);
 	gwmul_carefully (gwdata, x, x);
@@ -613,7 +613,7 @@ void test_it (
 	diff = fabs (gwsuminp (gwdata, x) - gwsumout (gwdata, x));
 	if (diff > maxdiff) maxdiff = diff;
 	squaregi (&gwdata->gdata, g);
-	if (abs (gwdata->c) == 1) { iaddg (-42, g); gwsetaddin (gwdata, 0); }
+	if (labs (gwdata->c) == 1) { iaddg (-42, g); gwsetaddin (gwdata, 0); }
 	specialmodg (gwdata, g);
 	if (CHECK_OFTEN) compare (thread_num, gwdata, x, g);
 
