--- embed/example4.c.orig	Mon Jul 18 04:54:09 2005
+++ embed/example4.c	Sun Aug  7 22:28:37 2005
@@ -22,10 +22,12 @@
 }
 void runexpr(void* object)
 {
+  void* result;
+
   printf("Input>  ");
   print_expr(object);
   printf("\n");
-  void* result = yacas_execute(object);
+  result = yacas_execute(object);
   printf("Output>  ");
   print_expr(result);
   printf("\n");
@@ -35,9 +37,10 @@
 int main(int argc, char** argv)
 {
   int i;
+  void *input;
   yacas_init();
-  
-  void *input = 
+
+  input = 
     yacas_create_sublist(
       yacas_link_objects(
         yacas_create_atom("+"),
