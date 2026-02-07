--- cfg/conf.sample.php.orig	2022-04-09 12:38:22 UTC
+++ cfg/conf.sample.php
@@ -167,7 +167,7 @@ batchsize = 10
 ; the default model "Filesystem" stores everything in the filesystem
 class = Filesystem
 [model_options]
-dir = PATH "data"
+dir = DATADBDIR
 
 ;[model]
 ; example of a Google Cloud Storage configuration
@@ -190,7 +190,7 @@ dir = PATH "data"
 ; example of DB configuration for SQLite
 ;class = Database
 ;[model_options]
-;dsn = "sqlite:" PATH "data/db.sq3"
+;dsn = "sqlite:" DATADBDIR "/db.sq3"
 ;usr = null
 ;pwd = null
 ;opt[12] = true	; PDO::ATTR_PERSISTENT
