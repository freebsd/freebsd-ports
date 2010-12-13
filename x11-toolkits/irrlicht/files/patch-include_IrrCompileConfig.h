--- include/IrrCompileConfig.h	2010-12-13 13:05:25.000000000 -0500
+++ include/IrrCompileConfig.h	2010-12-13 13:09:57.000000000 -0500
@@ -176,7 +176,7 @@
 //! Define _IRR_USE_NON_SYSTEM_JPEG_LIB_ to let irrlicht use the jpeglib which comes with irrlicht.
 /** If this is commented out, Irrlicht will try to compile using the jpeg lib installed in the system.
 	This is only used when _IRR_COMPILE_WITH_LIBJPEG_ is defined. */
-#define _IRR_USE_NON_SYSTEM_JPEG_LIB_
+//#define _IRR_USE_NON_SYSTEM_JPEG_LIB_
 
 
 //! Define _IRR_COMPILE_WITH_LIBPNG_ to enable compiling the engine using libpng.
@@ -187,7 +187,7 @@
 //! Define _IRR_USE_NON_SYSTEM_LIBPNG_ to let irrlicht use the libpng which comes with irrlicht.
 /** If this is commented out, Irrlicht will try to compile using the libpng installed in the system.
 	This is only used when _IRR_COMPILE_WITH_LIBPNG_ is defined. */
-#define _IRR_USE_NON_SYSTEM_LIB_PNG_
+//#define _IRR_USE_NON_SYSTEM_LIB_PNG_
 
 
 //! Define _IRR_D3D_NO_SHADER_DEBUGGING to disable shader debugging in D3D9
@@ -348,14 +348,14 @@
 /** If this is commented out, Irrlicht will try to compile using the zlib
 installed on the system. This is only used when _IRR_COMPILE_WITH_ZLIB_ is
 defined. */
-#define _IRR_USE_NON_SYSTEM_ZLIB_
+//#define _IRR_USE_NON_SYSTEM_ZLIB_
 //! Define _IRR_COMPILE_WITH_ZIP_ENCRYPTION_ if you want to read AES-encrypted ZIP archives
 #define _IRR_COMPILE_WITH_ZIP_ENCRYPTION_
 //! Define _IRR_COMPILE_WITH_BZIP2_ if you want to support bzip2 compressed zip archives
 /** bzip2 is superior to the original zip file compression modes, but requires
 a certain amount of memory for decompression and adds several files to the
 library. */
-#define _IRR_COMPILE_WITH_BZIP2_
+//#define _IRR_COMPILE_WITH_BZIP2_
 //! Define _IRR_USE_NON_SYSTEM_BZLIB_ to let irrlicht use the bzlib which comes with irrlicht.
 /** If this is commented out, Irrlicht will try to compile using the bzlib
 installed on the system. This is only used when _IRR_COMPILE_WITH_BZLIB_ is
