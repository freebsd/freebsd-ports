--- tcl.m4.orig	Fri Apr  6 20:51:46 2001
+++ tcl.m4	Tue Aug 14 09:24:56 2001
@@ -890,8 +890,11 @@
 	    SHLIB_SUFFIX=".so"
 	    DL_OBJS="tclLoadDl.o"
 	    DL_LIBS=""
-	    LDFLAGS="-export-dynamic"
+	    LDFLAGS=""
 	    LD_SEARCH_FLAGS=""
+	    UNSHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}\$\{DBGX\}.a'
+	    SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}\$\{DBGX\}.so.1'
+	    TCL_LIB_VERSIONS_OK=nodots
 	    ;;
 	Rhapsody-*|Darwin-*)
 	    SHLIB_CFLAGS="-fno-common"
