--- common/maperror.c.orig	Thu Jan 30 08:00:00 2003
+++ common/maperror.c	Thu Jan 30 08:00:15 2003
@@ -210,7 +210,6 @@
     case GNUPG_Certificate_Expired:
       rc = ASSUAN_Bad_Certificate; 
       break;
-    case GNUPG_Bad_Certificate_Chain: rc = ASSUAN_Bad_Certificate_Chain; break;
     case GNUPG_Missing_Certificate: rc = ASSUAN_Missing_Certificate; break;
     case GNUPG_No_Data:           rc = ASSUAN_No_Data_Available; break;
     case GNUPG_Bad_Signature:     rc = ASSUAN_Bad_Signature; break;
