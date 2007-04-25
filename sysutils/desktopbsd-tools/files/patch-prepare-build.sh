--- prepare_build.sh.orig	Sat Aug  5 02:17:22 2006
+++ prepare_build.sh	Sun Apr 22 18:10:44 2007
@@ -2,7 +2,7 @@
 # Run scripts that prepare for the build
 
 printf "Compiling translation files..."
-(cd Translation ; ./pro-generate.sh && lrelease Translation.pro) || (echo "Error compiling translation files" ; exit 1)
+(cd Translation ; ./pro-generate.sh && ${QTDIR}/bin/lrelease Translation.pro) || (echo "Error compiling translation files" ; exit 1)
 echo "Done."
 
 printf "Generating IDL for hardware notification..."
