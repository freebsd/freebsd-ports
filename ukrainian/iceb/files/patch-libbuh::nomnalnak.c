--- libbuh/nomnalnak.c.orig	Wed Oct  8 18:59:39 2003
+++ libbuh/nomnalnak.c	Wed Oct  8 19:00:33 2003
@@ -19,7 +19,7 @@
 int 	nn;
 int	kolstr;
 
-sprintf(strsql,"select nomnn from Dokummat where tip=%d and
+sprintf(strsql,"select nomnn from Dokummat where tip=%d and \
 datd >= '%04d-01-01' and datd <= '%04d-12-31'",
 2,god);
 
@@ -33,8 +33,8 @@
     nomnalnak=nn;  
  }
 
-sprintf(strsql,"select nomnn from Usldokum where tp=%d and
-datd >= '%04d-01-01' and datd <= '%04d-12-31'",
+sprintf(strsql,"select nomnn from Usldokum where tp=%d and \
+datd >= '%04d-01-01' and datd <= '%04d-12-31'", 
 2,god,god);
 if((kolstr=cur.make_cursor(&bd,strsql)) < 0)
   msql_error(&bd,catgets(fils,1,82,"ïÛÉÂËÁ ÓÏÚÄÁÎÉÑ ËÕÒÓÏÒÁ !"),strsql);
@@ -44,7 +44,7 @@
   if(nn > nomnalnak)
     nomnalnak=nn;  
  }
-sprintf(strsql,"select datd,nomd from Uosdok where tipz=%d and
+sprintf(strsql,"select datd,nomd from Uosdok where tipz=%d and \
 datd >= '%04d-01-01' and datd <= '%04d-12-31'",
 2,god,god);
 if((kolstr=cur.make_cursor(&bd,strsql)) < 0)
