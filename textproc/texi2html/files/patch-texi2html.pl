--- texi2html.pl.old	Sat Dec 13 07:39:45 2003
+++ texi2html.pl	Sat Dec 13 07:40:11 2003
@@ -174,7 +174,6 @@
             $ext
             $extensions
             $failed
-            $fh_name
             $file
             $first_index_chapter
             $first_line
@@ -4127,25 +4126,22 @@
 sub open
 {
     my($name) = @_;
+    local *FH;
 
-    ++$fh_name;
-    no strict "refs";
-    if (open($fh_name, $name))
+    if (open(*FH, $name))
     {
-        unshift(@fhs, $fh_name);
+        unshift(@fhs, *FH);
     }
     else
     {
         warn "$ERROR Can't read file $name: $!\n";
     }
-    use strict "refs";
 }
 
 sub init_input
 {
     @fhs = ();			# hold the file handles to read
     @input_spool = ();		# spooled lines to read
-    $fh_name = 'FH000';
     &open($docu);
 }
 
@@ -4420,9 +4416,8 @@
         if ($style =~ /^\&/)
         {                       # custom
             $style = $';
-            no strict "refs";
-            $text = &$style($text, $texi_style);
-            use strict "refs";
+            eval "\$text = &$style(\$text, \$texi_style)";
+            die $@ if $@;
         }
         elsif ($style)
         {                       # good style
