Obtained from:	https://github.com/traviscross/mtr/commit/3649b04337d38725f58a3d8ebe7845cb7fa3cabf

--- ui/mtr.c.orig	2017-02-05 07:27:33 UTC
+++ ui/mtr.c
@@ -301,6 +301,7 @@ static void init_fld_options(
         ctl->available_options[i] = data_fields[i].key;
         ctl->fld_index[data_fields[i].key] = i;
     }
+    ctl->available_options[i++] = '_';
     ctl->available_options[i] = 0;
 }
 
