--- cinclude/perl-constants.c.orig	2004-12-09 18:24:15.265625000 +0300
+++ cinclude/perl-constants.c	2004-12-09 19:02:31.562500000 +0300
@@ -240,6 +240,15 @@
             return GMIME_MDN_MODIFIER_MAILBOX_TERMINATED;
 #endif
           break;
+        case 'R':
+	  /* gmime-message.h */
+          if (strEQ(name, "GMIME_RECIPIENT_TYPE_TO"))
+            return GMIME_RECIPIENT_TYPE_TO;
+          else if (strEQ(name, "GMIME_RECIPIENT_TYPE_CC"))
+            return GMIME_RECIPIENT_TYPE_CC;
+          else if (strEQ(name, "GMIME_RECIPIENT_TYPE_CC"))
+            return GMIME_RECIPIENT_TYPE_BCC;
+          break;
         }
       }
       break;
