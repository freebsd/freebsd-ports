--- cgi-bin/openwebmail/ow-shared.pl.orig	Tue Nov 26 20:20:51 2002
+++ cgi-bin/openwebmail/ow-shared.pl	Sat Dec 21 01:07:47 2002
@@ -231,6 +231,9 @@
 sub readconf {
    my ($r_config, $r_config_raw, $configfile)=@_;
 
+   if ($configfile=~/\.\./) {	# .. in path is not allowed for higher security
+      openwebmailerror("Invalid config file path $configfile");
+   }
    # read config
    open(CONFIG, $configfile) or
       openwebmailerror("Couldn't open config file $configfile");
@@ -340,6 +343,11 @@
       }
    }
 
+   # remove / and .. from variables that will be used in require statement for security
+   foreach $key ( 'default_language', 'auth_module') {
+      ${$r_config}{$key} =~ s|/||g;
+      ${$r_config}{$key} =~ s|\.\.||g;
+   }
    # untaint pathname variable defined in openwebmail.conf
    foreach $key ( 'smtpserver', 'auth_module', 'virtusertable',
                   'mailspooldir', 'homedirspoolname', 'homedirfolderdirname',
