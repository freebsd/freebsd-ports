--- url/url_canon_icu.cc.orig	2017-10-07 18:17:57 UTC
+++ url/url_canon_icu.cc
@@ -130,7 +130,7 @@ void ICUCharsetConverter::ConvertFromUTF
     UErrorCode err = U_ZERO_ERROR;
     char* dest = &output->data()[begin_offset];
     int required_capacity = ucnv_fromUChars(converter_, dest, dest_capacity,
-                                            input, input_len, &err);
+                                            reinterpret_cast<const UChar*>(input), input_len, &err);
     if (err != U_BUFFER_OVERFLOW_ERROR) {
       output->set_length(begin_offset + required_capacity);
       return;
@@ -169,7 +169,7 @@ bool IDNToASCII(const base::char16* src,
   while (true) {
     UErrorCode err = U_ZERO_ERROR;
     UIDNAInfo info = UIDNA_INFO_INITIALIZER;
-    int output_length = uidna_nameToASCII(uidna, src, src_len, output->data(),
+    int output_length = uidna_nameToASCII(uidna, reinterpret_cast<const UChar*>(src), src_len, reinterpret_cast<UChar*>(output->data()),
                                           output->capacity(), &info, &err);
     if (U_SUCCESS(err) && info.errors == 0) {
       output->set_length(output_length);
