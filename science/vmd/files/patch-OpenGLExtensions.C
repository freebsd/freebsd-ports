--- src/OpenGLExtensions.C-xxx	Fri Dec  5 13:21:59 2003
+++ src/OpenGLExtensions.C	Fri Aug 27 16:42:14 2004
@@ -117,7 +117,17 @@
 #endif
 
 #if !defined(_MSC_VER) && !defined(__APPLE__)
-#if !defined(ARCH_LINUX) && !defined(ARCH_LINUXALPHA) && !defined(ARCH_LINUXAMD64) && !defined(ARCH_LINUXPPC) && (defined(GLX_VERSION_1_4) || defined(ARCH_SOLARIS2))
+/*
+   Why the !defined(ARCH_FREEBSD)?  Typically the X libraries that
+   come with FreeBSD work with glXGetProcAddress.  However, if the
+   nvidia-driver port is installed, it seems not to work.  But using
+   glXGetProcAddressARB seems to work whether or not the nvidia-driver
+   port is installed.  (To be honest, I do feel that this is a bit hackish,
+   and maybe this will break something in other environments, but lets face
+   that bridge when we come to it - email me at stephen@math.missouri.edu
+   about it.)
+*/
+#if !defined(ARCH_FREEBSD) && !defined(ARCH_LINUX) && !defined(ARCH_LINUXALPHA) && !defined(ARCH_LINUXAMD64) && !defined(ARCH_LINUXPPC) && (defined(GLX_VERSION_1_4) || defined(ARCH_SOLARIS2))
   // GLX 1.4 form found on commercial Unix systems that
   // don't bother providing the ARB extension version that Linux prefers.
   return glXGetProcAddress((const GLubyte *) procname);
