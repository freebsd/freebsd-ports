--- tp/Texinfo/ParserNonXS.pm.orig	2023-01-22 10:42:42 UTC
+++ tp/Texinfo/ParserNonXS.pm
@@ -4357,7 +4357,7 @@ sub _process_remaining_on_line($$$$)
             and ($current->{'parent'}->{'type'} eq 'menu_comment'
                  or $current->{'parent'}->{'type'} eq 'menu_entry_description')
             and $asterisk
-            and @{$current->{'contents'}}
+            and $current->{'contents'}
             and $current->{'contents'}->[-1]->{'type'}
             and $current->{'contents'}->[-1]->{'type'} eq 'empty_line'
             and $current->{'contents'}->[-1]->{'text'} eq '') {
