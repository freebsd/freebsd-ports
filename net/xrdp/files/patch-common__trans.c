--- ./common/trans.c-orig	2010-05-04 09:37:22.000000000 +0200
+++ ./common/trans.c		2010-06-15 09:13:05.000000000 +0200
@@ -214,6 +214,7 @@
         /* error */
         self->status = TRANS_STATUS_DOWN;
         rv = 1;
+        break;
       }
     }
     else if (rcvd == 0)
@@ -221,6 +222,7 @@
       /* error */
       self->status = TRANS_STATUS_DOWN;
       rv = 1;
+      break;
     }
     else
     {
@@ -271,6 +273,7 @@
         /* error */
         self->status = TRANS_STATUS_DOWN;
         rv = 1;
+        break;
       }
     }
     else if (sent == 0)
@@ -278,6 +281,7 @@
       /* error */
       self->status = TRANS_STATUS_DOWN;
       rv = 1;
+      break;
     }
     else
     {
