--- bin/verb_reverse.pl.orig	2014-09-18 02:46:59 UTC
+++ bin/verb_reverse.pl
@@ -9,8 +9,8 @@
 use strict;
 use locale;
 use utf8;
-use encoding 'utf8';
 
+binmode(STDOUT, ":utf8");
 
 my $UK_CAP	="'АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
 my $UK_LOW	="'абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
