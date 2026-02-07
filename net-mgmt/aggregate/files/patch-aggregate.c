Index: aggregate.c
===================================================================
--- aggregate.c	(revision 919)
+++ aggregate.c	(working copy)
@@ -261,8 +261,18 @@
           moanf(0, "[line %d] line too long; ignoring line", line);
         continue;
       }
+      if (buf[i] == '/') { 
+	      masklen = atoi(buf + i + 1);
+	      if (masklen < 1 || masklen > max_prefix_length)
+	      {
+		if (!quiet)
+		  moanf(0, "[line %d] mask length %d out of range; ignoring line", \
+		    line, masklen);
+		continue;
+	      }
+      } else
+	      masklen = default_prefix_length;
       buf[i] = 0;
-      masklen = default_prefix_length;
     } else {
       i = 0;
       while (buf[i] != '/' && i < MAX_buf) i++;
