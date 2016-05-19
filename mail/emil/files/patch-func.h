--- func.h.orig	1996-06-04 13:37:04 UTC
+++ func.h
@@ -166,7 +166,7 @@ int     check_encoding(struct message *)
 int     boundary_check(struct message *);
 int     is_bound(struct data *, char *);
 struct message * copy_mstruct(struct message *, int);
-int     getline(struct data *);
+int     get_line(struct data *);
 int     set_end_by_boundary(struct message *, char *);
 int     set_end_by_lines(struct message *, int);
 
