--- TailFile.cc.bak	2010-07-31 14:12:15.145254811 +0200
+++ TailFile.cc	2010-07-31 14:13:31.996950208 +0200
@@ -352,7 +352,10 @@
       int ch = fgetc(m_file);
 
       // add the character to the string
-      m_follow_buffer->put(ch);
+      if (ch == EOF)
+          clearerr(m_file);     // required by POSIX and ANSI
+      else
+          m_follow_buffer->put(ch);
       
       // check if return
       if (ch == '\n')
