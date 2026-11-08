-- allow to override the basis directory with an environment variable

--- src/util/input/input.cc.orig	2022-06-03 20:23:32 UTC
+++ src/util/input/input.cc
@@ -119,7 +119,12 @@ shared_ptr<const PTree> PTree::read_basis(string name)
   } catch (...) {
     // next, the standard install location
     try {
-      const string prefix(BASIS_DIR);
+      string prefix(BASIS_DIR);
+      
+      // override with the environment variable if it is set
+      if (auto env_basis_dir = std::getenv("BAGEL_BASIS_DIR"))
+          prefix = env_basis_dir;
+
       const string filename = prefix + "/" + name + ".json";
       out = make_shared<const PTree>(filename);
     } catch (...) {
