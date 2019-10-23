diff --git a/src/auth/KeyRing.cc b/src/auth/KeyRing.cc
index a2833183633a..c4fc15a2380b 100644
--- src/auth/KeyRing.cc
+++ src/auth/KeyRing.cc
@@ -203,6 +203,12 @@ void KeyRing::decode(bufferlist::const_iterator& bl) {
   } catch (buffer::error& err) {
     keys.clear();
     decode_plaintext(start_pos);
+  }catch (buffer::end_of_buffer& err) {
+    keys.clear();
+    decode_plaintext(start_pos);
+  } catch (exception& e){
+    keys.clear();
+    decode_plaintext(start_pos);
   }
 }
 
