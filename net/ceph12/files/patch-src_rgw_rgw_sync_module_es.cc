diff --git a/src/rgw/rgw_sync_module_es.cc b/src/rgw/rgw_sync_module_es.cc
index b5be52413b..7275823314 100644
--- src/rgw/rgw_sync_module_es.cc
+++ src/rgw/rgw_sync_module_es.cc
@@ -108,7 +108,7 @@ public:
 #define ES_NUM_REPLICAS_DEFAULT 1
 
 using ESVersion = std::pair<int,int>;
-static constexpr ESVersion ES_V5{5,0};
+static const ESVersion ES_V5{5,0};
 
 struct ESInfo {
   std::string name;
@@ -402,7 +402,7 @@ struct es_index_config : public es_index_config_base {
 };
 
 static bool is_sys_attr(const std::string& attr_name){
-  static constexpr std::initializer_list<const char*> rgw_sys_attrs = {RGW_ATTR_PG_VER,
+  static const std::initializer_list<const char*> rgw_sys_attrs = {RGW_ATTR_PG_VER,
                                                                        RGW_ATTR_SOURCE_ZONE,
                                                                        RGW_ATTR_ID_TAG,
                                                                        RGW_ATTR_TEMPURL_KEY1,
