--- Tests/Unit/TestNGMimeAddressHeaderFieldGenerator.m.orig	2015-09-16 18:41:31 UTC
+++ Tests/Unit/TestNGMimeAddressHeaderFieldGenerator.m
@@ -39,8 +39,8 @@
         @"<wolfgang@test.com>",  // email between brackets
         @"\"<wolfgang@test.com>\" <wolfgang@test.com>", // doubled
         @"\"wolfgang@inverse.ca\" <wolfgang@test.com>", // with and without br.
-        @"Àñinéoblabla <wolfgang@test.com>", // accented full name
-        @"Àñinéoblabla Bla Blé <wolfgang@test.com>", // accented and multiword
+        @"=?utf-8?q?=C3=80=C3=B1in=C3=A9oblabla?= <wolfgang@test.com>", // accented full name
+        @"=?utf-8?q?=C3=80=C3=B1in=C3=A9oblabla_Bla_Bl=C3=A9?= <wolfgang@test.com>", // accented and multiword
         @"Wolfgang Sourdeau \"Bla Bla\" <wolfgang@test.com>", // partly quoted
         @"Wolfgang Sourdeau <wolfgang@test.com>", // full name + email
         nil };
@@ -50,8 +50,7 @@
         @"\"<wolfgang@test.com>\" <wolfgang@test.com>", // doubled
         @"\"wolfgang@inverse.ca\" <wolfgang@test.com>", // with and without br.
         @"=?utf-8?q?=C3=80=C3=B1in=C3=A9oblabla?= <wolfgang@test.com>", // accented full name
-        @"=?utf-8?q?=C3=80=C3=B1in=C3=A9oblabla_Bla_Bl=C3=A9?= <wolfgang@test.com>", // accented
-        // and multiword
+        @"=?utf-8?q?=C3=80=C3=B1in=C3=A9oblabla_Bla_Bl=C3=A9?= <wolfgang@test.com>", // accented and multiword
 
         /* NOTE: the following are wrong but tolerated for now */
         @"Wolfgang Sourdeau \"Bla Bla\" <wolfgang@test.com>", // partly quoted
