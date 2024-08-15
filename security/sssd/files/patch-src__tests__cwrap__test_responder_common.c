--- src/tests/cwrap/test_responder_common.c.orig	2020-03-17 13:31:28 UTC
+++ src/tests/cwrap/test_responder_common.c
@@ -136,11 +136,13 @@ void check_sock_properties(struct create_pipe_ctx *ctx
     assert_true(S_ISSOCK(sbuf.st_mode));
     assert_true((sbuf.st_mode & ~S_IFMT) == mode);
 
+#ifdef SO_DOMAIN
     /* Check it's a UNIX socket */
     optlen = sizeof(optval);
     ret = getsockopt(ctx->fd, SOL_SOCKET, SO_DOMAIN, &optval, &optlen);
     assert_int_equal(ret, 0);
     assert_int_equal(optval, AF_UNIX);
+#endif
 
     optlen = sizeof(optval);
     ret = getsockopt(ctx->fd, SOL_SOCKET, SO_TYPE, &optval, &optlen);
