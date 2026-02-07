--- print.hh.orig	1993-08-02 05:28:22.000000000 +0900
+++ print.hh	2014-01-22 09:51:43.000000000 +0900
@@ -43,13 +43,13 @@
   FILE *ofp ;                   // Output file pointer (stdout or print cmd).
 
        Print         () ;
-  void end           (enum action_type) ;
+  void end           (action_type) ;
   FILE *makecmd      (char *) ;
   void print_extra   (void) ;
   void show_prologue (char *) ;
-  void show_text     (enum text_type, char *, char *) ;
+  void show_text     (text_type, char *, char *) ;
   void show_trailer  (void) ;
-  void start         (enum action_type) ;
+  void start         (action_type) ;
 
   private:
   void do_date       (void) ;
