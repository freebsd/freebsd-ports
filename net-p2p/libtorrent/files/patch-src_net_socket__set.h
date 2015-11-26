--- src/net/socket_set.h.orig	2012-01-19 10:19:26 UTC
+++ src/net/socket_set.h
@@ -53,12 +53,12 @@
 
 // Propably should rename to EventSet...
 
-class SocketSet : private std::vector<Event*, rak::cacheline_allocator<> > {
+class SocketSet : private std::vector<Event*, rak::cacheline_allocator<Event *> > {
 public:
   typedef uint32_t    size_type;
 
-  typedef std::vector<Event*, rak::cacheline_allocator<> > base_type;
-  typedef std::vector<size_type, rak::cacheline_allocator<> > Table;
+  typedef std::vector<Event*, rak::cacheline_allocator<Event *> > base_type;
+  typedef std::vector<size_type, rak::cacheline_allocator<size_type> > Table;
 
   static const size_type npos = static_cast<size_type>(-1);
 
