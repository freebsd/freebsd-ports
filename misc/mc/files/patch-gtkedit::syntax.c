--- gtkedit/syntax.c.orig	Sun Sep 29 16:55:01 2002
+++ gtkedit/syntax.c	Sun Sep 29 16:55:06 2002
@@ -1211,7 +1211,7 @@
 "file ..\\*\\\\.lsm$ LSM\\sFile",
 "include lsm.syntax",
 "",
-"file ..\\*\\\\.sh$ Shell\\sScript ^#!\\s\\*/.\\*/(k|ba||pdk|z)sh",
+"file ..\\*\\\\.sh$ Shell\\sScript ^#!\\s\\*/.\\*/([a-z]?|ba|pdk)sh",
 "include sh.syntax",
 "",
 "file ..\\*\\\\.(pl|PL|pm|PM])$ Perl\\sProgram ^#!\\s\\*/.\\*/perl",
