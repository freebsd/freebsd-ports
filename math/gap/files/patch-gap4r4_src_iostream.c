--- gap4r4/src/iostream.c.orig	Thu Feb 19 08:28:32 2004
+++ gap4r4/src/iostream.c	Tue Jun 14 18:41:51 2005
@@ -340,9 +340,9 @@ static UInt GetMasterPty ( int * pty, Ch
         return 0;
 
 #   else
-        static int  devindex = 0;
-        static int  letter   = 0;
-        static int  slave    = 0;
+        int  devindex = 0;
+        int  letter   = 0;
+        int  slave    = 0;
 
         while ( SYS_PTYCHAR1[letter] )
         {
@@ -355,12 +355,16 @@ static UInt GetMasterPty ( int * pty, Ch
                 namepty[strlen(namepty)-1] = SYS_PTYCHAR2[devindex];
                         
                 if ( (*pty = open( namepty, O_RDWR )) >= 0 )
+		{
                     if ( (slave = open( nametty, O_RDWR, 0 )) >= 0 )
                     {
                         close(slave);
                         (void) devindex++;
                         return 0;
                     }
+		    else
+			close(*pty);
+		}
                 devindex++;
             }
             devindex = 0;
