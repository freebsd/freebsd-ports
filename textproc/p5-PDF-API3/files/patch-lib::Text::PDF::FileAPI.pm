--- lib/Text/PDF/FileAPI.pm.orig       Fri Nov  1 13:01:57 2002
+++ lib/Text/PDF/FileAPI.pm    Fri Nov  1 13:02:03 2002
@@ -3,7 +3,6 @@
 use strict;
 no strict "refs";
 use vars qw($cr %types $VERSION @ISA);
-no warnings qw(uninitialized);

 use IO::File;

