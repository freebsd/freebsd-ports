--- contrib/olsr/message.hh.orig	2012-01-11 17:56:10 UTC
+++ contrib/olsr/message.hh
@@ -668,8 +668,8 @@ public:
 	return (str += '\n');
     }
 
-private:
-    size_t	_opaque_data_offset;
+// private:
+//    size_t	_opaque_data_offset;
 };
 
 /**
