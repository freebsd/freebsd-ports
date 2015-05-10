--- osquery/remote/requests.h.orig	2015-05-05 00:16:41 UTC
+++ osquery/remote/requests.h
@@ -152,7 +152,7 @@ class Serializer {
                            std::string& serialized) = 0;
 
   /**
-   * @brief Deerialize a property tree into a property tree
+   * @brief Deserialize a property tree into a property tree
    *
    * @param params A string of serialized parameters
    *
