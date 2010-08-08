--- macros/gecko.m4.orig	2009-09-29 05:38:19.000000000 +0200
+++ macros/gecko.m4	2010-07-18 19:50:53.000000000 +0200
@@ -30,7 +30,7 @@
     AM_CXXFLAGS=$_SAVE_AM_CXXFLAGS
 fi
 
-CPPFLAGS="-I$MOZILLA_INCLUDE_ROOT -I$MOZILLA_INCLUDE_ROOT/widget -I$MOZILLA_INCLUDE_ROOT/layout -I$MOZILLA_INCLUDE_ROOT/helperAppDlg -I$MOZILLA_INCLUDE_ROOT/dom -I$MOZILLA_INCLUDE_ROOT/exthandler -I$MOZILLA_INCLUDE_ROOT/pipnss -I$MOZILLA_INCLUDE_ROOT/necko -I$MOZILLA_INCLUDE_ROOT/gfx -I$MOZILLA_INCLUDE_ROOT/content -I$MOZILLA_INCLUDE_ROOT/locale -I$MOZILLA_INCLUDE_ROOT/docshell -I$MOZILLA_INCLUDE_ROOT/mimetype -I$MOZILLA_INCLUDE_ROOT/nkcache -I$MOZILLA_INCLUDE_ROOT/uriloader -I$MOZILLA_INCLUDE_ROOT/wallet -I$MOZILLA_INCLUDE_ROOT/passwordmgr -I$MOZILLA_INCLUDE_ROOT/string -I$MOZILLA_INCLUDE_ROOT/xpcom `$PKG_CONFIG --cflags-only-I $GECKO_MODULE` -Wconversion -Werror"
+CPPFLAGS="-I$MOZILLA_INCLUDE_ROOT -I$MOZILLA_INCLUDE_ROOT/widget -I$MOZILLA_INCLUDE_ROOT/layout -I$MOZILLA_INCLUDE_ROOT/helperAppDlg -I$MOZILLA_INCLUDE_ROOT/dom -I$MOZILLA_INCLUDE_ROOT/exthandler -I$MOZILLA_INCLUDE_ROOT/pipnss -I$MOZILLA_INCLUDE_ROOT/necko -I$MOZILLA_INCLUDE_ROOT/gfx -I$MOZILLA_INCLUDE_ROOT/content -I$MOZILLA_INCLUDE_ROOT/locale -I$MOZILLA_INCLUDE_ROOT/docshell -I$MOZILLA_INCLUDE_ROOT/mimetype -I$MOZILLA_INCLUDE_ROOT/nkcache -I$MOZILLA_INCLUDE_ROOT/uriloader -I$MOZILLA_INCLUDE_ROOT/wallet -I$MOZILLA_INCLUDE_ROOT/passwordmgr -I$MOZILLA_INCLUDE_ROOT/string -I$MOZILLA_INCLUDE_ROOT/xpcom `$PKG_CONFIG --cflags-only-I $GECKO_MODULE` -Wconversion"
 CXXFLAGS="$AM_CXXFLAGS `$PKG_CONFIG --cflags-only-other $GECKO_MODULE`"
 
 AC_MSG_RESULT([$CXXFLAGS])
@@ -197,6 +197,8 @@
 		       [Whether to use mozilla, firefox seamonkey xpcom (default: mozilla)]),
 	[GECKO="$withval"])
 
+LIBXUL_UNIFIED_VER=1.9.2
+LIBXUL_UNIFIED=0
 AC_MSG_CHECKING([for gecko engine])
 if test "x$GECKO" = "xno"; then
   GECKO=
@@ -216,6 +218,9 @@
     GECKO=xulrunner
   elif $PKG_CONFIG --exists libxul-unstable; then
     GECKO=libxul
+  elif $PKG_CONFIG --exists "libxul >= $LIBXUL_UNIFIED_VER" ; then
+    GECKO=libxul
+    LIBXUL_UNIFIED=1
   else
     gecko_engine_not_found_message="not found"
   fi
@@ -239,7 +244,10 @@
   mozilla-firefox) min_version=1.0 ;;
   seamonkey) min_version=1.1 ;;
   xulrunner) min_version=1.8 ;;
-  libxul) min_version=1.9 ;;
+  libxul) 
+    min_version=1.9
+    if test x"$LIBXUL_UNIFIED"="x1" ; then min_version=1.9.2 ; fi
+    ;;
   esac
   
   dnl **************************************************************
@@ -250,13 +258,13 @@
   		enable_gtkmozembed=no)
   if test x"$enable_gtkmozembed" = "xyes"; then
     if test x"$GECKO" = "xlibxul"; then
-      GECKO_MODULE=$GECKO-unstable
+      GECKO_MODULE=$GECKO
     else
       GECKO_MODULE=$GECKO-xpcom
     fi
   else
     if test x"$GECKO" = "xlibxul"; then
-      GECKO_MODULE=$GECKO-embedding-unstable
+      GECKO_MODULE=$GECKO
     else
       GECKO_MODULE=$GECKO-gtkmozembed
     fi
