+--- lib/Text/PDF/FileAPI.pm.orig       Thu Oct 31 15:46:58 2002
++++ lib/Text/PDF/FileAPI.pm    Thu Oct 31 15:47:06 2002
+@@ -3,7 +3,6 @@
+ use strict;
+ no strict "refs";
+ use vars qw($cr %types $VERSION @ISA);
+-no warnings qw(uninitialized);
+
+ use IO::File;
+
