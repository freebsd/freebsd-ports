--- src/binaryio.h.orig	Thu Sep 26 14:38:10 2002
+++ src/binaryio.h	Thu Sep 26 14:39:22 2002
@@ -22,22 +22,21 @@
 #define SH_BINARYIO_H
 
 #include <stdio.h>
-#include <string>
 
 class BinaryIO {
 	public:
 	enum MODE { READ, WRITE } ;
 
 	BinaryIO (void) ;
-	BinaryIO (string fn, MODE m) ;
+	BinaryIO (std::string fn, MODE m) ;
 	~BinaryIO (void) ;
 
-	string getName (void) ;
+	std::string getName (void) ;
 	bool is_open (void) ;
 	bool is_std (void) ;
 	bool eof (void) ;
 
-	void open (string fn, MODE m) ;	
+	void open (std::string fn, MODE m) ;	
 	void close (void) ;
 
 	unsigned char read8 (void) ;
@@ -45,25 +44,25 @@
 	unsigned int read16_be (void) ;
 	unsigned long read32_le (void) ;
 	unsigned long read32_be (void) ;
-	string readstring (unsigned int len) ;
+	std::string readstring (unsigned int len) ;
 
 	void write8 (unsigned char val) ;
 	void write16_le (unsigned int val) ;
 	void write16_be (unsigned int val) ;
 	void write32_le (unsigned long val) ;
 	void write32_be (unsigned long val) ;
-	void writestring (string s) ;
+	void writestring (std::string s) ;
 
 	protected:
 	void setStream (FILE *s) ;
 	FILE *getStream (void) ;
-	void setName (string fn) ;
+	void setName (std::string fn) ;
 	void set_open (bool fo) ;
 	MODE getMode (void) ;
 	void setMode (BinaryIO::MODE m) ;
 
 	private:
-	string filename ;
+	std::string filename ;
 	FILE *stream ;
 	bool fileopen ;
 	MODE mode ;
