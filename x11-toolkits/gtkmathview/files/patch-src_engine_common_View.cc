View.cc:294:10: error: no viable conversion from returned value of type 'bool' to function return type 'SmartPtr<Element>'
  return false;
         ^~~~~

--- src/engine/common/View.cc.orig	2018-08-25 13:57:22 UTC
+++ src/engine/common/View.cc
@@ -291,7 +291,7 @@ View::getCharAt(const scaled& x, const scaled& y, Char
 	  }
     }
 
-  return false;
+  return 0;
 }
 
 bool
