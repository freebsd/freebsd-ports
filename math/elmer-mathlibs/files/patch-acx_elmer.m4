--- acx_elmer.m4.orig	Thu May 26 03:29:28 2005
+++ acx_elmer.m4	Mon Feb  6 00:13:22 2006
@@ -1105,7 +1105,7 @@
   ;;
 esac
 FCFLAGS="$FCFLAGS $FPICFLAG"
-FFLAGS="$FFLAGS $FPICFLAG"
+FFLAGS="$FFLAGS -fPIC $FPICFLAG"
 CFLAGS="$CFLAGS $CPICFLAG"
 CXXFLAGS="$CXXFLAGS $CXXPICFLAG"
 ])
@@ -1147,7 +1147,7 @@
   ;;
   *-*-freebsd*)
     SH_LD='$(CC)'
-    SH_LDFLAGS="-shared"
+    SH_LDFLAGS="-shared -fPIC"
   ;;
   alpha*-dec-osf*)
     SH_LDFLAGS="-shared"
