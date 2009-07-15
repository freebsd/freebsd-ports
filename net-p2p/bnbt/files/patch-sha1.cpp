--- sha1.cpp	2009-06-30 14:02:51.000000000 -0700
+++ sha1.cpp.new	2009-06-30 14:02:47.000000000 -0700
@@ -44,9 +44,9 @@
 	m_count[1] = 0;
 }
 
-void CSHA1::Transform(unsigned long state[5], const unsigned char buffer[64])
+void CSHA1::Transform(unsigned int state[5], const unsigned char buffer[64])
 {
-	unsigned long a = 0, b = 0, c = 0, d = 0, e = 0;
+	unsigned int a = 0, b = 0, c = 0, d = 0, e = 0;
 
 	SHA1_WORKSPACE_BLOCK* block;
 	static unsigned char workspace[64];
@@ -96,7 +96,7 @@
 // Use this function to hash in binary data and strings
 void CSHA1::Update(const unsigned char* data, unsigned int len)
 {
-	unsigned long i = 0, j = 0;
+	unsigned int i = 0, j = 0;
 
 	j = (m_count[0] >> 3) & 63;
 
@@ -123,7 +123,7 @@
 
 void CSHA1::Final()
 {
-	unsigned long i = 0, j = 0;
+	unsigned int i = 0, j = 0;
 	unsigned char finalcount[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
 
 	for (i = 0; i < 8; i++)
