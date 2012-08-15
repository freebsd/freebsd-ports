--- Makefile.PL.orig	2012-07-23 01:47:59.000000000 +0400
+++ Makefile.PL	2012-08-13 11:36:04.404805799 +0400
@@ -105,12 +105,12 @@
         INSTALLLIB           => '$(DATADIR)/lib',
         INSTALLSITELIB       => '$(DATADIR)/lib',
         INSTALLVENDORLIB     => '$(DATADIR)/lib',
-        INSTALLMAN1DIR       => '$(PREFIX)/share/man/man1',
-        INSTALLSITEMAN1DIR   => '$(PREFIX)/share/man/man1',
-        INSTALLVENDORMAN1DIR => '$(PREFIX)/share/man/man1',
-        INSTALLMAN3DIR       => '$(PREFIX)/share/man/man3',
-        INSTALLSITEMAN3DIR   => '$(PREFIX)/share/man/man3',
-        INSTALLVENDORMAN3DIR => '$(PREFIX)/share/man/man3',
+        INSTALLMAN1DIR       => '$(PREFIX)/man/man1',
+        INSTALLSITEMAN1DIR   => '$(PREFIX)/man/man1',
+        INSTALLVENDORMAN1DIR => '$(PREFIX)/man/man1',
+        INSTALLMAN3DIR       => '$(PREFIX)/man/man3',
+        INSTALLSITEMAN3DIR   => '$(PREFIX)/man/man3',
+        INSTALLVENDORMAN3DIR => '$(PREFIX)/man/man3',
         SYSCONFDIR           => '$(PREFIX)/etc/fusioninventory',
         DATADIR              => '$(PREFIX)/share/fusioninventory',
         LOCALSTATEDIR        => '$(PREFIX)/var/fusioninventory',
@@ -201,7 +201,7 @@
     $manifypods =~ s/manifypods : pure_all/manifypods : pure_all fusioninventory-agent.1.html/;
     $manifypods .= <<'EOF';
 fusioninventory-agent.1.html: fusioninventory-agent
-	pod2html --infile=$< --outfile=$@
+	pod2html --infile=$? --outfile=$@
 
 EOF
     return $manifypods;
