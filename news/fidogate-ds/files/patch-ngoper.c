--- src/toss/ngoper.c.old	Wed Jul 14 16:13:34 2004
+++ src/toss/ngoper.c	Sat Jul 10 17:34:20 2004
@@ -20,7 +20,7 @@
   int   c;
   int   option_index;
   int   remove;
-  char *cmd_ng, *cmd_rn, *cmd_rm;
+  char *cmd_ng, *cmd_rn = NULL, *cmd_rm;
   char *c_flag=NULL;
   char *p;
   char  buf[BUFSIZ];
@@ -106,12 +106,6 @@
       debug(8, "config: AutoCreateRenumberCmd %s", p);
       cmd_rn = p;
     }
-  else
-    {
-      printf("config: parameter `AutoCreateRenumberCmd' not defined!\n");
-      exit_free();
-      exit(1);
-    }
 
   /* AutoCreateRmgroupCmd */
   if (NULL != (p = cf_get_string("AutoCreateRmgroupCmd", TRUE)))
@@ -136,9 +130,12 @@
       if (0 != run_system(buf))
 	return 1;
 
-      str_printf(buf, sizeof(buf), cmd_rn, argv[optind+1]);
-      if (0 != run_system(buf))
-	return 1;
+      if (cmd_rn)
+      {
+        str_printf(buf, sizeof(buf), cmd_rn, argv[optind+1]);
+        if (0 != run_system(buf))
+	    return 1;
+      }
     }
   else
     {
