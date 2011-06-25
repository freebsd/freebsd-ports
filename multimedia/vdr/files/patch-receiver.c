--- receiver.c.orig
+++ receiver.c
@@ -36,10 +36,10 @@ cReceiver::cReceiver(const cChannel *Cha
 cReceiver::~cReceiver()
 {
   if (device) {
-     const char *msg = "ERROR: cReceiver has not been detached yet! This is a design fault and VDR will segfault now!";
+     const char *msg = "ERROR: cReceiver has not been detached yet! This is a design fault and VDR will abort now!";
      esyslog("%s", msg);
      fprintf(stderr, "%s\n", msg);
-     *(char *)0 = 0; // cause a segfault
+     abort();
      }
 }
 
