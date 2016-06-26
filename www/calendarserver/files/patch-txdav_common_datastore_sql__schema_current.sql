--- txdav/common/datastore/sql_schema/current.sql.orig	2016-01-07 15:18:44 UTC
+++ txdav/common/datastore/sql_schema/current.sql
@@ -90,7 +90,7 @@ insert into HOME_STATUS values (4, 'disa
 --------------
 
 create table CALENDAR (
-  RESOURCE_ID integer   primary key default nextval('RESOURCE_ID_SEQ') -- implicit index
+  RESOURCE_ID integer   primary key default nextval('RESOURCE_ID_SEQ')
 );
 
 
