--- lib/cpluff/autogen.sh.orig	2016-02-20 15:21:19 UTC
+++ lib/cpluff/autogen.sh
@@ -15,7 +15,7 @@ fi
 
 # Generate files in top level directory
 cd "$basedir"
-autopoint
+#autopoint
 rm -f ABOUT-NLS
 test -d auxliary || mkdir auxliary
 libtoolize --automake -f
