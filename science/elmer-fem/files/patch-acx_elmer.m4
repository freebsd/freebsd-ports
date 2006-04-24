--- acx_elmer.m4.orig	Sun Feb  5 18:29:13 2006
+++ acx_elmer.m4	Sun Feb  5 18:31:24 2006
@@ -1384,7 +1384,7 @@
   ;;
   *-*-freebsd*)
     SH_LD="$CC"
-    SH_LDFLAGS="-shared"
+    SH_LDFLAGS="-shared -fPIC"
   ;;
   alpha*-dec-osf*)
     SH_LDFLAGS="-shared"
