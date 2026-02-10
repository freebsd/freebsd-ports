--- src/3rdparty/chromium/net/cookies/cookie_monster.h.orig	2025-04-23 16:00:55 UTC
+++ src/3rdparty/chromium/net/cookies/cookie_monster.h
@@ -314,7 +314,7 @@ class NET_EXPORT CookieMonster : public CookieStore {
   // of scheme. This enum should not be used when cookies are *cleared*,
   // because its purpose is to understand if Chrome can deprecate the
   // ability of HTTP urls to set/overwrite Secure cookies.
-  enum CookieSource {
+  enum CookieSource : uint8_t {
     COOKIE_SOURCE_SECURE_COOKIE_CRYPTOGRAPHIC_SCHEME = 0,
     COOKIE_SOURCE_SECURE_COOKIE_NONCRYPTOGRAPHIC_SCHEME,
     COOKIE_SOURCE_NONSECURE_COOKIE_CRYPTOGRAPHIC_SCHEME,
