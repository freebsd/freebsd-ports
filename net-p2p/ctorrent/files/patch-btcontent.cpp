--- btcontent.cpp.orig	2008-06-15 00:00:19 UTC
+++ btcontent.cpp
@@ -283,11 +283,12 @@ int btContent::InitialFromMI(const char *metainfo_fnam
   if ( !b ) return -1;
 
   // announce
-  if( !meta_str("announce",&s,&r) ) ERR_RETURN();
+  if( meta_str("announce",&s,&r) ) {
   if( r > MAXPATHLEN ) ERR_RETURN();
   m_announce = new char [r + 1];
   memcpy(m_announce, s, r);
   m_announce[r] = '\0';
+  }
 
   // announce-list
   if( r = meta_pos("announce-list") ){
@@ -303,7 +304,7 @@ int btContent::InitialFromMI(const char *metainfo_fnam
           if( !(q = buf_str(b+r, alend-r, &sptr, &slen)) )
             break;  // next list
           r += q;
-          if( strncasecmp(m_announce, sptr, slen) ){
+          if( !m_announce || strncasecmp(m_announce, sptr, slen) ){
             m_announcelist[n] = new char[slen+1];
             memcpy(m_announcelist[n], sptr, slen);
             (m_announcelist[n])[slen] = '\0';
