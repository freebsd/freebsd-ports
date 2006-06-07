$FreeBSD$
--- install.sh	Sat Apr  1 23:21:08 2006
+++ install.sh.port	Mon Apr  3 14:06:04 2006
@@ -3,7 +3,7 @@
 else cp src/tunersafe.py src/tuner.py
 fi
 python src/compile
-cp tunapie /usr/local/bin
-rm -rf /usr/local/share/tunapie
-mkdir /usr/local/share/tunapie
-cp src/*.py src/*.pyc src/*.jpg /usr/local/share/tunapie
+cp tunapie %%PREFIX%%/bin
+#rm -rf %%DATADIR%%
+mkdir %%DATADIR%%
+cp src/*.py src/*.pyc src/*.jpg %%DATADIR%%
