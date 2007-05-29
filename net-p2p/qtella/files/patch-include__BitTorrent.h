--- include/BitTorrent.h.orig	Tue May 29 17:19:03 2007
+++ include/BitTorrent.h	Tue May 29 17:19:18 2007
@@ -67,7 +67,7 @@
 public:
 	~BitTorrent();
 	static BitTorrent* decode( const char* buf, int len );
-	static BitTorrent* BitTorrent::bt_decode_file( const char* filename );
+	static BitTorrent* bt_decode_file( const char* filename );
 	void setAnnounce( const std::string& announce );
 	const std::string& getAnnounce() const;
 	void setSingleFile( bool s );
