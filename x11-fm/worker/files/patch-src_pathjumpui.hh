--- src/pathjumpui.hh.orig	2015-01-08 18:44:53.000000000 +0300
+++ src/pathjumpui.hh	2015-01-20 00:01:56.000000000 +0300
@@ -101,7 +101,7 @@
                                                     m_always_ignore( false )
         {}
 
-        bool operator<( const pathjump_entry &rhs )
+        bool operator<( const pathjump_entry &rhs ) const
         {
             if ( m_blockcount < rhs.m_blockcount ) return true;
             else if ( m_blockcount == rhs.m_blockcount ) {
