--- osquery/extensions/tests/extensions_tests.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/extensions/tests/extensions_tests.cpp
@@ -30,16 +30,17 @@ const std::string kTestManagerSocket = k
 class ExtensionsTest : public testing::Test {
  protected:
   void SetUp() {
-    remove(kTestManagerSocket);
-    if (pathExists(kTestManagerSocket).ok()) {
-      throw std::domain_error("Cannot test sockets: " + kTestManagerSocket);
+    socket_path = kTestManagerSocket + std::to_string(rand());
+    remove(socket_path);
+    if (pathExists(socket_path).ok()) {
+      throw std::domain_error("Cannot test sockets: " + socket_path);
     }
   }
 
   void TearDown() {
-    Dispatcher::removeServices();
+    Dispatcher::stopServices();
     Dispatcher::joinServices();
-    remove(kTestManagerSocket);
+    remove(socket_path);
   }
 
   bool ping(int attempts = 3) {
@@ -47,7 +48,7 @@ class ExtensionsTest : public testing::T
     ExtensionStatus status;
     for (int i = 0; i < attempts; ++i) {
       try {
-        EXManagerClient client(kTestManagerSocket);
+        EXManagerClient client(socket_path);
         client.get()->ping(status);
         return (status.code == ExtensionCode::EXT_SUCCESS);
       } catch (const std::exception& e) {
@@ -63,7 +64,7 @@ class ExtensionsTest : public testing::T
     ExtensionResponse response;
     for (int i = 0; i < attempts; ++i) {
       try {
-        EXManagerClient client(kTestManagerSocket);
+        EXManagerClient client(socket_path);
         client.get()->query(response, sql);
       } catch (const std::exception& e) {
         ::usleep(kDelayUS);
@@ -81,7 +82,7 @@ class ExtensionsTest : public testing::T
   ExtensionList registeredExtensions(int attempts = 3) {
     ExtensionList extensions;
     for (int i = 0; i < attempts; ++i) {
-      if (getExtensions(kTestManagerSocket, extensions).ok()) {
+      if (getExtensions(socket_path, extensions).ok()) {
         break;
       }
     }
@@ -101,34 +102,37 @@ class ExtensionsTest : public testing::T
     }
     return false;
   }
+
+ public:
+  std::string socket_path;
 };
 
 TEST_F(ExtensionsTest, test_manager_runnable) {
   // Start a testing extension manager.
-  auto status = startExtensionManager(kTestManagerSocket);
+  auto status = startExtensionManager(socket_path);
   EXPECT_TRUE(status.ok());
   // Call success if the Unix socket was created.
-  EXPECT_TRUE(socketExists(kTestManagerSocket));
+  EXPECT_TRUE(socketExists(socket_path));
 }
 
 TEST_F(ExtensionsTest, test_extension_runnable) {
-  auto status = startExtensionManager(kTestManagerSocket);
+  auto status = startExtensionManager(socket_path);
   EXPECT_TRUE(status.ok());
   // Wait for the extension manager to start.
-  EXPECT_TRUE(socketExists(kTestManagerSocket));
+  EXPECT_TRUE(socketExists(socket_path));
 
   // Test the extension manager API 'ping' call.
   EXPECT_TRUE(ping());
 }
 
 TEST_F(ExtensionsTest, test_extension_start) {
-  auto status = startExtensionManager(kTestManagerSocket);
+  auto status = startExtensionManager(socket_path);
   EXPECT_TRUE(status.ok());
-  EXPECT_TRUE(socketExists(kTestManagerSocket));
+  EXPECT_TRUE(socketExists(socket_path));
 
   // Now allow duplicates (for testing, since EM/E are the same).
   Registry::allowDuplicates(true);
-  status = startExtension(kTestManagerSocket, "test", "0.1", "0.0.0", "0.0.1");
+  status = startExtension(socket_path, "test", "0.1", "0.0.0", "0.0.1");
   // This will not be false since we are allowing deplicate items.
   // Otherwise, starting an extension and extensionManager would fatal.
   ASSERT_TRUE(status.ok());
@@ -138,7 +142,7 @@ TEST_F(ExtensionsTest, test_extension_st
   RouteUUID uuid = (RouteUUID)stoi(status.getMessage(), nullptr, 0);
 
   // We can test-wait for the extensions's socket to open.
-  EXPECT_TRUE(socketExists(kTestManagerSocket + "." + std::to_string(uuid)));
+  EXPECT_TRUE(socketExists(socket_path + "." + std::to_string(uuid)));
 
   // Then clean up the registry modifications.
   Registry::removeBroadcast(uuid);
@@ -160,9 +164,9 @@ class TestExtensionPlugin : public Exten
 CREATE_REGISTRY(ExtensionPlugin, "extension_test");
 
 TEST_F(ExtensionsTest, test_extension_broadcast) {
-  auto status = startExtensionManager(kTestManagerSocket);
+  auto status = startExtensionManager(socket_path);
   EXPECT_TRUE(status.ok());
-  EXPECT_TRUE(socketExists(kTestManagerSocket));
+  EXPECT_TRUE(socketExists(socket_path));
 
   // This time we're going to add a plugin to the extension_test registry.
   Registry::add<TestExtensionPlugin>("extension_test", "test_item");
@@ -180,7 +184,7 @@ TEST_F(ExtensionsTest, test_extension_br
   EXPECT_TRUE(Registry::exists("extension_test", "test_item"));
   EXPECT_FALSE(Registry::exists("extension_test", "test_alias"));
 
-  status = startExtension(kTestManagerSocket, "test", "0.1", "0.0.0", "0.0.1");
+  status = startExtension(socket_path, "test", "0.1", "0.0.0", "0.0.1");
   EXPECT_TRUE(status.ok());
 
   RouteUUID uuid;
@@ -191,7 +195,7 @@ TEST_F(ExtensionsTest, test_extension_br
     return;
   }
 
-  auto ext_socket = kTestManagerSocket + "." + std::to_string(uuid);
+  auto ext_socket = socket_path + "." + std::to_string(uuid);
   EXPECT_TRUE(socketExists(ext_socket));
 
   // Make sure the EM registered the extension (called in start extension).
