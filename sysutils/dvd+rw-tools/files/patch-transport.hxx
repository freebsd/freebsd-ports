diff -dur dvd+rw-tools-5.19.4.9.7/transport.hxx dvd+rw-tools-5.19-1.4.9.7/transport.hxx
--- transport.hxx	Sat Apr 10 09:30:11 2004
+++ transport.hxx	Mon Apr 19 12:25:06 2004
@@ -1390,7 +1390,7 @@
 		*progress = sensebuf[16]<<8|sensebuf[17];
 	    break;
 	}
-	msecs = getmsecs();
+	msecs = 1000 - (getmsecs() - msecs);
     }
 
   return 0;
