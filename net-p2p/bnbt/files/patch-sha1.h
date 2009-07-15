--- sha1.h	2009-06-30 14:02:51.000000000 -0700
+++ sha1.h.new	2009-06-30 14:02:47.000000000 -0700
@@ -59,7 +59,7 @@
 
 	typedef union {
 		unsigned char c[64];
-		unsigned long l[16];
+		unsigned int l[16];
 	} SHA1_WORKSPACE_BLOCK;
 
 	// Two different formats for ReportHash(...)
@@ -69,8 +69,8 @@
 	CSHA1();
 	virtual ~CSHA1();
 
-	unsigned long m_state[5];
-	unsigned long m_count[2];
+	unsigned int m_state[5];
+	unsigned int m_count[2];
 	unsigned char m_buffer[64];
 	unsigned char m_digest[20];
 
@@ -86,7 +86,7 @@
 
 private:
 	// Private SHA-1 transformation
-	void Transform(unsigned long state[5], const unsigned char buffer[64]);
+	void Transform(unsigned int state[5], const unsigned char buffer[64]);
 };
 
 #endif // ___SHA1_H___
