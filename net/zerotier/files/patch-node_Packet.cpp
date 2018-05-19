--- node/Packet.cpp.orig	2018-05-18 09:03:14 UTC
+++ node/Packet.cpp
@@ -332,7 +332,7 @@ static const int LZ4_minLength = (MFLIMIT+1);
 
 #define LZ4_STATIC_ASSERT(c)    { enum { LZ4_static_assert = 1/(int)(!!(c)) }; }   /* use only *after* variable declarations */
 
-static inline unsigned LZ4_NbCommonBytes (register reg_t val)
+static inline unsigned LZ4_NbCommonBytes (reg_t val)
 {
 	if (LZ4_isLittleEndian()) {
 	    if (sizeof(val)==8) {
