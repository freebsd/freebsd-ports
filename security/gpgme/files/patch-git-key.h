The operator< should be const, so it can be applied to const Signatures.
This fixes a build failure in security/libkleo.

diff --git lang/cpp/src/key.cpp lang/cpp/src/key.cpp
index e536d080..7411e9e4 100644
--- lang/cpp/src/key.cpp
+++ lang/cpp/src/key.cpp
@@ -865,7 +865,7 @@ UserID::Signature::Signature(const shared_gpgme_key_t &k, gpgme_user_id_t u, gpg
 {
 }
 
-bool UserID::Signature::operator<(const Signature &other)
+bool UserID::Signature::operator<(const Signature &other) const
 {
     // based on cmp_signodes() in g10/keylist.c
 
diff --git lang/cpp/src/key.h lang/cpp/src/key.h
index a7931672..57001a03 100644
--- lang/cpp/src/key.h
+++ lang/cpp/src/key.h
@@ -468,7 +468,7 @@ public:
     }
 
     /*! Defines a canonical sort order for signatures of the same user ID. */
-    bool operator<(const Signature &other);
+    bool operator<(const Signature &other) const;
 
     bool isNull() const
     {
