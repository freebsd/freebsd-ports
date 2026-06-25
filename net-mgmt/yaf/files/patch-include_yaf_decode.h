--- include/yaf/decode.h.orig	2026-03-19 20:13:51 UTC
+++ include/yaf/decode.h
@@ -203,6 +203,8 @@ typedef struct yfDecodeCtx_st yfDecodeCtx_t;
 #define YF_PROTO_TCP        6
 /** IPv4 Protocol Identifier and IPv6 Next Header for UDP */
 #define YF_PROTO_UDP        17
+/** IPv4 Protocol Identifier for tunneled IPv6 */
+#define YF_PROTO_TUNNEL_IP6 41
 /** IPv6 Next Header for Routing Options */
 #define YF_PROTO_IP6_ROUTE  43
 /** IPv6 Next Header for Fragment Options */
