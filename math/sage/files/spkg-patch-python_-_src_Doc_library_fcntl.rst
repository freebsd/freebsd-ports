--- python-2.7.3.p0/src/Doc/library/fcntl.rst.orig	2011-06-11 15:46:23.000000000 +0000
+++ python-2.7.3.p3/src/Doc/library/fcntl.rst	2012-04-22 00:31:48.000000000 +0000
@@ -50,8 +50,6 @@
    operations are typically defined in the library module :mod:`termios` and the
    argument handling is even more complicated.
 
-   The op parameter is limited to values that can fit in 32-bits.
-
    The parameter *arg* can be one of an integer, absent (treated identically to the
    integer ``0``), an object supporting the read-only buffer interface (most likely
    a plain Python string) or an object supporting the read-write buffer interface.
