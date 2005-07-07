127+128 is 255, which no `char' can exceed. This leads to a compiler
warning...

--- lib/iso2022_map.c	Tue Mar 30 11:38:43 2004
+++ lib/iso2022_map.c	Wed Jul  6 23:43:14 2005
@@ -926,5 +926,5 @@
 		if (iso2022_94 == Mx->type ||
 		    iso2022_96 == Mx->type) {
-		    if (ch < 32 + 128 || ch > 127 + 128) {
+		    if (ch < 32 + 128) {
 			DPRINT(Debug,10,(&Debug,
 					 "map_unicode_to_ISO2022_word_1: char %c (unicode %u)  out of range (type iso2022_94 or iso2022_96, PF_BUILTIN_upper)",
