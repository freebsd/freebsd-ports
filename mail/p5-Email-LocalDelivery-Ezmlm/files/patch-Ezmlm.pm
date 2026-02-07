 --- lib/Email/LocalDelivery/Ezmlm.pm.orig       Wed Sep 10 22:17:27 2003
 +++ lib/Email/LocalDelivery/Ezmlm.pm    Wed Sep 10 22:19:41 2003
 @@ -1,6 +1,6 @@
  use strict;
  package Email::LocalDelivery::Ezmlm;
 -our $VERSION = '0.10';
 +use vars qw($VERSION); $VERSION = '0.10';
  use File::Path qw(mkpath);
  use File::Basename qw( dirname );
 
 @@ -40,7 +40,8 @@
          # XXX should lock the folder - figure out how ezmlm does that
 
          my $num;
 -        if (open my $fh, "$folder/num") {
 +        use IO::Handle; my $fh = IO::Handle->new;
 +        if (open $fh, "$folder/num") {
              ($num) = (<$fh> =~ m/^(\d+)/);
          }
          ++$num;
 @@ -48,7 +49,7 @@
          my $filename = sprintf('%s/archive/%d/%02d',
                                 $folder, int $num / 100, $num % 100);
          eval { mkpath( dirname $filename ) };
 -        open my $fh, ">$filename" or next;
 +        open $fh, ">$filename" or next;
          print $fh $mail;
          close $fh or next;
 
