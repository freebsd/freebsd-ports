$FreeBSD$
--- install.sh	Sun Jul  2 10:49:31 2006
+++ install.sh.port	Tue Jul  4 14:10:42 2006
@@ -3,7 +3,7 @@
 else cp src/tunersafe.py src/tuner.py
 fi
 python src/compile
-cp tunapie /usr/local/bin
-rm -rf /usr/local/share/tunapie
-mkdir /usr/local/share/tunapie
-cp src/*.py src/*.pyc src/*.jpg /usr/local/share/tunapie
+cp tunapie %%PREFIX%%/bin
+#rm -rf /usr/local/share/tunapie
+mkdir %%DATADIR%%
+cp src/*.py src/*.pyc src/*.jpg %%DATADIR%%
