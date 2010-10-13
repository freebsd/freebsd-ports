--- smbldap_tools.pm.orig	2008-04-22 10:13:29.000000000 +0200
+++ smbldap_tools.pm	2010-10-13 10:50:48.831761476 +0200
@@ -92,6 +92,7 @@
   get_user_dn2
   connect_ldap_master
   connect_ldap_slave
+  group_name_by_type
   group_type_by_name
   subst_configvar
   read_config
@@ -825,9 +826,9 @@
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
@@ -1109,6 +1110,16 @@
     return $groupmap{$type_name};
 }
 
+sub group_name_by_type {
+    my $groupmap = shift;
+    my %type_name  = (
+        2 => 'domain',
+        4 => 'local',
+        5 => 'builtin'
+    );
+    return $type_name{$groupmap};
+}
+
 sub subst_user {
     my ( $str, $username ) = @_;
     $str =~ s/%U/$username/ if ($str);
@@ -1209,22 +1220,33 @@
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
