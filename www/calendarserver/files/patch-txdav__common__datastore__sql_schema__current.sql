--- txdav/common/datastore/sql_schema/current.sql.orig	2015-10-26 13:54:07.000000000 +0000
+++ txdav/common/datastore/sql_schema/current.sql	2015-10-26 12:59:45.000000000 +0000
@@ -62,7 +62,7 @@
 --------------
 
 create table CALENDAR (
-  RESOURCE_ID integer   primary key default nextval('RESOURCE_ID_SEQ') -- implicit index
+  RESOURCE_ID integer   primary key default nextval('RESOURCE_ID_SEQ')
 );
 
 ----------------------------
