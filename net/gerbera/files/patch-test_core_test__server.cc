--- test/core/test_server.cc.orig	2020-07-27 06:07:30 UTC
+++ test/core/test_server.cc
@@ -51,17 +51,6 @@ TEST_F(ServerTest, ServerOutputsHelpInformation)
     ASSERT_THAT(output.c_str(), HasSubstr(expectedOutput.c_str()));
 }
 
-TEST_F(ServerTest, ServerOutputsCompileInformationIncludingGit)
-{
-    fs::path cmd = fs::path(CMAKE_BINARY_DIR) / "gerbera --compile-info 2>&1";
-    std::string output = exec(cmd.c_str());
-
-    ASSERT_THAT(output, HasSubstr("Compile info\n-------------\nWITH_"));
-    ASSERT_THAT(output, HasSubstr("Git info:\n-------------\n"));
-    ASSERT_THAT(output, HasSubstr("Git Branch: "));
-    ASSERT_THAT(output, HasSubstr("Git Commit: "));
-}
-
 TEST_F(ServerTest, GeneratesFullConfigFromServerCommand)
 {
     // simple check to ensure complete generation from server
