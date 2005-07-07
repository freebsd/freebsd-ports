
$FreeBSD$

--- main.c.orig
+++ main.c
@@ -249,6 +251,10 @@
    be default yes, good for trouble-shooting
 */
 int server_signature=1;
+/*
+ * Server's signature if different from default.
+ */
+char* server_name = 0;
 /* should ser try to locate outbound interface on multihomed
  * host? by default not -- too expensive
  */
