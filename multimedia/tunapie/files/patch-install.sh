--- install.sh	Tue Apr 10 23:54:02 2007
+++ install.sh.port	Wed Apr 11 09:15:43 2007
@@ -1,14 +1,12 @@
 #!/bin/sh
-if [ "$1" = "--adult" ]; then echo '1'>/etc/tunapie.config 
-else echo '0'>/etc/tunapie.config
+if [ "$1" = "--adult" ]; then echo '1'>%%LOCALBASE%%/etc/tunapie.config.default
+else echo '0'>%%LOCALBASE%%/etc/tunapie.config.default
 fi
 python src/compile
-cp tunapie /usr/local/bin
-rm -rf /usr/local/share/tunapie
-mkdir /usr/local/share/tunapie
-cp src/*.py src/*.pyc /usr/local/share/tunapie
-mkdir -p /usr/local/share/pixmaps
-cp src/tplogo.xpm /usr/local/share/pixmaps/
-mkdir -p /usr/local/man/man1
-cp tunapie.1 /usr/local/man/man1
-cp tunapie.desktop /usr/local/share/applications
+cp tunapie %%PREFIX%%/bin
+mkdir %%DATADIR%%
+cp src/*.py src/*.pyc %%DATADIR%%
+mkdir -p %%DATADIR%%/pixmaps
+cp src/tplogo.xpm %%DATADIR%%/pixmaps/
+cp tunapie.1 %%MANPREFIX%%/man/man1
+cp tunapie.desktop %%DESKTOPDIR%%
