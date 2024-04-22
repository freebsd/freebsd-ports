--- Makefile.PL.orig	2024-02-06 02:12:51 UTC
+++ Makefile.PL
@@ -14,8 +14,8 @@ my %WriteMakefileArgs = (
   },
   "DISTNAME" => "Mail-SPF",
   "EXE_FILES" => [
-    "bin/spfd",
-    "bin/spfquery"
+    "bin/spfd.pl",
+    "bin/spfquery.pl"
   ],
   "LICENSE" => "bsd",
   "NAME" => "Mail::SPF",
