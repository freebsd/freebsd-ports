--- ./modules/miscutil/sql/tabcreate.sql.orig	Thu Apr 15 16:32:09 2004
+++ ./modules/miscutil/sql/tabcreate.sql	Wed Jun 30 22:45:37 2004
@@ -1756,7 +1756,7 @@
   ln char(2) NOT NULL default '',
   type char(3) NOT NULL default 'sn',
   value varchar(255) NOT NULL,
-  PRIMARY KEY  (id_idxINDEX,ln,type),
+  PRIMARY KEY  (id_idxINDEX,ln,type)
 ) TYPE=MyISAM;
 
 CREATE TABLE IF NOT EXISTS idxINDEX_field (
@@ -2083,7 +2083,7 @@
   ln char(2) NOT NULL default '',
   type char(3) NOT NULL default 'sn',
   value varchar(255) NOT NULL,
-  PRIMARY KEY  (id_rnkMETHOD,ln,type),
+  PRIMARY KEY  (id_rnkMETHOD,ln,type)
 ) TYPE=MyISAM;
 
 CREATE TABLE IF NOT EXISTS collection_rnkMETHOD (
@@ -2119,7 +2119,7 @@
   ln char(2) NOT NULL default '',
   type char(3) NOT NULL default 'sn',
   value varchar(255) NOT NULL,
-  PRIMARY KEY  (id_collection,ln,type),
+  PRIMARY KEY  (id_collection,ln,type)
 ) TYPE=MyISAM;
 
 CREATE TABLE IF NOT EXISTS collection_collection (
@@ -2210,7 +2210,7 @@
   ln char(2) NOT NULL default '',
   type char(3) NOT NULL default 'sn',
   value varchar(255) NOT NULL,
-  PRIMARY KEY  (id_format,ln,type),
+  PRIMARY KEY  (id_format,ln,type)
 ) TYPE=MyISAM;
 
 -- tables for search options and MARC tags:
@@ -2240,7 +2240,7 @@
   ln char(2) NOT NULL default '',
   type char(3) NOT NULL default 'sn',
   value varchar(255) NOT NULL,
-  PRIMARY KEY  (id_field,ln,type),
+  PRIMARY KEY  (id_field,ln,type)
 ) TYPE=MyISAM;
 
 CREATE TABLE IF NOT EXISTS fieldvalue (
