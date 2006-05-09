--- src/cpca_mk_cmd.c.orig	Wed Mar 15 15:00:26 2006
+++ src/cpca_mk_cmd.c	Wed Mar 15 15:33:26 2006
@@ -586,6 +586,7 @@
   Ptr             data ;
   short           size ;
   Ptr             work ;
+  short          *swork ;
   unsigned long   comSize = 0 ;
 
   if (p && str) {
@@ -594,7 +595,9 @@
     if (data) {
       work = data ;
 
-      *( ( short *)work )++ = id_val_code_set_Shift_JIS ;
+	  swork = (short *)work ;
+      *swork++ = id_val_code_set_Shift_JIS ;
+	  work = (Ptr)swork ;
       memcpy( work, str, (unsigned char)str[ 0 ] + 1 ) ;
       comSize = glue_cpcaSetJob( p,
                                  Attribute,
@@ -867,6 +870,7 @@
   short          size ;
   Ptr            data ;
   Ptr            work ;
+  unsigned short *uswork ;
   unsigned long  comSize = 0 ;
 
   if (p) {
@@ -877,8 +881,10 @@
 
       *work++ = id_val_resolution_type_dpi ;
 
-      *( ( unsigned short *)work )++ = resolutionX ;
-      *( ( unsigned short *)work )++ = resolutionY ;
+	  uswork = (unsigned short *)work ;
+      *uswork++ = resolutionX ;
+      *uswork++ = resolutionY ;
+      work = (Ptr)uswork ;
 
       comSize = glue_cpcaSetDocument ( p,
                                        id_att_resolution,
@@ -1597,6 +1603,8 @@
   short                paramSize ;
   unsigned long        userID ;
   unsigned long        password ;
+  cpcaHANDLE           *cpcaHANDLEp ;
+  cpcaUBYTE            *cpcaUBYTEp ;
 
 
   z_setUserInfo( userInfo, &userID, &password ) ;
@@ -1616,9 +1624,14 @@
   p += comSize ;
 
   /* 固有パラメータの設定 */
-  *( ( cpcaHANDLE *)p )++  = inParam->Object1 ;
-  *( ( cpcaUBYTE  *)p )++  = inParam->Mode ;
-  *( ( cpcaHANDLE *)p )++  = inParam->Object2 ;
+  cpcaHANDLEp = (cpcaHANDLE *)p ;
+  *cpcaHANDLEp++  = inParam->Object1 ;
+  cpcaUBYTEp = (cpcaUBYTE *)cpcaHANDLEp ;
+  *cpcaUBYTEp++  = inParam->Mode ;
+  cpcaHANDLEp = (cpcaHANDLE *)cpcaUBYTEp ;
+  *cpcaHANDLEp++  = inParam->Object2 ;
+  p = (Ptr)cpcaHANDLEp ;
+
   comSize += 9;
 
   return comSize ;
@@ -1644,7 +1657,7 @@
   short             paramSize ;
   unsigned long     userID ;
   unsigned long     password ;
-
+  cpcaATTRIB        *cpcaATTRIBp;
 	
   z_setUserInfo( userInfo, &userID, &password ) ;
   paramSize = 2 + inParam->Size ;
@@ -1661,7 +1674,9 @@
   p += comSize ;
 
   /*  固有パラメータの設定 */
-  *( ( cpcaATTRIB *)p )++  = inParam->Attribute ;
+  cpcaATTRIBp = (cpcaATTRIB *)p ;
+  *cpcaATTRIBp++  = inParam->Attribute ;
+  p = (Ptr)cpcaATTRIBp ;
   if ( inParam->Data && ( inParam->Size > 0 ) )
   {
     memcpy( p, inParam->Data, inParam->Size ) ;
@@ -1687,6 +1702,7 @@
   short               paramSize ;
   unsigned long       userID ;
   unsigned long       password ;
+  cpcaHANDLE          *cpcaHANDLEp ;
 
   z_setUserInfo( userInfo, &userID, &password ) ;
   paramSize = sizeof( cpcaHANDLE ) ;
@@ -1703,7 +1719,10 @@
   p += comSize ;
 
   /*  固有パラメータの設定 */
-  *( ( cpcaHANDLE *)p )++ = inParam->Object ;
+  cpcaHANDLEp = (cpcaHANDLE *)p ;
+  *cpcaHANDLEp++ = inParam->Object ;
+  p = (Ptr)cpcaHANDLEp ;
+
   comSize += paramSize ;
 
   return comSize ;
@@ -1723,6 +1742,7 @@
   short             paramSize ;
   unsigned long     userID ;
   unsigned long     password ;
+  cpcaATTRIB        *cpcaATTRIBp;
 
   z_setUserInfo( userInfo, &userID, &password ) ;
   paramSize = sizeof( cpcaATTRIB ) + inParam->Size ;
@@ -1739,7 +1759,9 @@
   p += comSize ;
 
   /*  固有パラメータの設定 */
-  *( ( cpcaATTRIB *)p )++ = inParam->Attribute ;
+  cpcaATTRIBp = (cpcaATTRIB *)p; 
+  *cpcaATTRIBp++ = inParam->Attribute ;
+  p = (Ptr)cpcaATTRIBp ;
   if ( inParam->Data && ( inParam->Size > 0 ) )
   {
     memcpy( p, inParam->Data, inParam->Size ) ;
@@ -1764,22 +1786,27 @@
   short                 comSize ;
   Ptr                   work ;
   char                  BindName;
+  unsigned char         *ucwork ;
 
   work = p ;
 
   /* ビンエイリアスの設定 */
-  *( ( unsigned char *)work )++ = bindInfo;
+  ucwork = (unsigned char *)work ;
+  *ucwork++ = bindInfo;
   /* ビン番号の設定＝なし（０を指定) */
-  *( ( unsigned char *)work )++ = bindNum ;
+  *ucwork++ = bindNum ;
   /* ビン名称指定 */
   /*  null文字列指定 */
   BindName = 0;
+  work = (Ptr)ucwork ;
 
   memcpy( ( StringPtr )work, &BindName, 1 ) ;
   work += 1 ;
   /* 開始ビン、終了ビン指定 */
-  *( ( unsigned char *)work )++ = 0 ;
-  *( ( unsigned char *)work )++ = 0 ;
+  ucwork = (unsigned char *)work ;
+  *ucwork++ = 0 ;
+  *ucwork++ = 0 ;
+  work = (Ptr)ucwork ;
   /* サイズの取得 */
   comSize = work - p ;
 
@@ -1803,19 +1830,24 @@
   Ptr                   work ;
   char                  count;
   char                  str_count;
+  unsigned char         *ucwork ;
+  unsigned short        *uswork ;
 
   work = p ;
   count = 1;
   str_count = 1;
 
   /* Type:フィニッシング方法の設定 */
-  *( ( unsigned char *)work )++ = str_count;
+  ucwork = (unsigned char *)work ;
+  *ucwork++ = str_count;
   /* Type:フィニッシング方法の設定 */
-  *( ( unsigned char *)work )++ = id_val_finishing_type_staple_stitching;
+  *ucwork++ = id_val_finishing_type_staple_stitching;
   /* Count:フィニッシングを行う個数 */
-  *( ( unsigned char *)work )++ = count ;
+  *ucwork++ = count ;
   /* Locate:フィニッシングを行う箇所 */
-  *( ( unsigned short *)work )++ = staple_val;
+  uswork = (unsigned short *)ucwork ;
+  *uswork++ = staple_val;
+  work = (Ptr)uswork ;
   /* サイズの取得 */
   comSize = work - p ;
 
@@ -1839,6 +1871,7 @@
   short          paramSize ;
   unsigned long  userID ;
   unsigned long  password ;
+  cpcaHANDLE     *cpcaHANDLEp ;
 
   z_setUserInfo( userInfo, &userID, &password ) ;
   paramSize = 4 ;
@@ -1855,7 +1888,9 @@
   p += comSize ;
 
   /* 固有パラメータの設定 */
-  *( ( cpcaHANDLE *)p )++ = inParam->Object ;
+  cpcaHANDLEp = (cpcaHANDLE *)p ;
+  *cpcaHANDLEp++ = inParam->Object ;
+  p = (Ptr)cpcaHANDLEp ;
   comSize += paramSize ;
 
   return comSize ;
@@ -1876,7 +1911,7 @@
   short           paramSize ;
   unsigned long   userID ;
   unsigned long   password ;
-
+  cpcaATTRIB      *cpcaATTRIBp ;
 
   z_setUserInfo( userInfo, &userID, &password ) ;
   paramSize = 2 + inParam->Size ;
@@ -1893,7 +1928,9 @@
   p += comSize ;
 
   /* 固有パラメータの設定 */
-  *( ( cpcaATTRIB *)p )++ = inParam->Attribute ;
+  cpcaATTRIBp = (cpcaATTRIB *)p ;
+  *cpcaATTRIBp++ = inParam->Attribute ;
+  p = (Ptr)cpcaATTRIBp ;
   if ( inParam->Data && ( inParam->Size > 0 ) )
   {
     memcpy( p, inParam->Data, inParam->Size ) ;
@@ -1918,6 +1955,8 @@
   short           paramSize ;
   unsigned long   userID ;
   unsigned long   password ;
+  cpcaHANDLE      *cpcaHANDLEp ;
+  cpcaUSHORT      *cpcaUSHORTp ;
 
   z_setUserInfo( userInfo, &userID, &password ) ;
   paramSize = 6 + inParam->Size ;
@@ -1934,8 +1973,11 @@
   p += comSize ;              
 
   /* 固有パラメータの設定 */
-  *( ( cpcaHANDLE *)p )++     = inParam->Object ;
-  *( ( cpcaUSHORT *)p )++     = inParam->Method ;
+  cpcaHANDLEp = (cpcaHANDLE *)p ;
+  *cpcaHANDLEp++     = inParam->Object ;
+  cpcaUSHORTp = (cpcaUSHORT *)cpcaHANDLEp ;
+  *cpcaUSHORTp++     = inParam->Method ;
+  p = (Ptr)cpcaUSHORTp ;
   if ( inParam->Data && ( inParam->Size > 0 ) )
   {
     memcpy( p, inParam->Data, inParam->Size ) ;
@@ -2075,6 +2117,7 @@
   short                 paramSize ;
   unsigned long         userID ;
   unsigned long         password ;
+  cpcaUBYTE             *cpcaUBYTEp ;
 
   z_setUserInfo( userInfo, &userID, &password ) ;
   paramSize = 1 ;
@@ -2091,7 +2134,9 @@
   p += comSize ;
 
   /* 固有パラメータの設定 */
-  *( ( cpcaUBYTE *)p )++ = inParam->Code ;
+  cpcaUBYTEp = (cpcaUBYTE *)p ;
+  *cpcaUBYTEp++ = inParam->Code ;
+  p = (Ptr)cpcaUBYTEp ;
   comSize += paramSize ;
 
   return comSize ;
