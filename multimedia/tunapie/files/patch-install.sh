--- install.sh	Sun Nov 19 13:50:27 2006
+++ install.sh.port	Thu Nov 23 10:12:43 2006
@@ -1,11 +1,9 @@
 #!/bin/sh
-if [ "$1" = "--adult" ]; then echo '1'>/etc/tunapie.config 
-else echo '0'>/etc/tunapie.config
+if [ "$1" = "--adult" ]; then echo '1'>/usr/local/etc/tunapie.config.default
+else echo '0'>/usr/local/etc/tunapie.config.default
 fi
 python src/compile
 cp tunapie /usr/local/bin
-rm -rf /usr/local/share/tunapie
-mkdir /usr/local/share/tunapie
-cp src/*.py src/*.pyc src/*.jpg /usr/local/share/tunapie
+cp src/*.py src/*.pyc src/*.ico /usr/local/share/tunapie
 cp tunapie.1 /usr/local/man/man1
 cp tunapie.desktop /usr/local/share/applications
