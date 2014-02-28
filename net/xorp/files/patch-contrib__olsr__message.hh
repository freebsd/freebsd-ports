--- ./contrib/olsr/message.hh.orig	2012-01-11 17:46:45.000000000 +0000
+++ ./contrib/olsr/message.hh	2014-02-26 21:17:13.000000000 +0000
@@ -668,8 +668,8 @@
 	return (str += '\n');
     }
 
-private:
-    size_t	_opaque_data_offset;
+// private:
+//    size_t	_opaque_data_offset;
 };
 
 /**
