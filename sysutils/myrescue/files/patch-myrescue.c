--- myrescue.c.orig	2017-02-10 01:59:06 UTC
+++ myrescue.c
@@ -36,7 +36,7 @@
 
 long long filesize ( int fd )
 {
-	long long rval = lseek64(fd, 0, SEEK_END) ;
+	long long rval = lseek(fd, 0, SEEK_END) ;
 	if (rval < 0) {
 		perror("filesize");
 		exit(-1);
@@ -47,8 +47,8 @@ long long filesize ( int fd )
 int peek_map(int bitmap_fd, int block)
 {
 	char c = 0;
-	if (lseek64(bitmap_fd, block, SEEK_SET) < 0) {
-		perror("peek_map lseek64");
+	if (lseek(bitmap_fd, block, SEEK_SET) < 0) {
+		perror("peek_map lseek");
 		exit(-1);
 	}
 	if (read(bitmap_fd, &c, 1) < 0) {
@@ -60,8 +60,8 @@ int peek_map(int bitmap_fd, int block)
 
 void poke_map(int bitmap_fd, int block, char val)
 {
-	if (lseek64(bitmap_fd, block, SEEK_SET) < 0) {
-		perror("poke_map lseek64");
+	if (lseek(bitmap_fd, block, SEEK_SET) < 0) {
+		perror("poke_map lseek");
 		exit(-1);
 	}
 	if (write(bitmap_fd, &val, 1) != 1) {
@@ -81,13 +81,13 @@ int copy_block( int src_fd, int dst_fd, 
 	filepos = block_num;
 	filepos *= block_size;
 
-	if (lseek64(src_fd, filepos, SEEK_SET) < 0) {
-		perror("lseek64 src_fd");
+	if (lseek(src_fd, filepos, SEEK_SET) < 0) {
+		perror("lseek src_fd");
 		return errno;
 	}
 
-	if (lseek64(dst_fd, filepos, SEEK_SET) < 0) {
-		perror("lseek64 dst_fd");
+	if (lseek(dst_fd, filepos, SEEK_SET) < 0) {
+		perror("lseek dst_fd");
 		return errno;
 	}
 
@@ -479,19 +479,19 @@ int main(int argc, char** argv)
 
 	/* open files */
 
-	src_fd = open64(src_name, O_RDONLY);
+	src_fd = open(src_name, O_RDONLY);
 	if ( src_fd < 0 ) {
 		perror ( "source open failed" ) ;
 		exit(-1) ;
 	}
 
-	dst_fd = open64(dst_name, O_RDWR | O_CREAT, 0600);
+	dst_fd = open(dst_name, O_RDWR | O_CREAT, 0600);
 	if ( dst_fd < 0 ) {
 		perror ( "destination open failed" ) ;
 		exit(-1) ;
 	}
 
-	bitmap_fd = open64(bitmap_name, O_RDWR | O_CREAT, 0600);
+	bitmap_fd = open(bitmap_name, O_RDWR | O_CREAT, 0600);
 	if ( bitmap_fd < 0 ) {
 		perror ( "bitmap open failed" ) ;
 		exit(-1) ;
