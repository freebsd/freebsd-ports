--- cgi-bin/openwebmail/openwebmail-tool.pl.orig	Wed Dec 18 21:10:06 2002
+++ cgi-bin/openwebmail/openwebmail-tool.pl	Wed Dec 18 21:14:14 2002
@@ -325,6 +325,7 @@
       print "done.\n";
    }
 
+   return 0;
    my $id = $ENV{'USER'} || $ENV{'LOGNAME'} || getlogin || (getpwuid($>))[0];
    my $hostname=hostname();
    my $realname=(getpwnam($id))[6]||$id;
