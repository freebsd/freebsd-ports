--- src/normalform/RadixSet.cc.orig	2004-07-30 12:58:13.000000000 +0200
+++ src/normalform/RadixSet.cc
@@ -878,7 +878,7 @@ ostream& operator<<(ostream& o, const Ra
       	       need_comma = true;
       	    o << int2quad(buffer, addr) << "/" << leng << "^" << n << "-" << m;
       	 } // end of for loop
-      } else { // not a compressed point
+      } else { // not a compressed print
        	 RadixSet::PrefixIterator itr(&set);
 	       for (bool flag = itr.first(addr, leng); flag; flag = itr.next(addr, leng)) {
            if (need_comma)
