--- intl/localealias.c.orig	Tue Aug 31 19:29:35 1999
+++ intl/localealias.c	Sun Jul  6 05:35:31 2003
@@ -333,12 +333,12 @@
 		  string_space_max = new_size;
 		}
 
-	      map[nmap].alias = memcpy (&string_space[string_space_act],
-					alias, alias_len);
+	      memcpy (&string_space[string_space_act], alias, alias_len);
+	      map[nmap].alias = &string_space[string_space_act];
 	      string_space_act += alias_len;
 
-	      map[nmap].value = memcpy (&string_space[string_space_act],
-					value, value_len);
+	      memcpy (&string_space[string_space_act], value, value_len);
+	      map[nmap].value = &string_space[string_space_act];
 	      string_space_act += value_len;
 
 	      ++nmap;
