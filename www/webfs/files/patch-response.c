--- response.c.orig	Fri Oct 12 11:48:48 2001
+++ response.c	Wed Jan 30 08:28:59 2002
@@ -201,12 +201,12 @@
     req->r_hlen[i] = sprintf(req->r_head+i*BR_HEADER,
 			     "\r\n--" BOUNDARY "\r\n"
 			     "Content-type: %s\r\n"
-			     "Content-range: bytes %ld-%ld/%ld\r\n"
+			     "Content-range: bytes %lld-%lld/%lld\r\n"
 			     "\r\n",
 			     now, req->mime,
 			     req->r_start[i],req->r_end[i]-1,req->bst.st_size);
     if (debug > 1)
-	fprintf(stderr,"%03d: send range: %ld-%ld/%ld (%ld byte)\n",
+	fprintf(stderr,"%03d: send range: %lld-%lld/%lld (%lld byte)\n",
 		req->fd,
 		req->r_start[i],req->r_end[i],req->bst.st_size,
 		req->r_end[i]-req->r_start[i]);
@@ -230,14 +230,14 @@
     if (req->ranges == 0) {
 	req->lres += sprintf(req->hres+req->lres,
 			     "Content-Type: %s\r\n"
-			     "Content-Length: %ld\r\n",
+			     "Content-Length: %lld\r\n",
 			     req->mime,
 			     req->body ? req->lbody : req->bst.st_size);
     } else if (req->ranges == 1) {
 	req->lres += sprintf(req->hres+req->lres,
 			     "Content-Type: %s\r\n"
-			     "Content-Range: bytes %ld-%ld/%ld\r\n"
-			     "Content-Length: %ld\r\n",
+			     "Content-Range: bytes %lld-%lld/%lld\r\n"
+			     "Content-Length: %lld\r\n",
 			     req->mime,
 			     req->r_start[0],req->r_end[0]-1,req->bst.st_size,
 			     req->r_end[0]-req->r_start[0]);
@@ -253,7 +253,7 @@
 	req->lres += sprintf(req->hres+req->lres,
 			     "Content-Type: multipart/byteranges;"
 			     " boundary=" BOUNDARY "\r\n"
-			     "Content-Length: %ld\r\n",
+			     "Content-Length: %lld\r\n",
 			     now,len);
     }
     if (mtime != -1) {
@@ -388,7 +388,7 @@
 		return;
 	    default:
 		if (debug > 1)
-		    fprintf(stderr,"%03d: %ld/%ld (%ld%%)\r",req->fd,
+		    fprintf(stderr,"%03d: %lld/%lld (%lld%%)\r",req->fd,
 			    req->written,req->bst.st_size,
 			    req->written*100/req->bst.st_size);
 		req->written += rc;
