--- mstorage_add.c.orig	Thu Feb  5 00:27:01 2004
+++ mstorage_add.c	Thu Feb 26 16:03:58 2004
@@ -54,9 +54,9 @@
 	if (!tmp) return -1;
       } else {
 	munmap(p->root,p->used);
-	tmp=mmap(0,need,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
+	tmp=mmap(0,need,PROT_READ|PROT_WRITE,MAP_SHARED,p->fd,0);
 	if (tmp==-1) {
-	  tmp=mmap(0,p->used,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
+	  tmp=mmap(0,p->used,PROT_READ|PROT_WRITE,MAP_SHARED,p->fd,0);
 	  /* this can never fail, because we mmap exactly as much as we
 	   * had mmapped previously.  We need to munmap before doing the
 	   * new mmap, though, because we may run into the address space
