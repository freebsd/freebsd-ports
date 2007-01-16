--- filters/comeagain.py.orig	Tue Jan  2 22:02:12 2007
+++ filters/comeagain.py	Sun Jan  7 12:35:20 2007
@@ -89,11 +89,7 @@
     if foundAll:
         return ''
     else:
-        return('421-Please send the message again.\n'
-               '421-This is not an indication of a problem:  We require\n'
-               '421-that any new sender retry their delivery as proof that\n'
-               '421-they are not spamware or virusware.\n'
-               '421 Thank you.')
+        return('421 Please send the message again to proof you are not spamware or virusware.')
 
 
 if __name__ == '__main__':
@@ -103,6 +99,6 @@
     # recipient.  Run this script with the name of that file as an
     # argument, and it'll validate that email address.
     if not sys.argv[1:]:
-        print 'Use:  comeagain.py <control file>'
+        print 'Use: comeagain.py <control file>'
         sys.exit(1)
     print doFilter('', sys.argv[1:])
