--- grub-core/gnulib/stdio.in.h.orig	2019-10-17 10:29:27 UTC
+++ grub-core/gnulib/stdio.in.h
@@ -141,7 +141,7 @@ _GL_WARN_ON_USE (fflush, "fflush is not always POSIX c
    so any use of gets warrants an unconditional warning.  Assume it is
    always declared, since it is required by C89.  */
 #undef gets
-_GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
+//_GL_WARN_ON_USE (gets, "gets is a security hole - use fgets instead");
 
 #if @GNULIB_FOPEN@
 # if @REPLACE_FOPEN@
