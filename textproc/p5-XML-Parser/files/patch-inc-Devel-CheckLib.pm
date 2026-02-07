--- inc/Devel/CheckLib.pm.orig	2023-12-28 19:47:02 UTC
+++ inc/Devel/CheckLib.pm
@@ -315,7 +315,7 @@ sub _make_cfile {
 	warn "# Code:\n$c\n";
     }
     my ($ch, $cfile) = File::Temp::tempfile(
-	'assertlibXXXXXXXX', SUFFIX => '.c'
+	'assertlibXXXXXXXX', SUFFIX => '.c', TMPDIR => 1
     );
     print $ch $code;
     close $ch;
