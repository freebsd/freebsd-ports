--- TailFile.cc.orig	2010-06-02 20:41:36 UTC
+++ TailFile.cc
@@ -352,8 +352,11 @@ void TailFile::follow_print(int n, int v
       int ch = fgetc(m_file);
 
       // add the character to the string
-      m_follow_buffer->put(ch);
-      
+      if (ch == EOF)
+          clearerr(m_file);     // required by POSIX and ANSI
+      else
+          m_follow_buffer->put(ch);
+    
       // check if return
       if (ch == '\n')
       {
