--- inst/apache.pl.orig	Sat May 22 14:47:57 2004
+++ inst/apache.pl	Sat May 22 14:55:05 2004
@@ -36,6 +36,10 @@
 use File::Spec::Functions;
 use Data::Dumper;
 
+# check whether questions should be asked
+our $QUIET;
+$QUIET = 1 if $ARGV[0] and $ARGV[0] eq 'QUIET';
+
 print "\n\n==> Probing Apache Configuration <==\n\n";
 
 our %AP;
@@ -290,17 +294,25 @@
 
 END
 
-    ask_confirm("Apache User:\t\t\t",  \$AP{user});
-    ask_confirm("Apache Group:\t\t\t", \$AP{group});
-    ask_confirm("Apache Port:\t\t\t",  \$AP{port});
-    ask_confirm("Apache Server Name:\t\t",  \$AP{server_name});
+    if ($QUIET) {
+        print "Apache User:\t\t\t".  $AP{user}."\n";
+        print "Apache Group:\t\t\t". $AP{group}."\n";
+        print "Apache Port:\t\t\t".  $AP{port}."\n";
+        print "Apache Server Name:\t\t". $AP{server_name}."\n";
+    }
+    else {
+        ask_confirm("Apache User:\t\t\t",  \$AP{user});
+        ask_confirm("Apache Group:\t\t\t", \$AP{group});
+        ask_confirm("Apache Port:\t\t\t",  \$AP{port});
+        ask_confirm("Apache Server Name:\t\t",  \$AP{server_name});
+    }
 
     # install fails if this is wrong
     $AP{ssl_key} = catfile($AP{HTTPD_ROOT}, "conf", "ssl.key", "server.key");
     $AP{ssl_cert} = catfile($AP{HTTPD_ROOT}, "conf", "ssl.crt","server.crt");
 
     if ($AP{ssl} or $AP{apache_ssl}) {
-        if (ask_yesno("Do you want to use SSL? [no] ", 0)) {
+        if (!$QUIET and ask_yesno("Do you want to use SSL? [no] ", 0)) {
             if ($AP{ssl} and $AP{apache_ssl}) {
                 $AP{ssl} = ask_choice("Which SSL module do you use? " .
                                       "(apache_ssl or mod_ssl) ",
