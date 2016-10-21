--- cpp/server/ct-dns-server.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/server/ct-dns-server.cc
@@ -17,7 +17,7 @@ using cert_trans::LogLookup;
 using cert_trans::LoggedEntry;
 using cert_trans::SQLiteDB;
 using ct::SignedTreeHead;
-using google::RegisterFlagValidator;
+using gflags::RegisterFlagValidator;
 using std::string;
 using std::stringstream;
 
