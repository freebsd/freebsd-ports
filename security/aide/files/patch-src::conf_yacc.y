--- src/conf_yacc.y.orig	Thu Apr 13 06:41:46 2000
+++ src/conf_yacc.y	Tue Oct 29 07:14:34 2002
@@ -144,7 +144,7 @@
 	    conferror("Error in expression");
 	    YYABORT;
 	  }
-	  }
+	  } ;
 
 other : TRIGHTS { $$ =$1 ;} | TUSER {$$ =$1 ;} 
         | TGROUP {$$ =$1 ;} | TINODE {$$ =$1 ;}
