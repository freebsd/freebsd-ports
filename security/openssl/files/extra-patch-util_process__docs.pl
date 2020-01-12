--- util/process_docs.pl.orig	2018-09-11 12:48:25 UTC
+++ util/process_docs.pl
@@ -43,7 +43,7 @@ GetOptions(\%options,
           );
 
 unless ($options{section}) {
-    $options{section} = [ 1, 3, 5, 7 ];
+    $options{section} = [ 1, 5 ];
 }
 unless ($options{sourcedir}) {
     $options{sourcedir} = catdir($config{sourcedir}, "doc");
@@ -98,7 +98,7 @@ foreach my $section (sort @{$options{sec
         my $suffix = { man  => ".$podinfo{section}".($options{suffix} // ""),
                        html => ".html" } -> {$options{type}};
         my $generate = { man  => "pod2man --name=$name --section=$podinfo{section} --center=OpenSSL --release=$config{version} \"$podpath\"",
-                         html => "pod2html \"--podroot=$options{sourcedir}\" --htmldir=$updir --podpath=man1:man3:man5:man7 \"--infile=$podpath\" \"--title=$podname\" --quiet"
+                         html => "pod2html \"--podroot=$options{sourcedir}\" --htmldir=$updir --podpath=man1:man5 \"--infile=$podpath\" \"--title=$podname\" --quiet"
                          } -> {$options{type}};
         my $output_dir = catdir($options{destdir}, "man$podinfo{section}");
         my $output_file = $podname . $suffix;
