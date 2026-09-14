--- test/gtest/ucp/test_ucp_proto_mock.cc.orig	2026-09-14 16:35:57 UTC
+++ test/gtest/ucp/test_ucp_proto_mock.cc
@@ -1186,6 +1186,7 @@ UCP_INSTANTIATE_TEST_CASE_TLS(test_ucp_proto_mock_rcx_
 
 UCP_INSTANTIATE_TEST_CASE_TLS(test_ucp_proto_mock_rcx_numa, rcx, "rc_x")
 
+#if HAVE_CMA
 class test_ucp_proto_mock_cma : public test_ucp_proto_mock {
 public:
     test_ucp_proto_mock_cma()
@@ -1214,6 +1215,7 @@ UCP_INSTANTIATE_TEST_CASE_TLS(test_ucp_proto_mock_cma,
 }
 
 UCP_INSTANTIATE_TEST_CASE_TLS(test_ucp_proto_mock_cma, mm_cma, "posix,cma")
+#endif
 
 class test_ucp_proto_mock_tcp : public test_ucp_proto_mock {
 public:
