--- lib/CA.pm.orig	Tue Jul  1 00:33:18 2003
+++ lib/CA.pm	Tue Jul 15 17:05:35 2003
@@ -328,7 +328,7 @@
    };
 
    # create configuration file
-   my $in  = $self->{'init'}->{'templatedir'}."/openssl.cnf";
+   my $in  = $self->{'init'}->{'templatedir'}."/tinyca.cnf";
    my $out = $self->{$name}->{'dir'}."/openssl.cnf";
 
    open(IN, "<$in") || do {
