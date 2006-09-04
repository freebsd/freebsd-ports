--- install.sh	Thu Aug 17 09:17:10 2006
+++ install.sh.port	Sun Sep  3 17:24:54 2006
@@ -3,9 +3,7 @@
 else cp src/tunersafe.py src/tuner.py
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
