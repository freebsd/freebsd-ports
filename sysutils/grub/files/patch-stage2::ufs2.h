--- stage2/ufs2.h.orig	Tue Jun 15 09:22:12 2004
+++ stage2/ufs2.h	Tue Jun 15 09:28:20 2004
@@ -68,12 +68,12 @@
  * __uint* constants already defined in
  * FreeBSD's /usr/include/machine/_types.h
  */
-#ifndef _MACHINE__TYPES_H_
+#if !defined(_MACHINE__TYPES_H_) && !defined(_MACHINE_ANSI_H_)
 typedef uint8_t                __uint8_t;
 typedef uint16_t               __uint16_t;
 typedef uint32_t               __uint32_t;
 typedef uint64_t               __uint64_t;
-#endif /* _MACHINE__TYPES_H_ */
+#endif /* !_MACHINE__TYPES_H_ && !_MACHINE_ANSI_H_ */
 
 #define i_size di_size
 
