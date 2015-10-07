--- src/IPAddress.h.orig	2010-09-29 03:23:24.000000000 +0200
+++ src/IPAddress.h	2015-08-20 23:35:26.583907000 +0200
@@ -16,7 +16,7 @@ public:
 
 	virtual int GetType() const = 0;
 	virtual bool operator==( const IPAddress & ) const = 0;
-	virtual bool operator!=( const IPAddress & addr ) const { return !operator!=(addr); }
+	virtual bool operator!=( const IPAddress & addr ) const { return !operator==(addr); }
 	virtual char * ptr() const = 0;
 	virtual uint32_t hash() const = 0;
 	virtual IPAddress* Clone() const = 0;
