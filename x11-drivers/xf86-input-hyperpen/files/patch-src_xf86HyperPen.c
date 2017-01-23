# Finish converting use of Error to ErrorF
# Correct a couple strings that should be const
#
--- src/xf86HyperPen.c.orig	2011-07-05 01:34:17 UTC
+++ src/xf86HyperPen.c
@@ -66,7 +66,7 @@
  * read a full packet before returning
  */
 
-static char *default_options[] = {
+static const char *default_options[] = {
     "BaudRate",    "9600",
     "DataBits",    "8",
     "StopBits",    "1",
@@ -212,7 +212,7 @@ xf86HypReadInput(InputInfoPtr pInfo)
     SYSCALL(len = read(pInfo->fd, buffer, sizeof(buffer)));
 
     if (len <= 0) {
-        Error("error reading HyperPen device");
+        ErrorF("error reading HyperPen device\n");
         return;
     }
 
@@ -372,14 +372,14 @@ xf86HypWriteAndRead(int fd, char *data, 
 
     SYSCALL(err = write(fd, data, strlen(data)));
     if (err == -1) {
-        Error("HyperPen write");
+        ErrorF("HyperPen write\n");
         return NULL;
     }
 
     while (numread < len) {
         err = xf86WaitForInput(fd, 100000);
         if (err == -1) {
-            Error("HyperPen select");
+            ErrorF("HyperPen select\n");
             return NULL;
         }
         if (!err) {
@@ -389,7 +389,7 @@ xf86HypWriteAndRead(int fd, char *data, 
 
         SYSCALL(err = read(fd, buffer + numread++, 1));
         if (err == -1) {
-            Error("HyperPen read");
+            ErrorF("HyperPen read\n");
             return NULL;
         }
         if (!err) {
@@ -431,7 +431,7 @@ xf86HypOpen(InputInfoPtr pInfo)
 
     pInfo->fd = xf86OpenSerial(pInfo->options);
     if (pInfo->fd == -1) {
-        Error(priv->hypDevice);
+        ErrorF("failed to open %s\n", priv->hypDevice);
         return !Success;
     }
     DBG(2, ErrorF("%s opened as fd %d\n", priv->hypDevice, pInfo->fd));
@@ -449,7 +449,7 @@ xf86HypOpen(InputInfoPtr pInfo)
     /* Put it in prompt mode so it doesn't say anything before we're ready */
     SYSCALL(err = write(pInfo->fd, SS_PROMPT_MODE, strlen(SS_PROMPT_MODE)));
     if (err == -1) {
-        Error("HyperPen write");
+        ErrorF("HyperPen write\n");
         return !Success;
     }
     /* Clear any pending input */
@@ -578,7 +578,7 @@ xf86HypOpen(InputInfoPtr pInfo)
     SYSCALL(err = write(pInfo->fd, buffer, idx));
 
     if (err == -1) {
-        Error("HyperPen write");
+        ErrorF("HyperPen write\n");
         return !Success;
     }
 
@@ -819,7 +819,7 @@ xf86HypInit(InputDriverPtr      drv,
             int                 flags)
 {
     HyperPenDevicePtr priv = malloc(sizeof(HyperPenDeviceRec));
-    char *s;
+    const char *s;
     int rc = Success;
 
     if (!priv) {
