--- components/miracle_parameter/common/public/miracle_parameter.h.orig	2023-11-04 07:08:51 UTC
+++ components/miracle_parameter/common/public/miracle_parameter.h
@@ -93,7 +93,8 @@ class MiracleParameter {
 template <>
 class MiracleParameter<std::string> : public MiracleParameterBase<std::string> {
  public:
-  constexpr MiracleParameter(const base::Feature* feature,
+	 // XXXROBERT
+  MiracleParameter(const base::Feature* feature,
                              const char* param_name,
                              std::string default_value)
       : MiracleParameterBase(feature, param_name, std::move(default_value)) {}
