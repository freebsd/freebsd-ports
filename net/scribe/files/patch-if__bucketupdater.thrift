--- ./if/bucketupdater.thrift.orig	2011-06-27 09:59:22.000000000 +0400
+++ ./if/bucketupdater.thrift	2011-10-19 18:33:32.000000000 +0400
@@ -19,6 +19,7 @@
 
 namespace cpp scribe.thrift
 namespace java com.facebook.infrastructure.service
+namespace perl Scribe.Thrift
 
 // BucketStoreMapping service exception
 exception BucketStoreMappingException {
