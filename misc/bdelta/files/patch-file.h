--- file.h.orig	2013-01-30 20:16:01 UTC
+++ file.h
@@ -3,6 +3,7 @@
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 #include <stdio.h>
+#include <cstdlib>
 
 #define MAX_IO_BLOCK_SIZE (1024 * 1024)
 
@@ -58,6 +59,44 @@ unsigned read_dword(FILE *f) {
 	return (read_word(f) << 16) + low;
 }
 
+static size_t scan_varint(const char* in,size_t len, unsigned long long* n) {
+  size_t i;
+  unsigned long long l;
+  if (len==0) return 0;
+  for (l=0, i=0; i<len; ++i) {
+    l+=(unsigned long long)(in[i]&0x7f) << (i*7);
+    if (!(in[i]&0x80)) {
+      *n=l;
+      return i+1;
+    }
+  }
+  return 0;
+}
+
+size_t scan_pb_type0_sint(const char* in,size_t len,signed long long* l) {
+  unsigned long long m;
+  size_t n=scan_varint(in,len,&m);
+  if (!n) return 0;
+  *l=(-(m&1)) ^ (m>>1);
+  return n;
+}
+
+long long read_varint(FILE* f) {
+  char buf[20];
+  size_t i;
+  long long l;
+  for (i=0; i<sizeof(buf); ++i) {
+    fread_fixed(f,buf+i,1);
+    if (!(buf[i]&0x80)) {
+      if (scan_pb_type0_sint(buf,i+1,&l)!=i+1) break;
+      return l;
+    }
+  }
+  static char read_error_message[128];
+  strcpy(read_error_message, "parse error: read_varint() failed");
+  throw read_error_message;
+}
+
 void write_word(FILE *f, unsigned number) {
 	unsigned char b = number & 255,
 	              b2 = number >> 8;
@@ -70,6 +109,31 @@ void write_dword(FILE *f, unsigned numbe
 	write_word(f, number >> 16);
 }
 
+
+/* write int in least amount of bytes, return number of bytes */
+/* as used in varints from Google protocol buffers */
+static size_t fmt_varint(char* dest,unsigned long long l) {
+  /* high bit says if more bytes are coming, lower 7 bits are payload; little endian */
+  size_t i;
+  for (i=0; l; ++i, l>>=7) {
+    if (dest) dest[i]=(l&0x7f) | ((!!(l&~0x7f))<<7);
+  }
+  if (!i) {	/* l was 0 */
+    if (dest) dest[0]=0;
+    ++i;
+  }
+  return i;
+}
+
+static size_t fmt_pb_type0_sint(char* dest,signed long long l) {
+  return fmt_varint(dest,(l << 1) ^ (l >> (sizeof(l)*8-1)));
+}
+
+void write_varint(FILE* f, long long number) {
+  char tmp[20];
+  fwrite_fixed(f,tmp,fmt_pb_type0_sint(tmp,number));
+}
+
 bool fileExists(char *fname) {
 	FILE *f = fopen(fname, "rb");
 	bool exists = (f != NULL);
