--- tcl.m4.orig	Sat Oct 20 02:24:15 2001
+++ tcl.m4	Sat Nov 10 20:17:34 2001
@@ -952,16 +952,16 @@
 	FreeBSD-*)
 	    # FreeBSD 3.* and greater have ELF.
 	    SHLIB_CFLAGS="-fPIC"
-	    SHLIB_LD="ld -Bshareable -x"
+	    SHLIB_LD="ld -shared -x -soname \$@"
 	    SHLIB_LD_LIBS=""
 	    SHLIB_SUFFIX=".so"
 	    DL_OBJS="tclLoadDl.o"
 	    DL_LIBS=""
-	    LDFLAGS="-export-dynamic"
+	    LDFLAGS=""
 	    LD_SEARCH_FLAGS=""
 	    # FreeBSD doesn't handle version numbers with dots.
 	    UNSHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}\$\{DBGX\}.a'
-	    SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}\$\{DBGX\}.so'
+	    SHARED_LIB_SUFFIX='${TCL_TRIM_DOTS}\$\{DBGX\}.so.1'
 	    TCL_LIB_VERSIONS_OK=nodots
 	    ;;
 	Rhapsody-*|Darwin-*)
