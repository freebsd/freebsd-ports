--- src/cpp-ethereum/libethash/endian.h.orig	2018-07-06 00:22:11.000000000 +0200
+++ src/cpp-ethereum/libethash/endian.h	2019-02-07 09:09:17.097747000 +0100
@@ -55,20 +55,20 @@
 
 #define fix_endian32(dst_, src_) dst_ = ethash_swap_u32(src_)
 #define fix_endian32_same(val_) val_ = ethash_swap_u32(val_)
-#define fix_endian64(dst_, src_) dst_ = ethash_swap_u64(src_
+#define fix_endian64(dst_, src_) dst_ = ethash_swap_u64(src_)
 #define fix_endian64_same(val_) val_ = ethash_swap_u64(val_)
-#define fix_endian_arr32(arr_, size_)			\
-	do {										\
-	for (unsigned i_ = 0; i_ < (size_), ++i_) { \
-		arr_[i_] = ethash_swap_u32(arr_[i_]);	\
-	}											\
-	while (0)
-#define fix_endian_arr64(arr_, size_)			\
-	do {										\
-	for (unsigned i_ = 0; i_ < (size_), ++i_) { \
-		arr_[i_] = ethash_swap_u64(arr_[i_]);	\
-	}											\
-	while (0)									\
+#define fix_endian_arr32(arr_, size_)					\
+	do {								\
+		for (unsigned i_ = 0; i_ < (size_); ++i_) {		\
+			(arr_)[i_] = ethash_swap_u32((arr_)[i_]);	\
+		}							\
+	} while (0)
+#define fix_endian_arr64(arr_, size_)					\
+	do {								\
+		for (unsigned i_ = 0; i_ < (size_); ++i_) {		\
+			(arr_)[i_] = ethash_swap_u64((arr_)[i_]);	\
+		}							\
+	} while (0)
 
 #else
 # error "endian not supported"
