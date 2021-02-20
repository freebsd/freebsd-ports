- patch provided by the upstream

--- packages/external/acro/packages/colin/src/colin/AppResponse.h.orig	2021-02-17 01:12:03 UTC
+++ packages/external/acro/packages/colin/src/colin/AppResponse.h
@@ -54,10 +54,10 @@ class AppResponse
 public: // typedefs
 
    ///
-   typedef std::pair<response_info_t, const utilib::Any >  response_pair_t;
+   typedef std::pair<response_info_t, utilib::Any >  response_pair_t;
 
    ///
-   typedef std::map<response_info_t, const utilib::Any >  response_map_t;
+   typedef std::map<response_info_t, utilib::Any >  response_map_t;
 
 public: // construct / destruct / copy / compare methods
 
