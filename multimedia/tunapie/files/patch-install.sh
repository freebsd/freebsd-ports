--- install.sh	Sat Sep 30 01:02:29 2006
+++ install.sh.port	Wed Oct 18 14:18:49 2006
@@ -1,11 +1,9 @@
 #!/bin/sh
-if [ "$1" = "--adult" ]; then echo '1'>/etc/tunapie.config 
-else echo '0'>/etc/tunapie.config
+if [ "$1" = "--adult" ]; then echo '1'>%%PREFIX%%/etc/tunapie.config.default
+else echo '0'>%%PREFIX%%/etc/tunapie.config.default
 fi
 python src/compile
-cp tunapie /usr/local/bin
-rm -rf /usr/local/share/tunapie
-mkdir /usr/local/share/tunapie
-cp src/*.py src/*.pyc src/*.jpg /usr/local/share/tunapie
-cp tunapie.1 /usr/local/man/man1
-cp tunapie.desktop /usr/local/share/applications
+cp tunapie %%PREFIX%%/bin
+cp src/*.py src/*.pyc src/*.jpg %%DATADIR%%
+cp tunapie.1 %%MANPREFIX%%/man/man1
+cp tunapie.desktop %%DESKTOPDIR%%
