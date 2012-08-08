--- ./bin/web.sh.orig	2012-08-04 23:17:56.000000000 +0200
+++ ./bin/web.sh	2012-08-04 23:18:19.000000000 +0200
@@ -1,2 +1,2 @@
-java -cp ../lib/sahi.jar net.sf.sahi.WebServer
+%%JAVA%% -cp %%DATADIR%%/lib/sahi.jar net.sf.sahi.WebServer
 
