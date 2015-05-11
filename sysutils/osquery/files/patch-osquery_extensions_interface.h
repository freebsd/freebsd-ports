--- osquery/extensions/interface.h.orig	2015-05-05 00:16:41 UTC
+++ osquery/extensions/interface.h
@@ -30,7 +30,6 @@
 // clang-format on
 
 namespace osquery {
-namespace extensions {
 
 using namespace apache::thrift;
 using namespace apache::thrift::protocol;
@@ -38,6 +37,21 @@ using namespace apache::thrift::transpor
 using namespace apache::thrift::server;
 using namespace apache::thrift::concurrency;
 
+/// Create easier to reference typedefs for Thrift layer implementations.
+#define SHARED_PTR_IMPL OSQUERY_THRIFT_POINTER::shared_ptr
+typedef SHARED_PTR_IMPL<TSocket> TSocketRef;
+typedef SHARED_PTR_IMPL<TTransport> TTransportRef;
+typedef SHARED_PTR_IMPL<TProtocol> TProtocolRef;
+
+typedef SHARED_PTR_IMPL<TProcessor> TProcessorRef;
+typedef SHARED_PTR_IMPL<TServerTransport> TServerTransportRef;
+typedef SHARED_PTR_IMPL<TTransportFactory> TTransportFactoryRef;
+typedef SHARED_PTR_IMPL<TProtocolFactory> TProtocolFactoryRef;
+typedef SHARED_PTR_IMPL<PosixThreadFactory> PosixThreadFactoryRef;
+typedef std::shared_ptr<TThreadPoolServer> TThreadPoolServerRef;
+
+namespace extensions {
+
 /**
  * @brief The Thrift API server used by an osquery Extension process.
  *
@@ -68,6 +82,7 @@ class ExtensionHandler : virtual public 
             const ExtensionPluginRequest& request);
 
  protected:
+  /// Transient UUID assigned to the extension after registering.
   RouteUUID uuid_;
 };
 
@@ -163,6 +178,7 @@ class ExtensionManagerHandler : virtual 
  private:
   /// Check if an extension exists by the name it registered.
   bool exists(const std::string& name);
+
   /// Introspect into the registry, checking if any extension routes have been
   /// removed.
   void refresh();
@@ -170,6 +186,9 @@ class ExtensionManagerHandler : virtual 
   /// Maintain a map of extension UUID to metadata for tracking deregistration.
   InternalExtensionList extensions_;
 };
+
+typedef SHARED_PTR_IMPL<ExtensionHandler> ExtensionHandlerRef;
+typedef SHARED_PTR_IMPL<ExtensionManagerHandler> ExtensionManagerHandlerRef;
 }
 
 /// A Dispatcher service thread that watches an ExtensionManagerHandler.
@@ -183,7 +202,8 @@ class ExtensionWatcher : public Internal
 
  public:
   /// The Dispatcher thread entry point.
-  void enter();
+  void start();
+
   /// Perform health checks.
   virtual void watch();
 
@@ -194,8 +214,10 @@ class ExtensionWatcher : public Internal
  protected:
   /// The UNIX domain socket path for the ExtensionManager.
   std::string path_;
+
   /// The internal in milliseconds to ping the ExtensionManager.
   size_t interval_;
+
   /// If the ExtensionManager socket is closed, should the extension exit.
   bool fatal_;
 };
@@ -205,60 +227,87 @@ class ExtensionManagerWatcher : public E
   ExtensionManagerWatcher(const std::string& path, size_t interval)
       : ExtensionWatcher(path, interval, false) {}
 
+  /// Start a specialized health check for an ExtensionManager.
   void watch();
 };
 
-/// A Dispatcher service thread that starts ExtensionHandler.
-class ExtensionRunner : public InternalRunnable {
+class ExtensionRunnerCore : public InternalRunnable {
+ public:
+  virtual ~ExtensionRunnerCore();
+  ExtensionRunnerCore(const std::string& path)
+      : path_(path), server_(nullptr) {}
+
+ public:
+  /// Given a handler transport and protocol start a thrift threaded server.
+  void startServer(TProcessorRef processor);
+
+  // The Dispatcher thread service stop point.
+  void stop();
+
+ protected:
+  /// The UNIX domain socket used for requests from the ExtensionManager.
+  std::string path_;
+
+  /// Server instance, will be stopped if thread service is removed.
+  TThreadPoolServerRef server_;
+};
+
+/**
+ * @brief A Dispatcher service thread that starts ExtensionHandler.
+ *
+ * This runner will start a Thrift Extension server, call serve, and wait
+ * until the extension exists or the ExtensionManager (core) terminates or
+ * deregisters the extension.
+ *
+ */
+class ExtensionRunner : public ExtensionRunnerCore {
  public:
-  virtual ~ExtensionRunner();
   ExtensionRunner(const std::string& manager_path, RouteUUID uuid)
-      : uuid_(uuid) {
+      : ExtensionRunnerCore(""), uuid_(uuid) {
     path_ = getExtensionSocket(uuid, manager_path);
   }
 
  public:
-  /// The Dispatcher thread entry point.
-  void enter();
+  void start();
 
   /// Access the UUID provided by the ExtensionManager.
   RouteUUID getUUID() { return uuid_; }
 
  private:
-  /// The UNIX domain socket used for requests from the ExtensionManager.
-  std::string path_;
   /// The unique and transient Extension UUID assigned by the ExtensionManager.
   RouteUUID uuid_;
 };
 
-/// A Dispatcher service thread that starts ExtensionManagerHandler.
-class ExtensionManagerRunner : public InternalRunnable {
+/**
+ * @brief A Dispatcher service thread that starts ExtensionManagerHandler.
+ *
+ * This runner will start a Thrift ExtensionManager server, call serve, and wait
+ * until for extensions to register, or thrift API calls.
+ *
+ */
+class ExtensionManagerRunner : public ExtensionRunnerCore {
  public:
-  virtual ~ExtensionManagerRunner();
   explicit ExtensionManagerRunner(const std::string& manager_path)
-      : path_(manager_path) {}
+      : ExtensionRunnerCore(manager_path) {}
 
  public:
-  void enter();
-
- private:
-  std::string path_;
+  void start();
 };
 
 /// Internal accessor for extension clients.
 class EXInternal {
  public:
   explicit EXInternal(const std::string& path)
-      : socket_(new extensions::TSocket(path)),
-        transport_(new extensions::TBufferedTransport(socket_)),
-        protocol_(new extensions::TBinaryProtocol(transport_)) {}
+      : socket_(new TSocket(path)),
+        transport_(new TBufferedTransport(socket_)),
+        protocol_(new TBinaryProtocol(transport_)) {}
 
   virtual ~EXInternal() { transport_->close(); }
 
  protected:
-  OSQUERY_THRIFT_POINTER::shared_ptr<extensions::TSocket> socket_;
-  OSQUERY_THRIFT_POINTER::shared_ptr<extensions::TTransport> transport_;
-  OSQUERY_THRIFT_POINTER::shared_ptr<extensions::TProtocol> protocol_;
+  TSocketRef socket_;
+  TTransportRef transport_;
+  TProtocolRef protocol_;
 };
 
 /// Internal accessor for a client to an extension (from an extension manager).
