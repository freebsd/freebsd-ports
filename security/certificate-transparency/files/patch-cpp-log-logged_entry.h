Obtained from:	https://github.com/google/certificate-transparency/commit/6776cc2c4cca665c088019d40f9587189a5d687d

--- cpp/log/logged_entry.h.orig
+++ cpp/log/logged_entry.h
@@ -25,9 +25,7 @@ class LoggedEntry : private ct::LoggedEntryPB {
   using LoggedEntryPB::merkle_leaf_hash;
   using LoggedEntryPB::set_merkle_leaf_hash;
   using LoggedEntryPB::set_sequence_number;
-  void CopyFrom(const ::google::protobuf::Message& from) {
-    LoggedEntryPB::CopyFrom(from);
-  }
+  using LoggedEntryPB::CopyFrom;
   void CopyFrom(const LoggedEntry& from) {
     LoggedEntryPB::CopyFrom(from);
   }
