--- llist.cpp.orig	Sat Jul  6 18:36:20 2002
+++ llist.cpp	Thu Aug  5 15:22:51 2004
@@ -4,11 +4,13 @@
  * $Id: llist.cpp,v 1.2 2002/01/07 17:18:49 fx Exp $
  */
 
-#include <iostream.h>
+#include <iostream>
 #include <string.h>
 #include <stdlib.h>
 
 #include "llist.h"
+
+using namespace std;
 
 LinkList::LinkList() {
 	anchor=current=NULL;
