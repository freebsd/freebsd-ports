diff --git a/src/test/objectstore/store_test.cc b/src/test/objectstore/store_test.cc
old mode 100644
new mode 100755
index 326c9785d0..8d39249360
--- src/test/objectstore/store_test.cc
+++ src/test/objectstore/store_test.cc
@@ -4313,7 +4313,7 @@ TEST_P(StoreTest, Synthetic) {
   doSyntheticTest(store, 10000, 400*1024, 40*1024, 0);
 }
 
-
+#if defined(WITH_BLUESTORE)
 TEST_P(StoreTestSpecificAUSize, SyntheticMatrixSharding) {
   if (string(GetParam()) != "bluestore")
     return;
@@ -4485,6 +4485,7 @@ TEST_P(StoreTestSpecificAUSize, SyntheticMatrixPreferDeferred) {
   };
   do_matrix(m, store, doSyntheticTest);
 }
+#endif // #if defined(WITH_BLUESTORE)
 
 TEST_P(StoreTest, AttrSynthetic) {
   ObjectStore::Sequencer osr("test");
@@ -6855,6 +6856,7 @@ TEST_P(StoreTestSpecificAUSize, fsckOnUnalignedDevice2) {
   g_conf->apply_changes(NULL);
 }
 
+#if defined(WITH_BLUESTORE)
 TEST_P(StoreTest, SpuriousReadErrorTest) {
   if (string(GetParam()) != "bluestore")
     return;
@@ -6921,6 +6923,7 @@ TEST_P(StoreTest, SpuriousReadErrorTest) {
   g_conf->set_val("bluestore_debug_inject_csum_err_probability", "0");
   g_ceph_context->_conf->apply_changes(nullptr);
 }
+#endif // #if defined(WITH_BLUESTORE)
 
 int main(int argc, char **argv) {
   vector<const char*> args;
