--- osquery/extensions/interface.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/extensions/interface.cpp
@@ -173,89 +173,56 @@ bool ExtensionManagerHandler::exists(con
 }
 }
 
-ExtensionRunner::~ExtensionRunner() { remove(path_); }
+ExtensionRunnerCore::~ExtensionRunnerCore() { remove(path_); }
 
-void ExtensionRunner::enter() {
-  // Set the socket information for the extension manager.
-  auto socket_path = path_;
+void ExtensionRunnerCore::stop() {
+  if (server_ != nullptr) {
+    server_->stop();
+  }
+}
 
-  // Create the thrift instances.
-  OSQUERY_THRIFT_POINTER::shared_ptr<ExtensionHandler> handler(
-      new ExtensionHandler(uuid_));
-  OSQUERY_THRIFT_POINTER::shared_ptr<TProcessor> processor(
-      new ExtensionProcessor(handler));
-  OSQUERY_THRIFT_POINTER::shared_ptr<TServerTransport> serverTransport(
-      new TServerSocket(socket_path));
-  OSQUERY_THRIFT_POINTER::shared_ptr<TTransportFactory> transportFactory(
-      new TBufferedTransportFactory());
-  OSQUERY_THRIFT_POINTER::shared_ptr<TProtocolFactory> protocolFactory(
-      new TBinaryProtocolFactory());
+void ExtensionRunnerCore::startServer(TProcessorRef processor) {
+  auto transport = TServerTransportRef(new TServerSocket(path_));
+  auto transport_fac = TTransportFactoryRef(new TBufferedTransportFactory());
+  auto protocol_fac = TProtocolFactoryRef(new TBinaryProtocolFactory());
 
-  OSQUERY_THRIFT_POINTER::shared_ptr<ThreadManager> threadManager =
-      ThreadManager::newSimpleThreadManager(FLAGS_worker_threads);
-  OSQUERY_THRIFT_POINTER::shared_ptr<PosixThreadFactory> threadFactory =
-      OSQUERY_THRIFT_POINTER::shared_ptr<PosixThreadFactory>(
-          new PosixThreadFactory());
-  threadManager->threadFactory(threadFactory);
-  threadManager->start();
+  auto thread_manager_ =
+      ThreadManager::newSimpleThreadManager((size_t)FLAGS_worker_threads, 0);
+  auto thread_fac = ThriftThreadFactory(new PosixThreadFactory());
+  thread_manager_->threadFactory(thread_fac);
+  thread_manager_->start();
 
   // Start the Thrift server's run loop.
+  server_ = TThreadPoolServerRef(new TThreadPoolServer(
+      processor, transport, transport_fac, protocol_fac, thread_manager_));
+  server_->serve();
+}
+
+void ExtensionRunner::start() {
+  // Create the thrift instances.
+  auto handler = ExtensionHandlerRef(new ExtensionHandler(uuid_));
+  auto processor = TProcessorRef(new ExtensionProcessor(handler));
+
+  VLOG(1) << "Extension service starting: " << path_;
   try {
-    VLOG(1) << "Extension service starting: " << socket_path;
-    TThreadPoolServer server(processor,
-                             serverTransport,
-                             transportFactory,
-                             protocolFactory,
-                             threadManager);
-    server.serve();
+    startServer(processor);
   } catch (const std::exception& e) {
-    LOG(ERROR) << "Cannot start extension handler: " << socket_path << " ("
+    LOG(ERROR) << "Cannot start extension handler: " << path_ << " ("
                << e.what() << ")";
-    return;
   }
 }
 
-ExtensionManagerRunner::~ExtensionManagerRunner() {
-  // Remove the socket path.
-  remove(path_);
-}
-
-void ExtensionManagerRunner::enter() {
-  // Set the socket information for the extension manager.
-  auto socket_path = path_;
-
+void ExtensionManagerRunner::start() {
   // Create the thrift instances.
-  OSQUERY_THRIFT_POINTER::shared_ptr<ExtensionManagerHandler> handler(
-      new ExtensionManagerHandler());
-  OSQUERY_THRIFT_POINTER::shared_ptr<TProcessor> processor(
-      new ExtensionManagerProcessor(handler));
-  OSQUERY_THRIFT_POINTER::shared_ptr<TServerTransport> serverTransport(
-      new TServerSocket(socket_path));
-  OSQUERY_THRIFT_POINTER::shared_ptr<TTransportFactory> transportFactory(
-      new TBufferedTransportFactory());
-  OSQUERY_THRIFT_POINTER::shared_ptr<TProtocolFactory> protocolFactory(
-      new TBinaryProtocolFactory());
-
-  OSQUERY_THRIFT_POINTER::shared_ptr<ThreadManager> threadManager =
-      ThreadManager::newSimpleThreadManager(FLAGS_worker_threads);
-  OSQUERY_THRIFT_POINTER::shared_ptr<PosixThreadFactory> threadFactory =
-      OSQUERY_THRIFT_POINTER::shared_ptr<PosixThreadFactory>(
-          new PosixThreadFactory());
-  threadManager->threadFactory(threadFactory);
-  threadManager->start();
+  auto handler = ExtensionManagerHandlerRef(new ExtensionManagerHandler());
+  auto processor = TProcessorRef(new ExtensionManagerProcessor(handler));
 
-  // Start the Thrift server's run loop.
+  VLOG(1) << "Extension manager service starting: " << path_;
   try {
-    VLOG(1) << "Extension manager service starting: " << socket_path;
-    TThreadPoolServer server(processor,
-                             serverTransport,
-                             transportFactory,
-                             protocolFactory,
-                             threadManager);
-    server.serve();
+    startServer(processor);
   } catch (const std::exception& e) {
     LOG(WARNING) << "Extensions disabled: cannot start extension manager ("
-                 << socket_path << ") (" << e.what() << ")";
+                 << path_ << ") (" << e.what() << ")";
   }
 }
 }
