--- lib/epson-escpr-api.c.orig	2024-03-13 01:23:02 UTC
+++ lib/epson-escpr-api.c
@@ -231,7 +231,7 @@ static const EPS_UINT8 PrintQualityCmd[] = {
 
     /*** ESC/P-R Commands (Print Num)                                                   */
     /*** -------------------------------------------------------------------------------*/
-static const EPS_UINT8 PrintNumCmd[] = {
+static const EPS_UINT8 PrintNumCmd[] __unused = {
 	                        0x1B, 'n', 0x02, 0x00, 0x00, 0x00,
                             's', 'e', 't', 'n',
                             0x00, 0x00};
@@ -251,7 +251,7 @@ static const EPS_UINT8 SetiCmd[]   = {
 
     /*** ESC/P-R Commands (custom setting)                                              */
     /*** -------------------------------------------------------------------------------*/
-static const EPS_UINT8 CustomCmd[]       = {
+static const EPS_UINT8 CustomCmd[] __unused       = {
 	                        0x1B, 'm', 0x01, 0x00, 0x00, 0x00,
                             's', 'e', 't', 'c',
                             0x00 };
@@ -4506,7 +4506,7 @@ EPS_UINT8       array4[4] = {0, 0, 0, 0};   /* Tempora
 /*======================================================================================*/
 /*** Set up ESC/PR "Print Num" Command                                                  */
 /*======================================================================================*/
-static void    MakePageNumCmd (
+static void    __unused MakePageNumCmd (
 
         EPS_UINT8*		pBuf
 
