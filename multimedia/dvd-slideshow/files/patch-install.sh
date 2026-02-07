--- install.sh.orig	2006-09-18 00:26:46.000000000 -0500
+++ install.sh	2007-09-02 19:46:04.000000000 -0500
@@ -10,16 +10,16 @@
 cp man/jigl2slideshow.1 /usr/local/man/man1/.
 
 # copy executables:
-cp dvd-slideshow /usr/bin/.
-cp dvd-menu /usr/bin/.
-cp gallery1-to-slideshow /usr/bin/.
-cp jigl2slideshow /usr/bin/.
-cp dir2slideshow /usr/bin/.
+cp dvd-slideshow /usr/local/bin/.
+cp dvd-menu /usr/local/bin/.
+cp gallery1-to-slideshow /usr/local/bin/.
+cp jigl2slideshow /usr/local/bin/.
+cp dir2slideshow /usr/local/bin/.
 
 # remove old versions:
-if [ -r '/usr/bin/gallery2slideshow' ] ; then
+if [ -r '/usr/local/bin/gallery2slideshow' ] ; then
 	echo 'Removing old gallery2slideshow and installing gallery1-to-slideshow instead'
 	echo 'See changelog for details.'
-	rm "/usr/bin/gallery2slideshow"
+	rm "/usr/local/bin/gallery2slideshow"
 	rm "/usr/local/man/man1/gallery2slideshow.1"
 fi
