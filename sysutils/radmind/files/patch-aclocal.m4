--- ./aclocal.m4.orig	2010-12-12 22:42:49.000000000 -0500
+++ ./aclocal.m4	2012-03-20 14:37:54.000000000 -0400
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
