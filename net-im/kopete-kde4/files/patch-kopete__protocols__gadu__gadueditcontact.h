------------------------------------------------------------------------
r1356912 | rkcosta | 2013-06-05 01:18:59 +0300 (Wed, 05 Jun 2013) | 8 lines

Forward-declaring a nested class is not valid C++.

Fix the build with at least clang 3.3 by actually including
gaducontactlist.h. While just removing the forward declaration also works
since all places which include gadueditcontact.h include gaducontactlist.h
first), it's better to be on the safe side and not rely on that.



Index: kopete/protocols/gadu/gadueditcontact.h
===================================================================
--- kopete/protocols/gadu/gadueditcontact.h	(revision 1356911)
+++ kopete/protocols/gadu/gadueditcontact.h	(revision 1356912)
@@ -23,6 +23,8 @@
 #ifndef GADUEDITCONTACT_H
 #define GADUEDITCONTACT_H
 
+#include "gaducontactlist.h"
+
 #include <kdialog.h>
 //Added by qt3to4:
 #include <QLabel>
@@ -32,7 +34,6 @@
 class QLabel;
 class QWidget;
 class GaduContact;
-class GaduContactsList::ContactLine;
 class Q3ListViewItem;
 
 class GaduEditContact : public KDialog

------------------------------------------------------------------------
