--- latte-text.h.orig	Sat Oct 16 03:24:33 1999
+++ latte-text.h	Fri Mar 19 01:17:52 2004
@@ -51,7 +51,7 @@
 
 class LatteText_TextVisitor : public Latte_Visitor {
  public:
-  LatteText_TextVisitor(ostream &out,
+  LatteText_TextVisitor(std::ostream &out,
                         unsigned int wrapcol = 72,
                         const char *sentence_end_chars = 0,
                         const char *sentence_end_transparent_chars = 0) :
@@ -63,7 +63,7 @@
   void visit_str(Latte_Str &);
 
  private:
-  ostream &m_out;
+  std::ostream &m_out;
   unsigned int m_wrapcol;
   unsigned int m_column;
   const char *m_sentence_end_chars;
@@ -73,11 +73,11 @@
 
 extern void
 latte_text(bool no_default, unsigned long log_flags,
-           const deque<latte_string>::const_iterator &loads_begin,
-           const deque<latte_string>::const_iterator &loads_end,
+           const std::deque<latte_string>::const_iterator &loads_begin,
+           const std::deque<latte_string>::const_iterator &loads_end,
            unsigned int wrapcol,
            const char *sentence_end_chars,
            const char *sentence_end_transparent_chars,
-           const char *filename, istream &in, ostream &out);
+           const char *filename, std::istream &in, std::ostream &out);
 
 #endif // LATTE_TEXT_H
