--- ./aclocal.m4.orig	2013-11-13 18:25:50.000000000 +0000
+++ ./aclocal.m4	2013-11-24 17:58:35.428302772 +0000
@@ -79,7 +79,7 @@
 		s/^#.*$//m;
 		s/^\s+//gim;
 		s/\s+$/\n/gim;
-		s/\+$/\/rt3/gim;
+		s/\+$/\/rt42/gim;
 		# m4 will not let us just use $1, we need @S|@1
 		s/^\s*((?:bin|sbin|libexec|data|sysconf|sharedstate|localstate|lib|include|oldinclude|info|man|html)dir)\s*:\s*(.*)$/@S|@1=@S|@2/gim;
 		s/^\s*(.*?)\s*:\s*(.*)$/\(test "x\@S|@@S|@1" = "xNONE" || test "x\@S|@@S|@1" = "x") && @S|@1=@S|@2/gim;
