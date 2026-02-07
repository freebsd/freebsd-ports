--- texi2html.pl	2012-07-09 10:54:41.000000000 +0200
+++ /usr/local/bin/texi2html	2012-07-09 10:53:16.000000000 +0200
@@ -1993,6 +1933,11 @@
     # Messages should be untranslated for tests.
     Locale::Messages::bindtextdomain ($messages_textdomain, "$datadir/locale");
 }
+else
+{
+    unshift @INC, "$pkgdatadir/lib/libintl-perl/lib";
+    require Locale::Messages;
+}
 
 sub __($)
 {
