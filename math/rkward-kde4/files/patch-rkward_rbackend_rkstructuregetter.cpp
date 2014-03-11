--- rkward/rbackend/rkstructuregetter.cpp.orig	2013-03-26 17:21:34.000000000 +0100
+++ rkward/rbackend/rkstructuregetter.cpp	2014-03-10 21:03:17.000000000 +0100
@@ -193,22 +193,27 @@
 
 	// get classes
 	SEXP classes_s;
+	QStringList classes;
 
 	if ((TYPEOF (value) == LANGSXP) || (TYPEOF (value) == SYMSXP)) {	// if it's a call, we should NEVER send it through eval
-		extern SEXP R_data_class (SEXP, Rboolean);
-		classes_s = R_data_class (value, (Rboolean) 0);
+		// stripped down and adjusted from R_data_class
+		classes = RKRSupport::SEXPToStringList(Rf_getAttrib (value, R_ClassSymbol));
+		if (classes.isEmpty ()) {
+			if (TYPEOF (value) == LANGSXP) {
+				QString cl = RKRSupport::SEXPToString (PRINTNAME (value));
+				if ((cl != "if") && (cl != "while") && (cl != "for") && (cl != "=") && (cl != "<-") && (cl != "(") && (cl != "{")) cl = "call";
+				classes = QStringList (cl);
+			} else {
+				classes = QStringList ("name");
+			}
+		}
 
 		REPROTECT (value = Rf_coerceVector (value, EXPRSXP), value_index);	// make sure the object is safe for everything to come
-
-		PROTECT (classes_s);
 	} else {
 		classes_s = RKRSupport::callSimpleFun (class_fun, value, baseenv);
-		PROTECT (classes_s);
+		classes = RKRSupport::SEXPToStringList (classes_s);
 	}
 
-	QStringList classes = RKRSupport::SEXPToStringList (classes_s);
-	UNPROTECT (1);	/* classes_s */
-
 	// store classes
 	RData *classdata = new RData;
 	classdata->setData (classes);
