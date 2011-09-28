--- bclock.c.orig	2011-09-28 14:32:42.000000000 +0800
+++ bclock.c	2011-09-28 14:33:26.000000000 +0800
@@ -88,7 +88,7 @@ static XrmOptionDescRec options[] = {
 {"-transparent","*clock.transparent",	XrmoptionNoArg,		"TRUE"},
 };
 
-void main(argc, argv)
+int main(argc, argv)
     int argc;
     char **argv;
 {
