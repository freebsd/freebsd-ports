--- Common/DtaAnnotatedDump.h.orig	2017-05-17 20:10:01 UTC
+++ Common/DtaAnnotatedDump.h
@@ -17,7 +17,7 @@ EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 #pragma once 
 #pragma pack(push,1)
 
-typedef union
+typedef union TAG_CAtomHeader
 {
     // four bytes in big endian (network) byte order
     uint8_t     all[4];
