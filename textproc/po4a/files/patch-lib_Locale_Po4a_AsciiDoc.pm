# https://github.com/mquinson/po4a/pull/298
# Asciidoc: Don't split in attributes include:: and ifeval:: lines
--- lib/Locale/Po4a/AsciiDoc.pm.orig	2021-02-22 16:53:34 UTC
+++ lib/Locale/Po4a/AsciiDoc.pm
@@ -771,6 +771,10 @@ sub parse {
                 and ( defined( $self->{type} ) and ( $self->{type} eq "Table" ) ) )
             {
                 $paragraph .= $line . "\n";
+            } elsif (    ( $macroname eq "include" || $macroname eq "ifeval" )
+                and ( $macrotype eq '::' ) )
+            {
+                $self->pushline( $line . "\n" );
             } else {
                 if ( $macrotype eq '::' ) {
                     do_paragraph( $self, $paragraph, $wrapped_mode );
