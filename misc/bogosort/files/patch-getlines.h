--- getlines.h.orig	2016-05-11 20:30:38 UTC
+++ getlines.h
@@ -39,6 +39,6 @@ char **getmorelines(FILE *stream, char *
  * getline: return a pointer to a newly allocated string containing the next
  * line in stream
  */
-char *getline(FILE *stream);
+char *get_line(FILE *stream);
 
 #endif /* GETLINES_H */
