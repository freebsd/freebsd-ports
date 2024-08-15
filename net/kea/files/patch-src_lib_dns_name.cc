--- src/lib/dns/name.cc.orig	2024-07-25 08:50:58 UTC
+++ src/lib/dns/name.cc
@@ -303,7 +303,7 @@ Name::Name(const std::string &namestring, bool downcas
     // And get the output
     labelcount_ = offsets.size();
     isc_throw_assert(labelcount_ > 0 && labelcount_ <= Name::MAX_LABELS);
-    ndata_.assign(ndata.data(), ndata.size());
+    ndata_.assign(ndata.data(), ndata.data() + ndata.size());
     length_ = ndata_.size();
     offsets_.assign(offsets.begin(), offsets.end());
 }
@@ -336,7 +336,7 @@ Name::Name(const char* namedata, size_t data_len, cons
     // Get the output
     labelcount_ = offsets.size();
     isc_throw_assert(labelcount_ > 0 && labelcount_ <= Name::MAX_LABELS);
-    ndata_.assign(ndata.data(), ndata.size());
+    ndata_.assign(ndata.data(), ndata.data() + ndata.size());
     length_ = ndata_.size();
     offsets_.assign(offsets.begin(), offsets.end());
 
@@ -347,7 +347,7 @@ Name::Name(const char* namedata, size_t data_len, cons
         // Drop the last character of the data (the \0) and append a copy of
         // the origin's data
         ndata_.erase(ndata_.end() - 1);
-        ndata_.append(origin->ndata_);
+        ndata_.insert(ndata.end(), origin->ndata_.begin(), origin->ndata_.end());
 
         // Do a similar thing with offsets. However, we need to move them
         // so they point after the prefix we parsed before.
@@ -582,7 +582,7 @@ Name::concatenate(const Name& suffix) const {
 
     Name retname;
     retname.ndata_.reserve(length);
-    retname.ndata_.assign(ndata_, 0, length_ - 1);
+    retname.ndata_.assign(ndata_.data(), ndata_.data() + length_ - 1);
     retname.ndata_.insert(retname.ndata_.end(),
                           suffix.ndata_.begin(), suffix.ndata_.end());
     isc_throw_assert(retname.ndata_.size() == length);
@@ -622,7 +622,7 @@ Name::reverse() const {
     NameString::const_iterator n0 = ndata_.begin();
     retname.offsets_.push_back(0);
     while (rit1 != offsets_.rend()) {
-        retname.ndata_.append(n0 + *rit1, n0 + *rit0);
+        retname.ndata_.insert(retname.ndata_.end(), n0 + *rit1, n0 + *rit0);
         retname.offsets_.push_back(retname.ndata_.size());
         ++rit0;
         ++rit1;
@@ -662,7 +662,7 @@ Name::split(const unsigned int first, const unsigned i
     // original name, and append the trailing dot explicitly.
     //
     retname.ndata_.reserve(retname.offsets_.back() + 1);
-    retname.ndata_.assign(ndata_, offsets_[first], retname.offsets_.back());
+    retname.ndata_.assign(ndata_.data() + offsets_[first], ndata_.data() + retname.offsets_.back());
     retname.ndata_.push_back(0);
 
     retname.length_ = retname.ndata_.size();
