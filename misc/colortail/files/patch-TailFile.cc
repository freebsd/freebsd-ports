--- TailFile.cc.orig	Thu Aug  5 08:09:38 1999
+++ TailFile.cc	Thu Feb  5 19:49:47 2004
@@ -375,7 +375,7 @@
    // check if there isn't a follow buffer
    if (m_follow_buffer == NULL)
    {
-      m_follow_buffer = new ostrstream();
+      m_follow_buffer = new std::ostrstream();
    }
 
    // make buffer
@@ -417,6 +417,9 @@
       int ch = fgetc(m_file);
 
       // add the character to the string
+      if (ch == EOF)
+          clearerr(m_file);     // required by POSIX and ANSI
+      else
       m_follow_buffer->put(ch);
       
       // check if return
