
$FreeBSD$

--- utilbin/infotext.c.orig	Tue Mar 30 16:50:40 2004
+++ utilbin/infotext.c	Tue Mar 30 16:51:20 2004
@@ -1035,7 +1035,7 @@
    DPRINTF(("pass 4\n"));
    {
       if (real_args > 0) {
-#if defined(ALPHA) || defined(ALPHA5) || defined(ALINUX) || defined(HP11) || defined(HP10) || __GNUC__ == 3
+#if defined(ALPHA) || defined(ALPHA5) || defined(ALINUX) || defined(HP11) || defined(HP10) || defined(FREEBSD_ALPHA) || __GNUC__ == 3
       for(i=0;i<real_args;i++) {
 /*      printf("argument[%d]: \"%s\"\n",i,argv[first_arg +i]); */
          sge_dstring_copy_string(&buffer, sge_infotext_string_replace(&tmp_buf, (char*)sge_dstring_get_string(&buffer2),"%s",argv[first_arg +i],1));
