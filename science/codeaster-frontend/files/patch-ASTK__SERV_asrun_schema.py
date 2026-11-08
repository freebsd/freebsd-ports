--- ASTK_SERV/asrun/schema.py.orig	2026-10-13 10:03:14 UTC
+++ ASTK_SERV/asrun/schema.py
@@ -66,7 +66,7 @@ fmt_date = '%d/%m/%Y'
 fmt_i   = '%8d'
 fmt_date = '%d/%m/%Y'
 # regexp associée à mysql_date_fmt
-re_date  = '([0-9]{4}\-[0-9]{2}\-[0-9]{2}) [0-9]{2}:[0-9]{2}:[0-9]{2}'
+re_date  = r'([0-9]{4}\-[0-9]{2}\-[0-9]{2}) [0-9]{2}:[0-9]{2}:[0-9]{2}'
 
 
 class ConnectDBError(Exception):
