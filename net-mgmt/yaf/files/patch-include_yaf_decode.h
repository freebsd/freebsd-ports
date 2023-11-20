--- include/yaf/decode.h.orig	2023-02-08 18:37:15 UTC
+++ include/yaf/decode.h
@@ -218,6 +218,8 @@ typedef struct yfDecodeCtx_st yfDecodeCtx_t;
 #define YF_PROTO_TCP        6
 /** IPv4 Protocol Identifier and IPv6 Next Header for UDP */
 #define YF_PROTO_UDP        17
+/** IPv4 Protocol Identifier for tunneled IPv6 */
+#define YF_PROTO_TUNNEL_IP6 41
 /** IPv6 Next Header for Routing Options */
 #define YF_PROTO_IP6_ROUTE  43
 /** IPv6 Next Header for Fragment Options */
