diff --git a/src/rgw/rgw_sync_module_es.cc b/src/rgw/rgw_sync_module_es.cc
index aa58219b5a..de4200d75e 100644
--- src/rgw/rgw_sync_module_es.cc
+++ src/rgw/rgw_sync_module_es.cc
@@ -244,7 +244,7 @@ struct es_index_config {
 };
 
 static bool is_sys_attr(const std::string& attr_name){
-  static constexpr std::initializer_list<const char*> rgw_sys_attrs = {RGW_ATTR_PG_VER,
+  static const std::initializer_list<const char*> rgw_sys_attrs = {RGW_ATTR_PG_VER,
                                                                        RGW_ATTR_SOURCE_ZONE,
                                                                        RGW_ATTR_ID_TAG,
                                                                        RGW_ATTR_TEMPURL_KEY1,
