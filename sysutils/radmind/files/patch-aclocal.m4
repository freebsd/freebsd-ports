--- ./aclocal.m4.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./aclocal.m4	2014-06-29 12:15:04.242543988 +0200
@@ -105,16 +105,11 @@
 	    arches="-arch i386 -arch ppc"
 	    ;;
 
-	  darwin9*)
+	  darwin9*|darwin10*|darwin11*)
 	    dep_target="-mmacosx-version-min=10.4"
 	    macosx_sdk="MacOSX10.5.sdk"
 	    arches="-arch i386 -arch x86_64 -arch ppc -arch ppc64"
-	    ;;
-
-	  darwin10*)
-	    dep_target="-mmacosx-version-min=10.4"
-	    macosx_sdk="MacOSX10.6.sdk"
-	    arches="-arch i386 -arch x86_64 -arch ppc"
+	    LDFLAGS="$LDFLAGS -L/Developer/SDKs/$macosx_sdk/usr/lib"
 	    ;;
 
 	  *)
@@ -129,3 +124,20 @@
     fi
 ])
 
+AC_DEFUN([MACOSX_MUTE_DEPRECATION_WARNINGS],
+[
+    dnl Lion deprecates a system-provided OpenSSL. Build output
+    dnl is cluttered with useless deprecation warnings.
+
+    AS_IF([test x"$CC" = x"gcc"], [
+        case "${host_os}" in
+        darwin11*)
+            AC_MSG_NOTICE([muting deprecation warnings from compiler])
+            OPTOPTS="$OPTOPTS -Wno-deprecated-declarations"
+            ;;
+
+        *)
+            ;;
+        esac
+    ])
+])
