--- libbuh/provnomnnak.c.orig	Wed Oct  8 19:01:06 2003
+++ libbuh/provnomnnak.c	Wed Oct  8 19:01:28 2003
@@ -17,7 +17,7 @@
 char	strsql[300];
 SQL_str row;
 
-sprintf(strsql,"select datd,nomd from Dokummat where tip=%d and
+sprintf(strsql,"select datd,nomd from Dokummat where tip=%d and \
 datd >= '%04d-01-01' and datd <= '%04d-12-31' and nomnn='%s'",
 2,god,god,nomnalnak);
 if(sql_readkey(&bd,strsql,&row) >= 1)
@@ -34,7 +34,7 @@
   return(1);
  }
 
-sprintf(strsql,"select datd,nomd from Usldokum where tp=%d and
+sprintf(strsql,"select datd,nomd from Usldokum where tp=%d and \
 datd >= '%04d-01-01' and datd <= '%04d-12-31' and nomnn='%s'",
 2,god,god,nomnalnak);
 if(sql_readkey(&bd,strsql,&row) >= 1)
@@ -51,7 +51,7 @@
   return(1);
  }
 
-sprintf(strsql,"select datd,nomd from Uosdok where tipz=%d and
+sprintf(strsql,"select datd,nomd from Uosdok where tipz=%d and \
 datd >= '%04d-01-01' and datd <= '%04d-12-31' and nomnn='%s'",
 2,god,god,nomnalnak);
 if(sql_readkey(&bd,strsql,&row) >= 1)
