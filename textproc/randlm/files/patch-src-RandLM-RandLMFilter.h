--- src/RandLM/RandLMFilter.h.orig	2014-09-01 18:07:56.000000000 +0400
+++ src/RandLM/RandLMFilter.h	2014-09-01 18:08:39.000000000 +0400
@@ -289,7 +289,7 @@ namespace randlm {
       std::cerr << "Saved ResizedBitFilter. Rho = " << rho() << "." << std::endl;
       assert(fout->write((char*)&old_addresses_, sizeof(old_addresses_)));
       assert(fout->write((char*)&a_, sizeof(a_)));
-      return fout->write((char*)&b_, sizeof(b_));
+      return fout->write((char*)&b_, sizeof(b_)).good();
     }
   protected:
     bool load(RandLMFile* fin) {
@@ -297,7 +297,7 @@ namespace randlm {
       std::cerr << "Loaded ResizedBitFilter. Rho = " << rho() << "." << std::endl;
       assert(fin->read((char*)&old_addresses_, sizeof(old_addresses_)));
       assert(fin->read((char*)&a_, sizeof(a_)));
-      return fin->read((char*)&b_, sizeof(b_));
+      return fin->read((char*)&b_, sizeof(b_)).good();
     }
     // member data
     uint64_t old_addresses_;  // size of pre-resized filter
@@ -342,11 +342,11 @@ namespace randlm {
     }
     bool save(RandLMFile* fout) {
       assert(Filter<T>::save(fout));
-      return fout->write((char*)&wrap_around_, sizeof(wrap_around_));
+      return fout->write((char*)&wrap_around_, sizeof(wrap_around_)).good();
     }
     private:
     bool load(RandLMFile* fin) {
-      return fin->read((char*)&wrap_around_, sizeof(wrap_around_));
+      return fin->read((char*)&wrap_around_, sizeof(wrap_around_)).good();
     }
     inline bool incrementSubCell(int bit, int len, T* cell) {
       // increment counter consisting of bits [startbit, startbit + len - 1] rest stays unchanged
