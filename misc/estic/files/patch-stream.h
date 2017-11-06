--- spunk/stream.h.orig	1996-11-07 17:06:52 UTC
+++ spunk/stream.h
@@ -44,25 +44,53 @@
 #include <stdio.h>
 #include <string.h>
 
+#include "machine.h"
+
+class Stream;
+
+Stream& operator << (Stream&, char);
+Stream& operator << (Stream&, unsigned char);
+Stream& operator << (Stream&, signed char);
+Stream& operator << (Stream&, i16);
+Stream& operator << (Stream&, u16);
+Stream& operator << (Stream&, i32);
+Stream& operator << (Stream&, u32);
+Stream& operator << (Stream&, float);
+Stream& operator << (Stream&, double);
+Stream& operator << (Stream&, char*);
+
+Stream& operator >> (Stream&, char&);
+Stream& operator >> (Stream&, unsigned char&);
+Stream& operator >> (Stream&, signed char&);
+Stream& operator >> (Stream&, i16&);
+Stream& operator >> (Stream&, u16&);
+Stream& operator >> (Stream&, i32&);
+Stream& operator >> (Stream&, u32&);
+Stream& operator >> (Stream&, float&);
+Stream& operator >> (Stream&, double&);
+Stream& operator >> (Stream&, char*);
+
+
 #include "strmable.h"
 #include "coll.h"
 #include "str.h"
 
 
 
-static const stOk           =  0;   // things are allright
-static const stInitError    =  1;   // error initializing the stream
-static const stReadError    =  2;   // error reading from the stream
-static const stWriteError   =  3;   // error writing to the stream
-static const stGetError     =  4;   // get found not registered class
-static const stPutError     =  5;   // put found not registered class
-static const stMemoryError  =  6;   // not enough memory
-static const stStoreError   =  7;   // Keine Store-Methode angegeben
-static const stLoadError    =  8;   // Keine Load-Methode oder Fehler bei Load
-static const stCopyError    =  9;   // CopyFrom: error of source stream
-static const stSeekError    = 10;   // error using Seek, GetPos etc.
-static const stReadTimeout  = 11;   // Timeout on read (CharacterStream only)
-static const stWriteTimeout = 12;   // Timeout on write (CharcterStream only)
+
+static const int stOk           =  0;   // things are allright
+static const int stInitError    =  1;   // error initializing the stream
+static const int stReadError    =  2;   // error reading from the stream
+static const int stWriteError   =  3;   // error writing to the stream
+static const int stGetError     =  4;   // get found not registered class
+static const int stPutError     =  5;   // put found not registered class
+static const int stMemoryError  =  6;   // not enough memory
+static const int stStoreError   =  7;   // Keine Store-Methode angegeben
+static const int stLoadError    =  8;   // Keine Load-Methode oder Fehler bei Load
+static const int stCopyError    =  9;   // CopyFrom: error of source stream
+static const int stSeekError    = 10;   // error using Seek, GetPos etc.
+static const int stReadTimeout  = 11;   // Timeout on read (CharacterStream only)
+static const int stWriteTimeout = 12;   // Timeout on write (CharcterStream only)
 
 
 
