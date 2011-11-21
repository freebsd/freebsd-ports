--- src/os/unix/ngx_files.c.orig	2011-11-21 17:32:42.000000000 +0400
+++ src/os/unix/ngx_files.c	2011-11-21 17:33:28.000000000 +0400
@@ -454,7 +454,7 @@
 }
 
 
-#if (NGX_HAVE_POSIX_FADVISE)
+#if (NGX_HAVE_POSIX_FADVISE) && !(NGX_HAVE_F_READAHEAD)
 
 ngx_int_t
 ngx_read_ahead(ngx_fd_t fd, size_t n)
