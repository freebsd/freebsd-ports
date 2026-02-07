--- include/LDL.h.orig	Fri Dec 13 11:54:46 2002
+++ include/LDL.h	Fri Dec 13 11:55:01 2002
@@ -20,8 +20,6 @@
 # endif
 # include <string.h>
 
-#if !defined(HAVE_INSQUE) && !defined(HAVE_REMQUE)
-/* the insque, remque are not defined, we need to define the type for them */
 typedef struct qelem
 {
    struct qelem* q_forw,* q_back;
@@ -49,8 +47,6 @@
    if (elem->q_forw) elem->q_forw->q_back = elem->q_back;
    if (elem->q_back) elem->q_back->q_forw = elem->q_forw;
 }
-#endif
-
 #endif
 
 
