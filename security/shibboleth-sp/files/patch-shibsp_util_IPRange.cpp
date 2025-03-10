--- shibsp/util/IPRange.cpp.bak	2024-09-10 19:52:20.000000000 +0000
+++ shibsp/util/IPRange.cpp	2024-10-31 10:12:49.160721000 +0000
@@ -119,9 +119,9 @@
         if (log.isDebugEnabled()) {
             log.debug(
                 "comparing address (%s) to network (%s) with mask (%s)",
-                rawbits.to_string< char, char_traits<char>, allocator<char> >().c_str(),
-                m_network4.to_string< char, char_traits<char>, allocator<char> >().c_str(),
-                m_mask4.to_string< char, char_traits<char>, allocator<char> >().c_str()
+                rawbits.to_string< char, std::char_traits<char>, allocator<char> >().c_str(),
+                m_network4.to_string< char, std::char_traits<char>, allocator<char> >().c_str(),
+                m_mask4.to_string< char, std::char_traits<char>, allocator<char> >().c_str()
                 );
         }
         rawbits &= m_mask4;
@@ -141,9 +141,9 @@
         if (log.isDebugEnabled()) {
             log.debug(
                 "comparing address (%s) to network (%s) with mask (%s)",
-                rawbits.to_string< char, char_traits<char>, allocator<char> >().c_str(),
-                m_network6.to_string< char, char_traits<char>, allocator<char> >().c_str(),
-                m_mask6.to_string< char, char_traits<char>, allocator<char> >().c_str()
+                rawbits.to_string< char, std::char_traits<char>, allocator<char> >().c_str(),
+                m_network6.to_string< char, std::char_traits<char>, allocator<char> >().c_str(),
+                m_mask6.to_string< char, std::char_traits<char>, allocator<char> >().c_str()
                 );
         }
         rawbits &= m_mask6;
