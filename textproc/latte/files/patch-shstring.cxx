--- shstring.cxx.orig	Thu Dec  3 07:54:01 1998
+++ shstring.cxx	Fri Mar 19 01:17:52 2004
@@ -16,9 +16,11 @@
 // The Initial Developer of the Original Code is Zanshin, Inc.
 
 #include <shstring.h>
-#include <iostream.h>
+#include <iostream>
 #include <cstring>
 
+using namespace std;
+
 shstring::shstring() : rep(0)
 {
 }
@@ -105,6 +107,45 @@
     return 1;
   else
     return 0;
+}
+
+bool
+shstring::operator <= (const shstring &other) const
+{
+  if (rep.get()) {
+    if (other.rep.get())
+      return rep->str() <= other.rep->str();
+    return 0;
+  } else if (other.rep.get())
+    return 1;
+  else
+    return 0;
+}
+
+bool
+shstring::operator > (const shstring &other) const
+{
+  if (rep.get()) {
+    if (other.rep.get())
+      return rep->str() > other.rep->str();
+    return 0;
+  } else if (other.rep.get())
+    return 0;
+  else
+    return 1;
+}
+
+bool
+shstring::operator >= (const shstring &other) const
+{
+  if (rep.get()) {
+    if (other.rep.get())
+      return rep->str() >= other.rep->str();
+    return 0;
+  } else if (other.rep.get())
+    return 0;
+  else
+    return 1;
 }
 
 bool
