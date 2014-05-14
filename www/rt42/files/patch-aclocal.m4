--- ./aclocal.m4.orig	2014-05-06 17:59:04.000000000 +0100
+++ ./aclocal.m4	2014-05-14 15:26:37.710277502 +0100
@@ -79,7 +79,7 @@
 		s/^#.*$//m;
 		s/^\s+//gim;
 		s/\s+$/\n/gim;
-		s/\+$/\/rt3/gim;
+		s/\+$/\/rt42/gim;
 		# m4 will not let us just use $1, we need @S|@1
 		s/^\s*((?:bin|sbin|libexec|data|sysconf|sharedstate|localstate|lib|include|oldinclude|info|man|html)dir)\s*:\s*(.*)$/@S|@1=@S|@2/gim;
 		s/^\s*(.*?)\s*:\s*(.*)$/\(test "x\@S|@@S|@1" = "xNONE" || test "x\@S|@@S|@1" = "x") && @S|@1=@S|@2/gim;
