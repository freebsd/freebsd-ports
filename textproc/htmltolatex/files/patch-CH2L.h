
$FreeBSD$

--- CH2L.h.orig	Fri Feb 21 01:22:49 2003
+++ CH2L.h	Fri Feb 21 02:08:08 2003
@@ -189,6 +189,7 @@
 	///////////////////////////////////////////////
 
 	//////////////// spidering //////////////////
+public:
 	struct spider_info {
 		std::string	mUrl;
 		std::string mLocalTag;
@@ -200,6 +201,7 @@
 		
 		friend std::ostream& operator<<(std::ostream &o,const spider_info &si);
 	};
+private:
 	typedef std::map<string,spider_info>	SpiderTable_t;
 	SpiderTable_t	mSpiderTable;
 	bool			mSpidering;	// not the first page
