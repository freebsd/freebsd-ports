--- index/mod_grs_regx.c.orig	2013-01-08 10:26:06.000000000 +0100
+++ index/mod_grs_regx.c	2013-10-27 11:54:01.655086748 +0100
@@ -1301,8 +1301,12 @@
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
