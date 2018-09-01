--- feature_index.cpp.orig	2018-09-01 10:26:57 UTC
+++ feature_index.cpp
@@ -34,8 +34,7 @@ int EncoderFeatureIndex::getID(const char *key) {
   std::map <std::string, std::pair<int, unsigned int> >::iterator
       it = dic_.find(key);
   if (it == dic_.end()) {
-    dic_.insert(std::make_pair<std::string, std::pair<int, unsigned int> >
-                (key, std::make_pair<int, unsigned int>(maxid_, 1)));
+    dic_.insert(std::make_pair(key, std::make_pair(maxid_, 1)));
     int n = maxid_;
     maxid_ += (key[0] == 'U' ? y_.size() : y_.size() * y_.size());
     return n;
@@ -171,7 +170,7 @@ void EncoderFeatureIndex::shrink(size_t freq) {
     const std::string &key = it->first;
 
     if (it->second.second >= freq) {
-      old2new.insert(std::make_pair<int, int>(it->second.first, new_maxid));
+      old2new.insert(std::make_pair(it->second.first, new_maxid));
       it->second.first = new_maxid;
       new_maxid += (key[0] == 'U' ? y_.size() : y_.size() * y_.size());
       ++it;
