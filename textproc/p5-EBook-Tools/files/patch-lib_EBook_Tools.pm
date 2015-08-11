--- lib/EBook/Tools.pm.orig	2014-10-01 22:27:01 UTC
+++ lib/EBook/Tools.pm
@@ -11710,6 +11710,7 @@ Returns the return value from tidy
                        '-q','-utf8','--tidy-mark','no',
                        '--wrap','0',
                        '-xml',
+                       '-indent',
                        '--add-xml-decl','yes',
                        '-f',$tidyxmlerrors,
                        '-o',$outfile,
