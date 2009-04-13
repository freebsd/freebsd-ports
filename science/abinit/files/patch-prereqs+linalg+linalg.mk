--- prereqs/linalg/linalg.mk~	2009-03-11 14:12:18.000000000 +0900
+++ prereqs/linalg/linalg.mk	2009-04-13 11:39:18.000000000 +0900
@@ -32,7 +32,7 @@
 	touch build-stamp
 
 install-stamp: build
-	$(MKDIR_P) tmp/lib
+	mkdir -p tmp/lib
 	cp blas/libblas.a lapack/liblapack.a tmp/lib
 	touch install-stamp
 
