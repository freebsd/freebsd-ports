--- base/strings/safe_sprintf_unittest.cc.orig	2013-11-08 07:42:08.000000000 +0100
+++ base/strings/safe_sprintf_unittest.cc	2013-11-15 15:04:45.000000000 +0100
@@ -733,12 +733,14 @@
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wconversion-null"
 #endif
+/* Avoid compiler error: http://pastebin.com/1edWUE84
   EXPECT_EQ(1, SafeSPrintf(buf, "%d", NULL));
   EXPECT_EQ("0", std::string(buf));
   EXPECT_EQ(3, SafeSPrintf(buf, "%p", NULL));
   EXPECT_EQ("0x0", std::string(buf));
   EXPECT_EQ(6, SafeSPrintf(buf, "%s", NULL));
   EXPECT_EQ("<NULL>", std::string(buf));
+*/
 #if defined(__GCC__)
 #pragma GCC diagnostic pop
 #endif
