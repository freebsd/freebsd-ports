--- include/reflex/matcher.h.orig	2020-07-09 08:31:49 UTC
+++ include/reflex/matcher.h
@@ -139,19 +139,19 @@ class Matcher : public PatternMatcher<reflex::Pattern>
   {
     if (n == 0)
       return std::pair<const char*,size_t>(txt_, len_);
-    return std::pair<const char*,size_t>(reinterpret_cast<const char*>(NULL), 0);
+    return std::pair<const char*,size_t>(nullptr, 0);
   }
   /// Returns the group capture identifier containing the group capture index >0 and name (or NULL) of a named group capture, or (1,NULL) by default
   virtual std::pair<size_t,const char*> group_id()
     /// @returns a pair of size_t and string
   {
-    return std::pair<size_t,const char*>(accept(), reinterpret_cast<const char*>(NULL));
+    return std::pair<size_t,const char*>(accept(), nullptr);
   }
   /// Returns the next group capture identifier containing the group capture index >0 and name (or NULL) of a named group capture, or (0,NULL) when no more groups matched
   virtual std::pair<size_t,const char*> group_next_id()
     /// @returns (0,NULL)
   {
-    return std::pair<size_t,const char*>(0, reinterpret_cast<const char*>(NULL));
+    return std::pair<size_t,const char*>(0, nullptr);
   }
   /// Returns the position of the last indent stop.
   size_t last_stop()
