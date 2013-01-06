--- ./traceroute.cc.orig	2013-01-06 16:38:44.000000000 +0100
+++ ./traceroute.cc	2013-01-06 16:38:44.000000000 +0100
@@ -190,8 +190,6 @@
 /* A global random token used to distinguish this traceroute's probes from
    those of other traceroutes possibly running on the same machine. */
 static u16 global_id;
-/* A global cache of known hops, indexed by TTL and address. */
-static std::map<struct HopIdent, Hop *> hop_cache;
 /* A list of timedout hops, which are not kept in hop_cache, so we can delete
    all hops on occasion. */
 static std::list<Hop *> timedout_hops;
@@ -204,6 +202,9 @@
 static struct timeval get_now(struct timeval *now = NULL);
 static const char *ss_to_string(const struct sockaddr_storage *ss);
 
+/* A global cache of known hops, indexed by TTL and address. */
+static std::map<struct HopIdent, Hop *> hop_cache;
+
 struct Hop {
   Hop *parent;
   struct sockaddr_storage tag;
