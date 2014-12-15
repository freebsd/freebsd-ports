--- channels/sip/include/route.h.orig	2014-02-10 18:28:35 UTC
+++ channels/sip/include/route.h
@@ -98,7 +98,7 @@ void sip_route_dump(const struct sip_rou
  * \retval NULL on failure
  */
 struct ast_str *sip_route_list(const struct sip_route *route, int formatcli, int skip)
-		__attribute_malloc__ __attribute_warn_unused_result__;
+		__attribute__((__malloc__)) __attribute__((__warn_unused_result__));
 
 /*!
  * \brief Check if the route is strict
