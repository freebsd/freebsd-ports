--- Makefile.PL.orig	2022-07-08 08:59:56 UTC
+++ Makefile.PL
@@ -321,6 +321,11 @@ sub get_constants_headers
 				warn "Skipping '$_': does not define a symbol";
 				next;
 			}
+			if (m{^#\s*define\s+(CURL.+?DEPRECA\w+)}) {
+				chomp;
+				warn "Skipping '$_': does not define a symbol";
+				next;
+			}
 
 			m{^#\s*define\s+(CURL\w*)} and $syms{$1}++;
 		}
