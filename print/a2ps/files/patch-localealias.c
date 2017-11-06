--- intl/localealias.c.orig	1999-08-31 17:29:35 UTC
+++ intl/localealias.c
@@ -329,6 +329,17 @@ read_alias_file (fname, fname_len)
 		      FREE_BLOCKS (block_list);
 		      return added;
 		    }
+		  if (string_space != new_pool)
+		    {
+		      size_t i;
+
+		      for (i = 0; i < nmap; i++)
+			{
+			  map[i].alias += new_pool - string_space;
+			  map[i].value += new_pool - string_space;
+			}
+		    }
+
 		  string_space = new_pool;
 		  string_space_max = new_size;
 		}
