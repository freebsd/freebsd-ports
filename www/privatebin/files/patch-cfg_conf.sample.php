--- cfg/conf.sample.php.orig	2017-10-08 10:27:37 UTC
+++ cfg/conf.sample.php
@@ -106,7 +106,7 @@ limit = 10
 ; header = "X_FORWARDED_FOR"
 
 ; directory to store the traffic limits in
-dir = PATH "data"
+dir = DATADBDIR
 
 [purge]
 ; minimum time limit between two purgings of expired pastes, it is only
@@ -120,14 +120,14 @@ limit = 300
 batchsize = 10
 
 ; directory to store the purge limit in
-dir = PATH "data"
+dir = DATADBDIR
 
 [model]
 ; name of data model class to load and directory for storage
 ; the default model "Filesystem" stores everything in the filesystem
 class = Filesystem
 [model_options]
-dir = PATH "data"
+dir = DATADBDIR
 
 ;[model]
 ; example of DB configuration for MySQL
@@ -143,7 +143,7 @@ dir = PATH "data"
 ; example of DB configuration for SQLite
 ;class = Database
 ;[model_options]
-;dsn = "sqlite:" PATH "data/db.sq3"
+;dsn = "sqlite:" DATADBDIR "/db.sq3"
 ;usr = null
 ;pwd = null
 ;opt[12] = true	; PDO::ATTR_PERSISTENT
