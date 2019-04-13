--- lib/epson-typedefs.h.orig	2019-04-08 01:01:26 UTC
+++ lib/epson-typedefs.h
@@ -41,7 +41,7 @@ extern "C" {
 typedef unsigned char  EPS_UINT8;       /* unsigned  8-bit  Min: 0          Max: 255        */
 typedef unsigned short EPS_UINT16;      /* unsigned 16-bit  Min: 0          Max: 65535      */
 typedef unsigned int   EPS_UINT32;      /* unsigned 32-bit  Min: 0          Max: 4294967295 */
-typedef signed char    EPS_INT8;        /*   signed  8-bit  Min: -128       Max: 127        */
+typedef char           EPS_INT8;        /*   signed  8-bit  Min: -128       Max: 127        */
 typedef short          EPS_INT16;       /*   signed 16-bit  Min: -32768     Max: 32767      */
 typedef int            EPS_INT32;       /*   signed 32-bit  Min:-2147483648 Max: 2147483647 */
 typedef float          EPS_FLOAT;       /*    float 32-bit  Min:3.4E-38     Max: 3.4E+38    */
