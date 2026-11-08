--- test/gtest/uct/test_mm.cc.orig	2026-09-13 20:27:27 UTC
+++ test/gtest/uct/test_mm.cc
@@ -147,12 +147,12 @@ class test_uct_mm : public uct_test { (public)
         size_t iface_addr_len = uct_mm_md_mapper_call(md(m_e1), iface_addr_length);
         std::vector<uint8_t> iface_addr(iface_addr_len);
 
-        status = uct_mm_md_mapper_call(md(m_e1), iface_addr_pack, &iface_addr[0]);
+        status = uct_mm_md_mapper_call(md(m_e1), iface_addr_pack, iface_addr.data());
         ASSERT_UCS_OK(status);
 
         uct_mm_remote_seg_t rseg;
         status = uct_mm_md_mapper_call(md(m_e2), mem_attach, seg->seg_id, size,
-                                       &iface_addr[0], &rseg);
+                                       iface_addr.data(), &rseg);
         ASSERT_UCS_OK(status);
 
         test_attach_ptr(ptr, rseg.address, 0xdeadbeef11111);
