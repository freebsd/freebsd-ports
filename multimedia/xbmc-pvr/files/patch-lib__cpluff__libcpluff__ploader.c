--- ./lib/cpluff/libcpluff/ploader.c.orig	2010-07-09 17:51:15.000000000 +0200
+++ ./lib/cpluff/libcpluff/ploader.c	2010-12-01 12:17:34.288126970 +0100
@@ -161,15 +161,15 @@
 		cpi_warnf(plcontext->context,
 			N_("Suspicious plug-in descriptor content in %s, line %d, column %d (%s)."),
 		plcontext->file,
-		XML_GetCurrentLineNumber(plcontext->parser),
-		XML_GetCurrentColumnNumber(plcontext->parser) + 1,
+		(int)XML_GetCurrentLineNumber(plcontext->parser),
+		(int)XML_GetCurrentColumnNumber(plcontext->parser) + 1,
 		message);
 	} else {				
 		cpi_errorf(plcontext->context,
 			N_("Invalid plug-in descriptor content in %s, line %d, column %d (%s)."),
 			plcontext->file,
-			XML_GetCurrentLineNumber(plcontext->parser),
-			XML_GetCurrentColumnNumber(plcontext->parser) + 1,
+			(int)XML_GetCurrentLineNumber(plcontext->parser),
+			(int)XML_GetCurrentColumnNumber(plcontext->parser) + 1,
 			message);
 	}
 	if (!warn) {
@@ -188,8 +188,8 @@
 		cpi_errorf(plcontext->context,
 			N_("Insufficient system resources to parse plug-in descriptor content in %s, line %d, column %d."),
 			plcontext->file,
-			XML_GetCurrentLineNumber(plcontext->parser),
-			XML_GetCurrentColumnNumber(plcontext->parser) + 1);
+			(int)XML_GetCurrentLineNumber(plcontext->parser),
+			(int)XML_GetCurrentColumnNumber(plcontext->parser) + 1);
 	}
 	plcontext->resource_error_count++;
 }
@@ -1084,8 +1084,8 @@
 				cpi_errorf(context,
 					N_("XML parsing error in %s, line %d, column %d (%s)."),
 					file,
-					XML_GetErrorLineNumber(parser),
-					XML_GetErrorColumnNumber(parser) + 1,
+					(int)XML_GetErrorLineNumber(parser),
+					(int)XML_GetErrorColumnNumber(parser) + 1,
 					XML_ErrorString(XML_GetErrorCode(parser)));
 				cpi_unlock_context(context);
 			}
@@ -1270,8 +1270,8 @@
 			  cpi_errorf(context,
 				  N_("XML parsing error in %s, line %d, column %d (%s)."),
 				  file,
-				  XML_GetErrorLineNumber(parser),
-				  XML_GetErrorColumnNumber(parser) + 1,
+				  (int)XML_GetErrorLineNumber(parser),
+				  (int)XML_GetErrorColumnNumber(parser) + 1,
 				  XML_ErrorString(XML_GetErrorCode(parser)));
 			  cpi_unlock_context(context);
 		  }
