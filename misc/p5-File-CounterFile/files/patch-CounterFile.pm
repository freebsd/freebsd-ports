--- CounterFile.pm.orig	Sun Jan 18 13:31:18 2004
+++ CounterFile.pm	Sun Jan 18 13:31:54 2004
@@ -19,7 +19,7 @@
 $DEFAULT_INITIAL = 0;                  # default initial counter value
 
  # default location for counter files
-$DEFAULT_DIR = $ENV{TMPDIR} || "/usr/tmp";
+$DEFAULT_DIR = $ENV{TMPDIR} || "/var/tmp";
 
 # Experimental overloading.
 use overload ('++'     => \&inc,
@@ -210,7 +210,7 @@
 If the file name does not start with "/" or ".", then it is
 interpreted as a file relative to C<$File::CounterFile::DEFAULT_DIR>.
 The default value for this variable is initialized from the
-environment variable C<TMPDIR>, or F</usr/tmp> if no environment
+environment variable C<TMPDIR>, or F</var/tmp> if no environment
 variable is defined.  You may want to assign a different value to this
 variable before creating counters.
 
