--- CounterFile.pm.orig	Tue Jul 30 23:45:06 2002
+++ CounterFile.pm	Sun Jul  6 08:08:46 2003
@@ -19,7 +19,7 @@
 $DEFAULT_INITIAL = 0;                  # default initial counter value
 
  # default location for counter files
-$DEFAULT_DIR = $ENV{TMPDIR} || "/usr/tmp";
+$DEFAULT_DIR = $ENV{TMPDIR} || "/var/tmp";
 
 # Experimental overloading.
 use overload ('++'     => \&inc,
@@ -205,7 +205,7 @@
 If the file name does not start with "/" or ".", then it is
 interpreted as a file relative to C<$File::CounterFile::DEFAULT_DIR>.
 The default value for this variable is initialized from the
-environment variable C<TMPDIR>, or F</usr/tmp> is no environment
+environment variable C<TMPDIR>, or F</var/tmp> is no environment
 variable is defined.  You may want to assign a different value to this
 variable before creating counters.
 
