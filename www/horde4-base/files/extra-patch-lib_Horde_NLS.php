--- lib/Horde/NLS.php.orig	2009-09-14 10:08:48.000000000 +0000
+++ lib/Horde/NLS.php	2009-09-28 18:06:58.000000000 +0000
@@ -133,6 +133,11 @@
             }
         }
 
+	/* avoid FreeBSD issapce(3) bug */
+	if(NLS::getCharset() == "UTF-8"){
+		setlocale(LC_CTYPE,"C");
+	}
+
         @putenv('LC_ALL=' . $lang_charset);
         @putenv('LANG=' . $lang_charset);
         @putenv('LANGUAGE=' . $lang_charset);
