
$FreeBSD$

--- maketemp.pl.orig	Wed Sep 15 00:00:08 2004
+++ maketemp.pl	Wed Sep 15 00:00:19 2004
@@ -3,17 +3,16 @@
 
 $tmp_dir = $ENV{'tempdir'} || "/tmp/.webmin";
 
-if (!-d $tmp_dir) {
-	mkdir($tmp_dir, 0755) || exit 1;
-	}
-chown($<, $(, $tmp_dir);
-chmod(0755, $tmp_dir);
-@st = lstat($tmp_dir);
-if (@st && $st[4] == $< && (-d _) &&
-    ($st[2] & 0777) == 0755) {
-	exit 0;
-	}
-else {
-	exit 1;
+while($tries++ < 10) {
+	local @st = lstat($tmp_dir);
+	exit(0) if ($st[4] == $< && (-d _) && ($st[2] & 0777) == 0755);
+	if (@st) {
+		unlink($tmp_dir) || rmdir($tmp_dir) ||
+			system("/bin/rm -rf ".quotemeta($tmp_dir));
+		}
+	mkdir($tmp_dir, 0755) || next;
+	chown($<, $(, $tmp_dir);
+	chmod(0755, $tmp_dir);
 	}
+exit(1);
 
