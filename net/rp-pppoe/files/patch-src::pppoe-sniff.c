--- src/pppoe-sniff.c.orig	Thu Mar 22 14:35:59 2001
+++ src/pppoe-sniff.c	Thu Mar 22 14:49:39 2001
@@ -33,6 +33,9 @@
 void dlokack(int fd, char *bufp);
 #endif
 
+/* function prototype */
+void sysErr(char const *);
+
 /* Default interface if no -I option given */
 #define DEFAULT_IF "eth0"
 
@@ -43,6 +46,23 @@
 
 char *IfName = NULL;		/* Interface name */
 char *ServiceName = NULL;	/* Service name   */
+
+/**********************************************************************
+*%FUNCTION: sysErr
+*%ARGUMENTS:
+* str -- error message
+*%RETURNS:
+* Nothing
+*%DESCRIPTION:
+* Prints a message plus the errno value to syslog.
+***********************************************************************/
+void
+sysErr(char const *str)
+{
+    char buf[1024];
+    sprintf(buf, "%.256s: %.256s", str, strerror(errno));
+    printErr(buf);
+}
 
 /**********************************************************************
 *%FUNCTION: parsePADRTags
