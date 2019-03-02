--- values.h.orig	2019-03-02 01:45:31 UTC
+++ values.h
@@ -37,18 +37,6 @@ enum value_slot {
     VALUE_CTIME = 3	// Like VALUE_LASTMOD, but for last metadata change.
 };
 
-#ifndef WORDS_BIGENDIAN
-inline std::uint32_t bswap32(std::uint32_t v) {
-# if HAVE_DECL___BUILTIN_BSWAP32
-    return __builtin_bswap32(v);
-# elif HAVE_DECL__BYTESWAP_ULONG
-    return _byteswap_ulong(v);
-# else
-    return (v << 24) | ((v & 0xff00) << 8) | ((v >> 8) & 0xff00) | (v >> 24);
-# endif
-}
-#endif
-
 inline std::uint32_t binary_string_to_int(const std::string &s)
 {
     if (s.size() != 4) return static_cast<std::uint32_t>(-1);
