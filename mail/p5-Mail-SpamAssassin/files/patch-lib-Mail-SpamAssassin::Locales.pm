--- lib/Mail/SpamAssassin/Locales.pm.bak	Tue Jan 22 04:27:46 2002
+++ lib/Mail/SpamAssassin/Locales.pm	Tue Feb 26 12:58:16 2002
@@ -62,7 +62,7 @@
     $locale =~ s/^([a-z][a-z]).*$/$1/;	# zh_TW... => zh
 
     my $ok_for_loc = $charsets_for_locale{$locale};
-    return 0 if (!defined $ok_for_loc);
+    next if (!defined $ok_for_loc);
 
     if ($ok_for_loc =~ /(?:^| )\Q${cs}\E(?:$| )/) {
       return 1;
