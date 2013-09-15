--- ./src/tcpdemux.h.orig	2013-05-27 22:28:50.000000000 +0000
+++ ./src/tcpdemux.h	2013-09-07 22:32:29.000000000 +0000
@@ -20,8 +20,18 @@
 #include "pcap_writer.h"
 #include "dfxml/src/dfxml_writer.h"
 #include "dfxml/src/hash_t.h"
+#ifdef __clang__
+#if __has_include(<unordered_set>)
+#define HAVE_CXX11_UNORDERED_SET 1
+#endif
+#endif
+#ifdef HAVE_CXX11_UNORDERED_SET
+#include <unordered_map>
+#include <unordered_set>
+#else
 #include <tr1/unordered_map>
 #include <tr1/unordered_set>
+#endif
 #include <queue>
 
 
@@ -53,10 +63,17 @@
         bool operator() (const flow_addr &x, const flow_addr &y) const { return x==y;}
     } flow_addr_key_eq;
 
+#ifdef HAVE_CXX11_UNORDERED_SET
+    typedef std::unordered_set<class tcpip *> tcpset;
+    typedef std::vector<class saved_flow *> saved_flows_t; // needs to be ordered
+    typedef std::unordered_map<flow_addr,tcpip *,flow_addr_hash,flow_addr_key_eq> flow_map_t; // active flows
+    typedef std::unordered_map<flow_addr,saved_flow *,flow_addr_hash,flow_addr_key_eq> saved_flow_map_t; // flows that have been saved
+#else
     typedef std::tr1::unordered_set<class tcpip *> tcpset;
     typedef std::vector<class saved_flow *> saved_flows_t; // needs to be ordered
     typedef std::tr1::unordered_map<flow_addr,tcpip *,flow_addr_hash,flow_addr_key_eq> flow_map_t; // active flows
     typedef std::tr1::unordered_map<flow_addr,saved_flow *,flow_addr_hash,flow_addr_key_eq> saved_flow_map_t; // flows that have been saved
+#endif
     tcpdemux();
 public:
     static uint32_t tcp_timeout;
