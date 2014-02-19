--- src/serialize.h.orig	2014-01-19 03:49:23.000000000 +0000
+++ src/serialize.h	2014-01-19 03:52:10.000000000 +0000
@@ -858,18 +858,6 @@
     iterator insert(iterator it, const char& x=char()) { return vch.insert(it, x); }
     void insert(iterator it, size_type n, const char& x) { vch.insert(it, n, x); }
 
-    void insert(iterator it, const_iterator first, const_iterator last)
-    {
-        if (it == vch.begin() + nReadPos && last - first <= nReadPos)
-        {
-            // special case for inserting at the front when there's room
-            nReadPos -= (last - first);
-            memcpy(&vch[nReadPos], &first[0], last - first);
-        }
-        else
-            vch.insert(it, first, last);
-    }
-
     void insert(iterator it, std::vector<char>::const_iterator first, std::vector<char>::const_iterator last)
     {
         if (it == vch.begin() + nReadPos && last - first <= nReadPos)
