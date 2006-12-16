diff -u src/IPv4Address.h.orig src/IPv4Address.h
--- src/IPv4Address.h.orig	Sat Dec 16 00:42:10 2006
+++ src/IPv4Address.h	Sat Dec 16 00:42:51 2006
@@ -13,7 +13,7 @@
 	IPv4Address(IPv4Address &na) { a=na.toStruct(); }
 	bool operator==( const IPv4Address & ) const;
 	bool operator!=( const IPv4Address & ) const;
-	char * IPv4Address::ptr() const;
+	char * ptr() const;
 	friend ostream & operator<<( ostream &, const IPv4Address &);
 	struct in_addr toStruct() const;
 private:
