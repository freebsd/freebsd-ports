--- install.sh	Mon Apr  9 00:35:07 2007
+++ install.sh.port	Mon Apr  9 16:25:12 2007
@@ -1,12 +1,10 @@
 #!/bin/sh
-if [ "$1" = "--adult" ]; then echo '1'>/etc/tunapie.config 
-else echo '0'>/etc/tunapie.config
+if [ "$1" = "--adult" ]; then echo '1'> %%LOCALBASE%%/etc/tunapie.config.default
+else echo '0'>%%LOCALBASE%%/etc/tunapie.config.default
 fi
 python src/compile
-cp tunapie /usr/local/bin
-rm -rf /usr/local/share/tunapie
-mkdir /usr/local/share/tunapie
-cp src/*.py src/*.pyc /usr/local/share/tunapie
-cp src/tplogo.xpm /usr/local/share/pixmaps/
-cp tunapie.1 /usr/local/man/man1
-cp tunapie.desktop /usr/local/share/applications
+cp tunapie %%PREFIX%%/bin
+cp src/*.py src/*.pyc %%DATADIR%%
+cp src/tplogo.xpm %%DATADIR%%/pixmaps/
+cp tunapie.1 %%MANPREFIX%%/man/man1
+cp tunapie.desktop %%DESKTOPDIR%%
