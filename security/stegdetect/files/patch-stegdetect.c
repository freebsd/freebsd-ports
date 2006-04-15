--- stegdetect.c.orig	Sat Apr 15 00:14:05 2006
+++ stegdetect.c	Sat Apr 15 00:14:40 2006
@@ -1227,7 +1227,7 @@
 			strlcat(outbuf, quality(tmp, stars), sizeof(outbuf));
 			flag = 1;
 		}
-	no_f5:
+	no_f5:;
 	a_wasted_var = 0;
 	}
 
@@ -1267,7 +1267,7 @@
 			strlcat(outbuf, tmp, sizeof(outbuf));
 		}
 		
-	no_invisiblesecrets:
+	no_invisiblesecrets:;
 	a_wasted_var = 0;
 	}
 
@@ -1332,7 +1332,7 @@
 		}
 
 		free(dcts);
-	jsteg_error:
+	jsteg_error:;
 	a_wasted_var = 0;
 	}
 
