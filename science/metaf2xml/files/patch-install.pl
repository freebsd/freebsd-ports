--- install.pl.orig	2017-06-23 13:29:20 UTC
+++ install.pl
@@ -658,7 +658,7 @@ if ($cmd eq 'all' || $cmd eq 'cgi') {
         if ($USE_CP) {
             do_copy "$BUILD_ROOT$METAF2XML_XSL/$_", "$BUILD_ROOT$HTDOCS_DIR/";
         } else {
-            $symlink->("$METAF2XML_XSL/$_", "$BUILD_ROOT$HTDOCS_DIR/$_")
+            $symlink->("%%METAF2XML_XSL%%/$_", "$BUILD_ROOT$HTDOCS_DIR/$_")
                 or usage "ERROR: symlink '$BUILD_ROOT$HTDOCS_DIR/$_': $!\n";
         }
     }
@@ -667,7 +667,7 @@ if ($cmd eq 'all' || $cmd eq 'cgi') {
     if ($USE_CP) {
         do_copy "$BUILD_ROOT$METAF2XML_BIN/metaf.pl","$BUILD_ROOT$CGI_BIN_DIR/";
     } else {
-        $symlink->("$METAF2XML_BIN/metaf.pl","$BUILD_ROOT$CGI_BIN_DIR/metaf.pl")
+        $symlink->("%%METAF2XML_BIN%%/metaf.pl","$BUILD_ROOT$CGI_BIN_DIR/metaf.pl")
             or usage "ERROR: symlink '$BUILD_ROOT$CGI_BIN_DIR/metaf.pl': $!\n";
     }
 
