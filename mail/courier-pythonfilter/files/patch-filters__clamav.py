--- filters/clamav.py.orig	Sat Dec 16 03:11:51 2006
+++ filters/clamav.py	Sun Jan  7 10:56:30 2007
@@ -31,13 +31,13 @@
     except Exception, e:
         return "554 " + str(e)
     if avresult[0]:
-        return "554 %s was detected. Abort!" % avresult[1]
+        return "554 Virus found - Signature is %s" % avresult[1]
     return ''
 
 
 if __name__ == '__main__':
     # we only work with 1 parameter
     if len(sys.argv) != 2:
-        print "Usage: attachment.py <message_body_file>"
+        print "Usage: clamav.py <message_body_file>"
         sys.exit(0)
     print doFilter(sys.argv[1], "")
