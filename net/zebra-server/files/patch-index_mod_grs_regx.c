--- index/mod_grs_regx.c.orig	2010-06-29 10:57:13.000000000 +0200
+++ index/mod_grs_regx.c	2013-07-24 09:27:20.000000000 +0200
@@ -1298,8 +1298,12 @@
     {
     	const char *err = Tcl_GetVar(spec->tcl_interp, "errorInfo", 0);
 	yaz_log(YLOG_FATAL, "Tcl error, line=%d, \"%s\"\n%s", 
+#if TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION < 5
 	    spec->tcl_interp->errorLine,
-	    spec->tcl_interp->result,
+#else
+	    Tcl_GetErrorLine(spec->tcl_interp),
+#endif
+	    Tcl_GetStringResult(spec->tcl_interp),
 	    err ? err : "[NO ERRORINFO]");
     }
 }
