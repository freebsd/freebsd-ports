--- lib/Apache/PageKit/Content.pm.orig	Tue Oct 23 23:49:55 2001
+++ lib/Apache/PageKit/Content.pm	Thu Dec  6 15:13:16 2001
@@ -20,11 +20,6 @@
     require XML::LibXML;
     require XML::LibXSLT;
 
-    # call backs so that we can note the mtimes of dependant files
-    XML::LibXML->match_callback(\&match_uri);
-    XML::LibXML->open_callback(\&open_uri);
-    XML::LibXML->close_callback(\&close_uri);
-    XML::LibXML->read_callback(\&read_uri);
   }
 
   $CONTENT = $content;
@@ -62,6 +57,11 @@
 #  $INCLUDE_MTIMES->{$stylesheet_file} = $stylesheet_mtime;
 
   my $parser = XML::LibXML->new(ext_ent_handler => \&open_uri);
+    # call backs so that we can note the mtimes of dependant files
+    $parser->match_callback(\&match_uri);
+    $parser->open_callback(\&open_uri);
+    $parser->close_callback(\&close_uri);
+    $parser->read_callback(\&read_uri);
   my $xslt = XML::LibXSLT->new();
   my $source = $parser->parse_file("/$component_id.xml");
   my $style_doc = $parser->parse_file($stylesheet_file);
@@ -155,7 +155,7 @@
 
 sub match_uri {
   my $uri = shift;
-  return $uri !~ /^\w+:/;
+  return $uri !~ /(^\w+:)|(catalog$)/;
 }
 
 sub open_uri {
