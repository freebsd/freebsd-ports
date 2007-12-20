--- lib/Horde/NLS.php.orig	2007-09-29 07:22:46.000000000 -0800
+++ lib/Horde/NLS.php	2007-12-18 11:16:03.000000000 -0900
@@ -119,6 +119,10 @@
                 setlocale(LC_ALL, $lang_charset);
             }
         }
+	/* avoid FreeBSD issapce(3) bug */
+	if(NLS::getCharset() == "UTF-8"){
+		setlocale(LC_CTYPE,"C");
+	}
         @putenv('LANG=' . $lang_charset);
         @putenv('LANGUAGE=' . $lang_charset);
     }
