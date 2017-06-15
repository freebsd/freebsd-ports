--- lib/epson-escpr-api.c.orig	2016-06-29 23:37:45 UTC
+++ lib/epson-escpr-api.c
@@ -62,6 +62,7 @@
 
 /*------------------------------------  Includes   -------------------------------------*/
 /*******************************************|********************************************/
+#include <stddef.h>
 #include "epson-escpr-pvt.h"
 #include "epson-escpr-services.h"
 #include "epson-escpr-pm.h"
@@ -231,7 +232,7 @@ static const EPS_UINT8 PrintQualityCmd[]
 
     /*** ESC/P-R Commands (Print Num)                                                   */
     /*** -------------------------------------------------------------------------------*/
-static const EPS_UINT8 PrintNumCmd[] = {
+static const EPS_UINT8 PrintNumCmd[] __unused = {
 	                        0x1B, 'n', 0x02, 0x00, 0x00, 0x00,
                             's', 'e', 't', 'n',
                             0x00, 0x00};
@@ -244,7 +245,7 @@ static const EPS_UINT8 PrintNumCmd2[] = 
 
     /*** ESC/P-R Commands (custom setting)                                              */
     /*** -------------------------------------------------------------------------------*/
-static const EPS_UINT8 CustomCmd[]       = {
+static const EPS_UINT8 CustomCmd[] __unused       = {
 	                        0x1B, 'm', 0x01, 0x00, 0x00, 0x00,
                             's', 'e', 't', 'c',
                             0x00 };
@@ -4463,7 +4464,7 @@ EPS_UINT8       array4[4] = {0, 0, 0, 0}
 /*======================================================================================*/
 /*** Set up ESC/PR "Print Num" Command                                                  */
 /*======================================================================================*/
-static void    MakePageNumCmd (
+static void    __unused MakePageNumCmd (
 
         EPS_UINT8*		pBuf
 
