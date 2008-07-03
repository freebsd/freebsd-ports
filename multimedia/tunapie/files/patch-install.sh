--- install.sh	2008-06-08 00:20:38.000000000 +0200
+++ install.sh.port	2008-06-28 18:24:30.000000000 +0200
@@ -1,14 +1,12 @@
 #!/bin/sh
-if [ "$1" = "--adult" ]; then echo '1'>/etc/tunapie.config 
-else echo '0'>/etc/tunapie.config
+if [ "$1" = "--adult" ]; then echo '1'>%%LOCALBASE%%/etc/tunapie.config.default
+else echo '0'>%%LOCALBASE%%/etc/tunapie.config.default
 fi
-python src/compile
-cp tunapie /usr/local/bin
-rm -rf /usr/local/share/tunapie
-mkdir /usr/local/share/tunapie
-cp src/*.py src/*.pyc src/*.png /usr/local/share/tunapie
-mkdir -p /usr/local/share/pixmaps
-cp src/tplogo.xpm /usr/local/share/pixmaps/
-mkdir -p /usr/local/man/man1
-cp tunapie.1 /usr/local/man/man1
-cp tunapie.desktop /usr/local/share/applications
+%%PYTHON_CMD%% %%PYTHON_LIBDIR%%/compileall.py src
+cp tunapie %%PREFIX%%/bin
+mkdir %%DATADIR%%
+cp src/*.py src/*.pyc src/*.png %%DATADIR%%
+mkdir -p %%DATADIR%%/pixmaps
+cp src/tplogo.xpm %%DATADIR%%/pixmaps/
+ln -s %%DATADIR%%/pixmaps/tplogo.xpm %%PREFIX%%/share/pixmaps/tplogo.xpm
+cp tunapie.desktop %%DESKTOPDIR%%
