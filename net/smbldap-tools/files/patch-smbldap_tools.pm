--- smbldap_tools.pm.orig	2008-04-22 10:13:29.000000000 +0200
+++ smbldap_tools.pm	2010-10-05 12:53:27.592346981 +0200
@@ -825,9 +825,9 @@
         $lines .= "dn: " . $entry->dn . "\n";
         foreach my $attr ( $entry->attributes ) {
             my @vals = $entry->get_value($attr);
-            foreach my $val (@vals) {
-                $val = "**UNPRINTABLE**" if ( $val =~ /[^[:print:]]/ );
-            }
+#            foreach my $val (@vals) {
+#                $val = "**UNPRINTABLE**" if ( $val =~ /[^[:print:]]/ );
+#            }
             $lines .= $attr . ": " . join( ',', @vals ) . "\n";
         }
     }
@@ -1209,22 +1209,33 @@
 }
 
 sub utf8Encode {
-    my $arg = shift;
+    my $charset = shift;
+    my $string = shift;
 
-    return to_utf8(
-        -string  => $arg,
-        -charset => 'ISO-8859-1',
-    );
+    if ($charset eq "UTF-8") {
+	return $string;
+    }
+    else {
+	return to_utf8(
+	    -string  => $string,
+	    -charset => $charset,
+	);
+    }
 }
 
 sub utf8Decode {
-    my $arg = shift;
+    my $charset = shift;
+    my $string = shift;
 
-    return from_utf8(
-        -string  => $arg,
-        -charset => 'ISO-8859-1',
-    );
+    if ($charset eq "UTF-8") {
+	return $string;
+    }
+    else {
+	return from_utf8(
+	    -string  => $string,
+	    -charset => $charset,
+	);
+    }
 }
 
 1;
-
