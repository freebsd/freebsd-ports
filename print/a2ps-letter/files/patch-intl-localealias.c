--- intl/localealias.c.orig	Tue Aug 31 13:29:35 1999
+++ intl/localealias.c	Tue Aug 12 11:09:53 2003
@@ -329,6 +329,17 @@
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
