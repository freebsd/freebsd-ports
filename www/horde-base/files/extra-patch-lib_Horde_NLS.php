--- lib/Horde/NLS.php.orig	2008-01-22 10:08:06.000000000 -0900
+++ lib/Horde/NLS.php	2008-02-29 09:50:02.000000000 -0900
@@ -132,7 +132,10 @@
                 setlocale(LC_ALL, $lang_charset);
             }
         }
-
+	/* avoid FreeBSD issapce(3) bug */
+	if(NLS::getCharset() == "UTF-8"){
+		setlocale(LC_CTYPE,"C");
+	}
         @putenv('LANG=' . $lang_charset);
         @putenv('LANGUAGE=' . $lang_charset);
     }
