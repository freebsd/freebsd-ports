-- Make the Catch2 test runner compatible with Catch2 v2 from devel/catch.
-- Catch::Session::OnUnusedOptions and unusedTokens() are not available there.

--- test/all_tests.cpp.orig	2026-09-24 16:52:34 UTC
+++ test/all_tests.cpp
@@ -36,17 +36,10 @@ int main(int argc, char* const argv[])

 int main(int argc, char* const argv[])
 {
-    Catch::Session session;
-
-    int returnCode = session.applyCommandLine(argc, argv, Catch::Session::OnUnusedOptions::Ignore);
-    if (returnCode != 0)
-        return returnCode;
-
-    for (auto token : session.unusedTokens()) {
-        printf("Token: %s\n", token.data.c_str());
-        if (token.data == "EXTENSIVE")
+    for (int i = 1; i < argc; i++) {
+        if (strcmp(argv[i], "EXTENSIVE") == 0)
             CHAIN_EXTENSIVE = true;
     }

-    return session.run();
+    return Catch::Session().run(argc, argv);
 }
