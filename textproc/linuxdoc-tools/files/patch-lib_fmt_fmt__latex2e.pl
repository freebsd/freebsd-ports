--- lib/fmt/fmt_latex2e.pl.orig	2018-03-28 15:14:45 UTC
+++ lib/fmt/fmt_latex2e.pl
@@ -284,13 +284,13 @@ $latex2e->{postASP} = sub
       push @texlines, $_;
       # and check for nameurl
       if ( /\\nameurl/ ){
-	($urlid, $urlnam) = ($_ =~ /\\nameurl{(.*)}{(.*)}/);
+	($urlid, $urlnam) = ($_ =~ /\\nameurl\{(.*)\}\{(.*)\}/);
 	print $urlnum . ": " . $urlid . "\n" if ( $global->{debug} );
 
 	$urldef = latex2e_defnam($urlnum) . "url";
-	s/\\nameurl{.*}{.*}/{\\em $urlnam} {\\tt \\$urldef}/;
+	s/\\nameurl\{.*\}\{.*\}/{\\em $urlnam} {\\tt \\$urldef}/;
 	push @urlnames, $_;
-	push @urldefines, "\\urldef{\\$urldef} \\url{$urlid}\n";
+	push @urldefines, "\\urldef\{\\$urldef\} \\url\{$urlid\}\n";
 	$urlnum++;
       }
     }
@@ -367,12 +367,12 @@ $latex2e->{postASP} = sub
 	    $_ = $_ . "\\makeindex\n" if ($latex2e->{makeindex});
 	  }
 	  # Set correct DTD name
-	  elsif (/^\\usepackage{\@LINUXDOC_DTD\@-sgml}/) {
+	  elsif (/^\\usepackage\{\@LINUXDOC_DTD\@-sgml\}/) {
 	    my $dtd = $global->{"dtd"};
 	    s/\@LINUXDOC_DTD\@/$dtd/;
 	  }
 	  # Set correct babel options
-	  elsif (/^\\usepackage\[\@BABELOPTIONS\@\]{babel}/) {
+	  elsif (/^\\usepackage\[\@BABELOPTIONS\@\]\{babel\}/) {
 	    if ( $babeloptions ) {
 	      s/\@BABELOPTIONS\@/$babeloptions/;
 	    } else {
